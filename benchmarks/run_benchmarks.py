import os
import csv
from argparse import ArgumentParser
from distutils.dir_util import copy_tree
import Spiral_DFT.run_igen      as DFT_IGen
import Spiral_DFT.build_and_run as DFT_Bench
import FFNN_mnist.run_igen      as FFNN_IGen
import FFNN_mnist.build_and_run as FFNN_Bench
import LGen_potrf.run_igen      as Potrf_IGen
import LGen_potrf.build_and_run as Potrf_Bench
import ATLAS_gemm.run_igen      as GEMM_IGen_vev
import ATLAS_gemm.build_and_run as GEMM_Bench_vec
import ATLAS_gemm_scalar.run_igen      as GEMM_IGen_scl
import ATLAS_gemm_scalar.build_and_run as GEMM_Bench_scl
import Reduction_mvm.run_igen          as Redu_IGen
import Reduction_mvm.build_and_run     as Redu_Bench

output_dir_name = "results"

gemm_interval_perf_results = [
    "interval_perf_f64i_vv.csv",
    "interval_perf_f64i_sv.csv",
    "interval_perf_ddi_vv.csv",
    "interval_perf_ddi_sv.csv",
    "interval_perf_bst.csv",
    "interval_perf_gal.csv",
    "interval_perf_fil.csv",
    "interval_perf_f64i_ss.csv"
]

gemm_real_perf_results = [
    "real_perf_baseline_vec.csv",
    "real_perf_baseline_scl.csv",
    "real_perf_f64i_vv.csv",
    "real_perf_ddi_vv.csv",
    "real_perf_f64i_sv.csv",
    "real_perf_ddi_sv.csv",
    "real_perf_f64i_ss.csv",
]

def copy_dir(rel_path_orig, rel_path_dest):
    dirname      = os.path.dirname(__file__)
    results_orig = os.path.join(dirname, rel_path_orig)
    results_dest = os.path.join(dirname, rel_path_dest)
    os.makedirs(results_dest, exist_ok=True)
    copy_tree(results_orig, results_dest)

def run_benchmark_dft():
    print("DFT benchmark")
    DFT_IGen.generate_igen_files()
    DFT_Bench.build_and_run()
    copy_dir("Spiral_DFT/results", output_dir_name + "/dft")

def run_benchmark_gemm():
    print("GEMM benchmark")
    # GEMM_IGen_vev.generate_igen_files()
    # GEMM_IGen_scl.generate_igen_files()
    # GEMM_Bench_vec.build_and_run()
    # GEMM_Bench_scl.build_and_run()
    copy_dir("ATLAS_gemm/results", output_dir_name + "/gemm")
    copy_dir("ATLAS_gemm_scalar/results", output_dir_name + "/gemm")

    # The csv files are scattered for gemm. Merge them into the right format
    fout = open(output_dir_name + "/gemm/interval_perf.csv","w")
    for f in gemm_interval_perf_results:
        file_name = output_dir_name + "/gemm/" + f
        for line in open(file_name):
            fout.write(line)
    fout.close()

    data_read = []
    for f in gemm_real_perf_results:
        file_name = output_dir_name + "/gemm/" + f
        with open(file_name) as fp:
            reader = csv.reader(fp, delimiter=",", quotechar='"')
            data_read += [row for row in reader]

    r_perf_base_vec = float(data_read[0][5])
    r_perf_base_scl = float(data_read[1][5])
    r_perf_f64i_vv  = float(data_read[2][5])
    r_perf_ddi_vv   = float(data_read[3][5])

    data_read = []
    for f in gemm_interval_perf_results:
        file_name = output_dir_name + "/gemm/" + f
        with open(file_name) as fp:
            reader = csv.reader(fp, delimiter=",", quotechar='"')
            data_read += [row for row in reader]

    i_perf_f64i_vv  = float(data_read[0][5])
    i_perf_f64i_sv  = float(data_read[1][5])
    i_perf_ddi_sv   = float(data_read[2][5])
    i_perf_ddi_vv   = float(data_read[3][5])

    r_perf_gemm616   = [r_perf_base_vec, r_perf_f64i_vv, r_perf_ddi_vv]

    overhead_gemm616 = [r_perf_base_scl / i_perf_f64i_sv, r_perf_base_vec / i_perf_f64i_vv,
                        r_perf_base_scl / i_perf_ddi_sv ,  r_perf_base_vec / i_perf_ddi_vv]

    fout = open(output_dir_name + "/gemm/real_perf_gemm616.csv","w")
    for perf in r_perf_gemm616:
        fout.write(str(perf))
        fout.write(",")
    fout.close()

    fout = open(output_dir_name + "/gemm/overhead_gemm616.csv","w")
    for perf in overhead_gemm616:
        fout.write(str(perf))
        fout.write(",")
    fout.close()

    # Remove all intermediate files files
    for f in gemm_interval_perf_results:
        file_name = output_dir_name + "/gemm/" + f
        os.remove(file_name)

    for f in gemm_real_perf_results:
        file_name = output_dir_name + "/gemm/" + f
        os.remove(file_name)

def run_benchmark_potrf():
    print("Potrf benchmark")
    Potrf_IGen.generate_igen_files()
    Potrf_Bench.build_and_run()
    copy_dir("LGen_potrf/results", output_dir_name + "/potrf")

def run_benchmark_ffnn():
    print("FFNN benchmark")
    FFNN_IGen.generate_igen_files()
    FFNN_Bench.build_and_run()
    copy_dir("FFNN_mnist/results", output_dir_name + "/ffnn")

def run_benchmark_redu():
    print("Reduction improvement in mvm benchmark")
    Redu_IGen.generate_igen_files()
    Redu_Bench.build_and_run()
    copy_dir("Reduction_mvm/results", output_dir_name + "/redu_mvm")

def plot_results():
    print("Plot results")
    dirname    = os.path.dirname(__file__)
    results_dir = os.path.join(dirname, output_dir_name)
    working_dir = os.getcwd()
    os.chdir(results_dir)

    # Plot results
    os.system("Rscript plot_benchmarks.R")
    os.chdir(working_dir)

def parse_arguments():
    parser = ArgumentParser()
    parser.add_argument('-all'  , dest='all'  , action='store_true', default=False, help='Run all benchmarks'  )
    parser.add_argument('-dft'  , dest='dft'  , action='store_true', default=False, help='Run DFT benchmark'   )
    parser.add_argument('-gemm' , dest='gemm' , action='store_true', default=False, help='Run GEMM benchmarks' )
    parser.add_argument('-potrf', dest='potrf', action='store_true', default=False, help='Run Potrf benchmarks')
    parser.add_argument('-ffnn' , dest='ffnn' , action='store_true', default=False, help='Run FFNN benchmarks')
    parser.add_argument('-redu' , dest='redu' , action='store_true', default=False, help='Run Reduction improvement in mvm benchmark (Figure 10 in paper)')
    parser.add_argument('-plot' , dest='plot' , action='store_true', default=False, help='Plot results for interval performance')
    args = parser.parse_args()

    # Set all argument to true by default or if "all" detected
    if args.all or (not args.dft and not args.gemm and not args.potrf and not args.ffnn and not args.redu and not args.plot):
        args.dft   = True
        args.gemm  = True
        args.potrf = True
        args.ffnn  = True
        args.redu  = True

    return args

if __name__ == "__main__":
    args = parse_arguments()
    if args.dft:
        run_benchmark_dft()
    if args.gemm:
        run_benchmark_gemm()
    if args.potrf:
        run_benchmark_potrf()
    if args.ffnn:
        run_benchmark_ffnn()
    if args.redu:
        run_benchmark_redu()
    if args.plot:
        plot_results()