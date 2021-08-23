import os

igen_script = '/home/joao/Documents/repo/icompes/bin/igen.py'
args = [
    {'inp':'ffnn_source/ffnn.cpp'    ,  'out':'igen/igen_ffnn_f64i.cpp'    , 'mode':'normal'    },
    {'inp':'ffnn_source/ffnn.cpp'    ,  'out':'igen/igen_ffnn_ddi.cpp'     , 'mode':'promote_dd'},
    {'inp':'ffnn_source/ffnn_vec.cpp',  'out':'igen/igen_ffnn_avx_f64i.cpp', 'mode':'normal'    },
    {'inp':'ffnn_source/ffnn_vec.cpp',  'out':'igen/igen_ffnn_avx_ddi.cpp' , 'mode':'promote_dd'},
]

def generate_igen_files():
    print("Generating IGen files for FFNN benchmark:")
    dirname  = os.path.dirname(__file__)
    igen_dir = os.path.join(dirname, "igen")
    os.makedirs(igen_dir, exist_ok=True)
    for a in args:
        inp_file = os.path.join(dirname, a['inp'])
        out_file = os.path.join(dirname, a['out'])
        cmd = 'python ' + igen_script + " -H " + "-o " + out_file + " -tmode " + a['mode'] + " " + inp_file
        print(cmd)
        os.system(cmd)
        print("\n")


if __name__ == "__main__":
    generate_files()