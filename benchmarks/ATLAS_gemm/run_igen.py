import os

igen_script = '/home/joao/Documents/repo/icompes/bin/igen.py'
args = [
    # IGen-vv
    {'inp':'atlas_source/ATL_col2blk.c'  ,     'out':'atlas_f64i/igen_ATL_col2blk.c'  ,    'mode':'normal'},
    {'inp':'atlas_source/ATL_dNBmm_b0.c' ,     'out':'atlas_f64i/igen_ATL_dNBmm_b0.c' ,    'mode':'normal'},
    {'inp':'atlas_source/ATL_dNBmm_b1.c' ,     'out':'atlas_f64i/igen_ATL_dNBmm_b1.c' ,    'mode':'normal'},
    {'inp':'atlas_source/ATL_gemm.c'     ,     'out':'atlas_f64i/igen_ATL_gemm.c'     ,    'mode':'normal'},
    {'inp':'atlas_source/ATL_gemmXX.c'   ,     'out':'atlas_f64i/igen_ATL_gemmXX.c'   ,    'mode':'normal'},
    {'inp':'atlas_source/ATL_mmJIK.c'    ,     'out':'atlas_f64i/igen_ATL_mmJIK.c'    ,    'mode':'normal'},
    {'inp':'atlas_source/ATL_putblk.c'   ,     'out':'atlas_f64i/igen_ATL_putblk.c'   ,    'mode':'normal'},
    {'inp':'atlas_source/ATL_row2blkT.c' ,     'out':'atlas_f64i/igen_ATL_row2blkT.c' ,    'mode':'normal'},
    {'inp':'atlas_source/cblas_dgemm.c'  ,     'out':'atlas_f64i/igen_cblas_dgemm.c'  ,    'mode':'normal'},
    
    # IGen-vv-dd
    {'inp':'atlas_source/ATL_col2blk.c'  ,     'out':'atlas_ddi/igen_ATL_col2blk.c'  ,    'mode':'promote_dd'},
    {'inp':'atlas_source/ATL_dNBmm_b0.c' ,     'out':'atlas_ddi/igen_ATL_dNBmm_b0.c' ,    'mode':'promote_dd'},
    {'inp':'atlas_source/ATL_dNBmm_b1.c' ,     'out':'atlas_ddi/igen_ATL_dNBmm_b1.c' ,    'mode':'promote_dd'},
    {'inp':'atlas_source/ATL_gemm.c'     ,     'out':'atlas_ddi/igen_ATL_gemm.c'     ,    'mode':'promote_dd'},
    {'inp':'atlas_source/ATL_gemmXX.c'   ,     'out':'atlas_ddi/igen_ATL_gemmXX.c'   ,    'mode':'promote_dd'},
    {'inp':'atlas_source/ATL_mmJIK.c'    ,     'out':'atlas_ddi/igen_ATL_mmJIK.c'    ,    'mode':'promote_dd'},
    {'inp':'atlas_source/ATL_putblk.c'   ,     'out':'atlas_ddi/igen_ATL_putblk.c'   ,    'mode':'promote_dd'},
    {'inp':'atlas_source/ATL_row2blkT.c' ,     'out':'atlas_ddi/igen_ATL_row2blkT.c' ,    'mode':'promote_dd'},
    {'inp':'atlas_source/cblas_dgemm.c'  ,     'out':'atlas_ddi/igen_cblas_dgemm.c'  ,    'mode':'promote_dd'},
]

defs = \
"-D L2SIZE=33554432 \
-D Add_             \
-D F77_INTEGER=int  \
-D StringSunStyle   \
-D ATL_OS_Linux     \
-D ATL_ARCH_Corei4  \
-D ATL_CPUMHZ=2289  \
-D ATL_AVXMAC       \
-D ATL_AVX          \
-D ATL_SSE3         \
-D ATL_SSE2         \
-D ATL_SSE1         \
-D ATL_USE64BITS    \
-D ATL_GAS_x8664    \
-D ATL_NCPU=12      \
-D DREAL            \
-D NoTransA_        \
-D NoTransB_        \
-D ALPHAX           \
-D BETAX            \
-D ATL_UCLEANM      \
-D ATL_UCLEANN      \
-D ATL_UCLEANK"

incl = \
"-I /home/joao/Documents/libraries/linear_algebra/atlas3.10.3/ATLAS/include \
-I /home/joao/Documents/libraries/linear_algebra/atlas3.10.3/install_debug/include/atlas"


def generate_igen_files():
    print("Generating IGen files for Potrf benchmark:")
    dirname  = os.path.dirname(__file__)


    igen_f64i_dir = os.path.join(dirname, "atlas_f64i")
    igen_ddi_dir  = os.path.join(dirname, "atlas_ddi")
    os.makedirs(igen_f64i_dir, exist_ok=True)
    os.makedirs(igen_ddi_dir, exist_ok=True)

    for a in args:
        inp_file = os.path.join(dirname, a['inp'])
        out_file = os.path.join(dirname, a['out'])
        cmd = 'python ' + igen_script + " " + defs + " " + incl + " -o " + out_file + " -tmode " + a['mode'] + " " + inp_file
        print(cmd)
        os.system(cmd)
        print("\n")

if __name__ == "__main__":
    generate_igen_files()