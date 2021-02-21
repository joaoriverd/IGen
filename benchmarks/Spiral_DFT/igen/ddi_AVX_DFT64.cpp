#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"
#include <stddef.h>
#include <stdlib.h>

void init_AVX_DFT64(dd_I a) {}

void AVX_DFT64(dd_I *Y, dd_I *X) {
  ddi_4 a1477;
  ddi_4 a1478;
  ddi_4 a1479;
  ddi_4 a1480;
  ddi_4 a1481;
  ddi_4 a1482;
  ddi_4 a1484;
  ddi_4 a1485;
  ddi_4 s6022;
  ddi_4 s6023;
  ddi_4 s6024;
  ddi_4 s6025;
  ddi_4 s6026;
  ddi_4 s6027;
  ddi_4 s6028;
  ddi_4 s6029;
  ddi_4 s6030;
  ddi_4 s6031;
  ddi_4 s6032;
  ddi_4 s6033;
  ddi_4 s6034;
  ddi_4 s6035;
  ddi_4 s6036;
  ddi_4 s6037;
  ddi_4 s6038;
  ddi_4 s6039;
  ddi_4 s6040;
  ddi_4 s6041;
  ddi_4 s6042;
  ddi_4 s6043;
  ddi_4 s6044;
  ddi_4 s6045;
  ddi_4 s6046;
  ddi_4 s6047;
  ddi_4 s6048;
  ddi_4 s6049;
  ddi_4 s6050;
  ddi_4 s6051;
  ddi_4 s6052;
  ddi_4 s6053;
  ddi_4 s6054;
  ddi_4 s6055;
  ddi_4 s6056;
  ddi_4 s6057;
  ddi_4 s6058;
  ddi_4 s6059;
  ddi_4 s6060;
  ddi_4 s6061;
  ddi_4 s6062;
  ddi_4 s6063;
  ddi_4 s6064;
  ddi_4 s6065;
  ddi_4 s6066;
  ddi_4 s6067;
  ddi_4 s6068;
  ddi_4 s6069;
  ddi_4 s6070;
  ddi_4 s6071;
  ddi_4 s6072;
  ddi_4 s6073;
  ddi_4 s6074;
  ddi_4 s6075;
  ddi_4 s6076;
  ddi_4 s6077;
  ddi_4 s6078;
  ddi_4 s6079;
  ddi_4 s6080;
  ddi_4 s6081;
  ddi_4 s6082;
  ddi_4 s6083;
  ddi_4 s6084;
  ddi_4 s6085;
  ddi_4 s6086;
  ddi_4 s6087;
  ddi_4 s6088;
  ddi_4 s6089;
  ddi_4 s6090;
  ddi_4 s6091;
  ddi_4 s6092;
  ddi_4 s6093;
  ddi_4 s6094;
  ddi_4 s6095;
  ddi_4 s6096;
  ddi_4 s6097;
  ddi_4 s6098;
  ddi_4 s6099;
  ddi_4 s6100;
  ddi_4 s6101;
  ddi_4 s6102;
  ddi_4 s6103;
  ddi_4 s6104;
  ddi_4 s6105;
  ddi_4 s6106;
  ddi_4 s6107;
  ddi_4 s6108;
  ddi_4 s6109;
  ddi_4 s6110;
  ddi_4 s6111;
  ddi_4 s6112;
  ddi_4 s6113;
  ddi_4 s6114;
  ddi_4 s6115;
  ddi_4 s6116;
  ddi_4 s6117;
  ddi_4 s6118;
  ddi_4 s6119;
  ddi_4 s6120;
  ddi_4 s6121;
  ddi_4 s6122;
  ddi_4 s6123;
  ddi_4 s6124;
  ddi_4 s6125;
  ddi_4 s6126;
  ddi_4 s6127;
  ddi_4 s6128;
  ddi_4 s6129;
  ddi_4 s6130;
  ddi_4 s6131;
  ddi_4 s6132;
  ddi_4 s6133;
  ddi_4 s6134;
  ddi_4 s6135;
  ddi_4 s6136;
  ddi_4 s6137;
  ddi_4 s6138;
  ddi_4 s6139;
  ddi_4 s6140;
  ddi_4 s6141;
  ddi_4 s6142;
  ddi_4 s6143;
  ddi_4 s6144;
  ddi_4 s6145;
  ddi_4 s6146;
  ddi_4 s6147;
  ddi_4 s6148;
  ddi_4 s6149;
  ddi_4 s6150;
  ddi_4 s6151;
  ddi_4 s6152;
  ddi_4 s6153;
  ddi_4 s6154;
  ddi_4 s6155;
  ddi_4 s6156;
  ddi_4 s6157;
  ddi_4 s6158;
  ddi_4 s6159;
  ddi_4 s6160;
  ddi_4 s6161;
  ddi_4 s6162;
  ddi_4 s6163;
  ddi_4 s6164;
  ddi_4 s6165;
  ddi_4 s6166;
  ddi_4 s6167;
  ddi_4 s6168;
  ddi_4 s6169;
  ddi_4 s6170;
  ddi_4 s6171;
  ddi_4 s6172;
  ddi_4 s6173;
  ddi_4 s6174;
  ddi_4 s6175;
  ddi_4 s6176;
  ddi_4 s6177;
  ddi_4 s6178;
  ddi_4 s6179;
  ddi_4 s6180;
  ddi_4 s6181;
  ddi_4 s6182;
  ddi_4 s6183;
  ddi_4 s6184;
  ddi_4 s6185;
  ddi_4 s6186;
  ddi_4 s6187;
  ddi_4 s6188;
  ddi_4 s6189;
  ddi_4 s6190;
  ddi_4 s6191;
  ddi_4 s6192;
  ddi_4 s6193;
  ddi_4 s6194;
  ddi_4 s6195;
  ddi_4 s6196;
  ddi_4 s6197;
  ddi_4 s6198;
  ddi_4 s6199;
  ddi_4 s6200;
  ddi_4 s6201;
  ddi_4 s6202;
  ddi_4 s6203;
  ddi_4 s6204;
  ddi_4 s6205;
  ddi_4 s6206;
  ddi_4 s6207;
  ddi_4 s6208;
  ddi_4 s6209;
  ddi_4 s6210;
  ddi_4 s6211;
  ddi_4 s6212;
  ddi_4 s6213;
  ddi_4 s6214;
  ddi_4 s6215;
  ddi_4 s6216;
  ddi_4 s6217;
  ddi_4 s6218;
  ddi_4 s6219;
  ddi_4 s6220;
  ddi_4 s6221;
  ddi_4 s6222;
  ddi_4 s6223;
  ddi_4 s6224;
  ddi_4 s6225;
  ddi_4 s6226;
  ddi_4 s6227;
  ddi_4 s6228;
  ddi_4 s6229;
  ddi_4 s6230;
  ddi_4 s6231;
  ddi_4 s6232;
  ddi_4 s6233;
  ddi_4 s6234;
  ddi_4 s6235;
  ddi_4 s6236;
  ddi_4 s6237;
  ddi_4 s6238;
  ddi_4 s6239;
  ddi_4 s6240;
  ddi_4 s6241;
  ddi_4 s6242;
  ddi_4 s6243;
  ddi_4 s6244;
  ddi_4 s6245;
  ddi_4 s6246;
  ddi_4 s6247;
  ddi_4 s6248;
  ddi_4 s6249;
  ddi_4 s6250;
  ddi_4 s6251;
  ddi_4 s6252;
  ddi_4 s6253;
  ddi_4 s6254;
  ddi_4 s6255;
  ddi_4 s6256;
  ddi_4 s6257;
  ddi_4 s6258;
  ddi_4 s6259;
  ddi_4 s6260;
  ddi_4 s6261;
  ddi_4 s6262;
  ddi_4 s6263;
  ddi_4 s6264;
  ddi_4 s6265;
  ddi_4 s6266;
  ddi_4 s6267;
  ddi_4 s6268;
  ddi_4 s6269;
  ddi_4 s6270;
  ddi_4 s6271;
  ddi_4 s6272;
  ddi_4 s6273;
  ddi_4 s6274;
  ddi_4 s6275;
  ddi_4 s6276;
  ddi_4 s6277;
  ddi_4 s6278;
  ddi_4 s6279;
  ddi_4 s6280;
  ddi_4 s6281;
  ddi_4 s6282;
  ddi_4 s6283;
  ddi_4 s6284;
  ddi_4 s6285;
  ddi_4 s6286;
  ddi_4 s6287;
  ddi_4 s6288;
  ddi_4 s6289;
  ddi_4 s6290;
  ddi_4 s6291;
  ddi_4 s6292;
  ddi_4 s6293;
  ddi_4 s6294;
  ddi_4 s6295;
  ddi_4 s6296;
  ddi_4 s6297;
  ddi_4 s6298;
  ddi_4 s6299;
  ddi_4 s6300;
  ddi_4 s6301;
  ddi_4 s6302;
  ddi_4 s6303;
  ddi_4 s6304;
  ddi_4 s6305;
  ddi_4 s6306;
  ddi_4 s6307;
  ddi_4 s6308;
  ddi_4 s6309;
  ddi_4 s6310;
  ddi_4 s6311;
  ddi_4 s6312;
  ddi_4 s6313;
  ddi_4 s6314;
  ddi_4 s6315;
  ddi_4 s6316;
  ddi_4 s6317;
  ddi_4 s6318;
  ddi_4 s6319;
  ddi_4 s6320;
  ddi_4 s6321;
  ddi_4 t4698;
  ddi_4 t4699;
  ddi_4 t4700;
  ddi_4 t4701;
  ddi_4 t4702;
  ddi_4 t4703;
  ddi_4 t4704;
  ddi_4 t4705;
  ddi_4 t4706;
  ddi_4 t4707;
  ddi_4 t4708;
  ddi_4 t4709;
  ddi_4 t4710;
  ddi_4 t4711;
  ddi_4 t4712;
  ddi_4 t4713;
  ddi_4 t4714;
  ddi_4 t4715;
  ddi_4 t4716;
  ddi_4 t4717;
  ddi_4 t4718;
  ddi_4 t4719;
  ddi_4 t4720;
  ddi_4 t4721;
  ddi_4 t4722;
  ddi_4 t4723;
  ddi_4 t4724;
  ddi_4 t4725;
  ddi_4 t4726;
  ddi_4 t4727;
  ddi_4 t4728;
  ddi_4 t4729;
  ddi_4 t4730;
  ddi_4 t4731;
  ddi_4 t4732;
  ddi_4 t4733;
  ddi_4 t4734;
  ddi_4 t4735;
  ddi_4 t4736;
  ddi_4 t4737;
  ddi_4 t4738;
  ddi_4 t4739;
  ddi_4 t4740;
  ddi_4 t4741;
  ddi_4 t4742;
  ddi_4 t4743;
  ddi_4 t4744;
  ddi_4 t4745;
  ddi_4 t4746;
  ddi_4 t4747;
  ddi_4 t4748;
  ddi_4 t4749;
  ddi_4 t4750;
  ddi_4 t4751;
  ddi_4 t4752;
  ddi_4 t4753;
  ddi_4 t4754;
  ddi_4 t4755;
  ddi_4 t4756;
  ddi_4 t4757;
  ddi_4 t4758;
  ddi_4 t4759;
  ddi_4 t4760;
  ddi_4 t4761;
  ddi_4 t4762;
  ddi_4 t4763;
  ddi_4 t4764;
  ddi_4 t4765;
  ddi_4 t4766;
  ddi_4 t4767;
  ddi_4 t4768;
  ddi_4 t4769;
  ddi_4 t4770;
  ddi_4 t4771;
  ddi_4 t4772;
  ddi_4 t4773;
  ddi_4 t4774;
  ddi_4 t4775;
  ddi_4 t4776;
  ddi_4 t4777;
  ddi_4 t4778;
  ddi_4 t4779;
  ddi_4 t4780;
  ddi_4 t4781;
  ddi_4 t4782;
  ddi_4 t4783;
  ddi_4 t4784;
  ddi_4 t4785;
  ddi_4 t4786;
  ddi_4 t4787;
  ddi_4 t4788;
  ddi_4 t4789;
  ddi_4 t4790;
  ddi_4 t4791;
  ddi_4 t4792;
  ddi_4 t4793;
  ddi_4 t4794;
  ddi_4 t4795;
  ddi_4 t4796;
  ddi_4 t4797;
  ddi_4 t4798;
  ddi_4 t4799;
  ddi_4 t4800;
  ddi_4 t4801;
  ddi_4 t4802;
  ddi_4 t4803;
  ddi_4 t4804;
  ddi_4 t4805;
  ddi_4 t4806;
  ddi_4 t4807;
  ddi_4 t4808;
  ddi_4 t4809;
  ddi_4 t4810;
  ddi_4 t4811;
  ddi_4 t4812;
  ddi_4 t4813;
  ddi_4 t4814;
  ddi_4 t4815;
  ddi_4 t4816;
  ddi_4 t4817;
  ddi_4 t4818;
  ddi_4 t4819;
  ddi_4 t4820;
  ddi_4 t4821;
  ddi_4 t4822;
  ddi_4 t4823;
  ddi_4 t4824;
  ddi_4 t4825;
  ddi_4 t4826;
  ddi_4 t4827;
  ddi_4 t4828;
  ddi_4 t4829;
  ddi_4 t4830;
  ddi_4 t4831;
  ddi_4 t4832;
  ddi_4 t4833;
  ddi_4 t4834;
  ddi_4 t4835;
  ddi_4 t4836;
  ddi_4 t4837;
  ddi_4 t4838;
  ddi_4 t4839;
  ddi_4 t4840;
  ddi_4 t4841;
  ddi_4 t4842;
  ddi_4 t4843;
  ddi_4 t4844;
  ddi_4 t4845;
  ddi_4 t4846;
  ddi_4 t4847;
  ddi_4 t4848;
  ddi_4 t4849;
  ddi_4 t4850;
  ddi_4 t4851;
  ddi_4 t4852;
  ddi_4 t4853;
  ddi_4 t4854;
  ddi_4 t4855;
  ddi_4 t4856;
  ddi_4 t4857;
  ddi_4 t4858;
  ddi_4 t4859;
  ddi_4 t4860;
  ddi_4 t4861;
  ddi_4 t4862;
  ddi_4 t4863;
  ddi_4 t4864;
  ddi_4 t4865;
  ddi_4 t4866;
  ddi_4 t4867;
  ddi_4 t4868;
  ddi_4 t4869;
  ddi_4 t4870;
  ddi_4 t4871;
  ddi_4 t4872;
  ddi_4 t4873;
  ddi_4 t4874;
  ddi_4 t4875;
  ddi_4 t4876;
  ddi_4 t4877;
  ddi_4 t4878;
  ddi_4 t4879;
  ddi_4 t4880;
  ddi_4 t4881;
  ddi_4 *a1476;
  ddi_4 *a1483;
  a1476 = ((ddi_4 *)X);
  s6022 = *(a1476);
  s6023 = *((a1476 + 1));
  s6024 = _igen_dd_mm256_permute2f128_pd(s6022, s6023, (0) | ((2) << 4));
  s6025 = _igen_dd_mm256_permute2f128_pd(s6022, s6023, (1) | ((3) << 4));
  s6026 = _igen_dd_mm256_unpacklo_pd(s6024, s6025);
  s6027 = _igen_dd_mm256_unpackhi_pd(s6024, s6025);
  s6028 = *((a1476 + 16));
  s6029 = *((a1476 + 17));
  s6030 = _igen_dd_mm256_permute2f128_pd(s6028, s6029, (0) | ((2) << 4));
  s6031 = _igen_dd_mm256_permute2f128_pd(s6028, s6029, (1) | ((3) << 4));
  s6032 = _igen_dd_mm256_unpacklo_pd(s6030, s6031);
  s6033 = _igen_dd_mm256_unpackhi_pd(s6030, s6031);
  t4698 = _igen_dd_mm256_add_pd(s6026, s6032);
  t4699 = _igen_dd_mm256_add_pd(s6027, s6033);
  t4700 = _igen_dd_mm256_sub_pd(s6026, s6032);
  t4701 = _igen_dd_mm256_sub_pd(s6027, s6033);
  s6034 = *((a1476 + 8));
  s6035 = *((a1476 + 9));
  s6036 = _igen_dd_mm256_permute2f128_pd(s6034, s6035, (0) | ((2) << 4));
  s6037 = _igen_dd_mm256_permute2f128_pd(s6034, s6035, (1) | ((3) << 4));
  s6038 = _igen_dd_mm256_unpacklo_pd(s6036, s6037);
  s6039 = _igen_dd_mm256_unpackhi_pd(s6036, s6037);
  s6040 = *((a1476 + 24));
  s6041 = *((a1476 + 25));
  s6042 = _igen_dd_mm256_permute2f128_pd(s6040, s6041, (0) | ((2) << 4));
  s6043 = _igen_dd_mm256_permute2f128_pd(s6040, s6041, (1) | ((3) << 4));
  s6044 = _igen_dd_mm256_unpacklo_pd(s6042, s6043);
  s6045 = _igen_dd_mm256_unpackhi_pd(s6042, s6043);
  t4702 = _igen_dd_mm256_add_pd(s6038, s6044);
  t4703 = _igen_dd_mm256_add_pd(s6039, s6045);
  t4704 = _igen_dd_mm256_sub_pd(s6038, s6044);
  t4705 = _igen_dd_mm256_sub_pd(s6039, s6045);
  t4706 = _igen_dd_mm256_add_pd(t4698, t4702);
  t4707 = _igen_dd_mm256_add_pd(t4699, t4703);
  t4708 = _igen_dd_mm256_sub_pd(t4698, t4702);
  t4709 = _igen_dd_mm256_sub_pd(t4699, t4703);
  t4710 = _igen_dd_mm256_sub_pd(t4700, t4705);
  t4711 = _igen_dd_mm256_add_pd(t4701, t4704);
  t4712 = _igen_dd_mm256_add_pd(t4700, t4705);
  t4713 = _igen_dd_mm256_sub_pd(t4701, t4704);
  s6046 = *((a1476 + 4));
  s6047 = *((a1476 + 5));
  s6048 = _igen_dd_mm256_permute2f128_pd(s6046, s6047, (0) | ((2) << 4));
  s6049 = _igen_dd_mm256_permute2f128_pd(s6046, s6047, (1) | ((3) << 4));
  s6050 = _igen_dd_mm256_unpacklo_pd(s6048, s6049);
  s6051 = _igen_dd_mm256_unpackhi_pd(s6048, s6049);
  s6052 = *((a1476 + 20));
  s6053 = *((a1476 + 21));
  s6054 = _igen_dd_mm256_permute2f128_pd(s6052, s6053, (0) | ((2) << 4));
  s6055 = _igen_dd_mm256_permute2f128_pd(s6052, s6053, (1) | ((3) << 4));
  s6056 = _igen_dd_mm256_unpacklo_pd(s6054, s6055);
  s6057 = _igen_dd_mm256_unpackhi_pd(s6054, s6055);
  t4714 = _igen_dd_mm256_add_pd(s6050, s6056);
  t4715 = _igen_dd_mm256_add_pd(s6051, s6057);
  t4716 = _igen_dd_mm256_sub_pd(s6050, s6056);
  t4717 = _igen_dd_mm256_sub_pd(s6051, s6057);
  s6058 = *((a1476 + 12));
  s6059 = *((a1476 + 13));
  s6060 = _igen_dd_mm256_permute2f128_pd(s6058, s6059, (0) | ((2) << 4));
  s6061 = _igen_dd_mm256_permute2f128_pd(s6058, s6059, (1) | ((3) << 4));
  s6062 = _igen_dd_mm256_unpacklo_pd(s6060, s6061);
  s6063 = _igen_dd_mm256_unpackhi_pd(s6060, s6061);
  s6064 = *((a1476 + 28));
  s6065 = *((a1476 + 29));
  s6066 = _igen_dd_mm256_permute2f128_pd(s6064, s6065, (0) | ((2) << 4));
  s6067 = _igen_dd_mm256_permute2f128_pd(s6064, s6065, (1) | ((3) << 4));
  s6068 = _igen_dd_mm256_unpacklo_pd(s6066, s6067);
  s6069 = _igen_dd_mm256_unpackhi_pd(s6066, s6067);
  t4718 = _igen_dd_mm256_add_pd(s6062, s6068);
  t4719 = _igen_dd_mm256_add_pd(s6063, s6069);
  t4720 = _igen_dd_mm256_sub_pd(s6062, s6068);
  t4721 = _igen_dd_mm256_sub_pd(s6063, s6069);
  t4722 = _igen_dd_mm256_add_pd(t4714, t4718);
  t4723 = _igen_dd_mm256_add_pd(t4715, t4719);
  t4724 = _igen_dd_mm256_sub_pd(t4714, t4718);
  t4725 = _igen_dd_mm256_sub_pd(t4715, t4719);
  t4726 = _igen_dd_mm256_sub_pd(t4716, t4721);
  t4727 = _igen_dd_mm256_add_pd(t4717, t4720);
  dd_I _t1 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t2 = _igen_dd_mm256_set1_pd(_t1);
  ddi_4 _t3 = _igen_dd_mm256_sub_pd(t4726, t4727);
  s6070 = _igen_dd_mm256_mul_pd(_t2, _t3);
  dd_I _t4 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t5 = _igen_dd_mm256_set1_pd(_t4);
  ddi_4 _t6 = _igen_dd_mm256_add_pd(t4726, t4727);
  s6071 = _igen_dd_mm256_mul_pd(_t5, _t6);
  dd_I _t7 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  dd_I _t8 = _ia_neg_dd(_t7);
  ddi_4 _t9 = _igen_dd_mm256_set1_pd(_t8);
  ddi_4 _t10 = _igen_dd_mm256_add_pd(t4716, t4721);
  a1477 = _igen_dd_mm256_mul_pd(_t9, _t10);
  dd_I _t11 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t12 = _igen_dd_mm256_set1_pd(_t11);
  ddi_4 _t13 = _igen_dd_mm256_sub_pd(t4717, t4720);
  a1478 = _igen_dd_mm256_mul_pd(_t12, _t13);
  s6072 = _igen_dd_mm256_sub_pd(a1477, a1478);
  s6073 = _igen_dd_mm256_add_pd(a1477, a1478);
  t4728 = _igen_dd_mm256_add_pd(t4706, t4722);
  t4729 = _igen_dd_mm256_add_pd(t4707, t4723);
  t4730 = _igen_dd_mm256_sub_pd(t4706, t4722);
  t4731 = _igen_dd_mm256_sub_pd(t4707, t4723);
  t4732 = _igen_dd_mm256_add_pd(t4710, s6070);
  t4733 = _igen_dd_mm256_add_pd(t4711, s6071);
  t4734 = _igen_dd_mm256_sub_pd(t4710, s6070);
  t4735 = _igen_dd_mm256_sub_pd(t4711, s6071);
  t4736 = _igen_dd_mm256_sub_pd(t4708, t4725);
  t4737 = _igen_dd_mm256_add_pd(t4709, t4724);
  t4738 = _igen_dd_mm256_add_pd(t4708, t4725);
  t4739 = _igen_dd_mm256_sub_pd(t4709, t4724);
  t4740 = _igen_dd_mm256_add_pd(t4712, s6072);
  t4741 = _igen_dd_mm256_sub_pd(t4713, s6073);
  t4742 = _igen_dd_mm256_sub_pd(t4712, s6072);
  t4743 = _igen_dd_mm256_add_pd(t4713, s6073);
  s6074 = _igen_dd_mm256_unpacklo_pd(t4728, t4732);
  s6075 = _igen_dd_mm256_unpackhi_pd(t4728, t4732);
  s6076 = _igen_dd_mm256_unpacklo_pd(t4729, t4733);
  s6077 = _igen_dd_mm256_unpackhi_pd(t4729, t4733);
  s6078 = _igen_dd_mm256_permute2f128_pd(s6074, s6075, (0) | ((2) << 4));
  s6079 = _igen_dd_mm256_permute2f128_pd(s6074, s6075, (1) | ((3) << 4));
  s6080 = _igen_dd_mm256_permute2f128_pd(s6076, s6077, (0) | ((2) << 4));
  s6081 = _igen_dd_mm256_permute2f128_pd(s6076, s6077, (1) | ((3) << 4));
  s6082 = _igen_dd_mm256_unpacklo_pd(t4736, t4740);
  s6083 = _igen_dd_mm256_unpackhi_pd(t4736, t4740);
  s6084 = _igen_dd_mm256_unpacklo_pd(t4737, t4741);
  s6085 = _igen_dd_mm256_unpackhi_pd(t4737, t4741);
  s6086 = _igen_dd_mm256_permute2f128_pd(s6082, s6083, (0) | ((2) << 4));
  s6087 = _igen_dd_mm256_permute2f128_pd(s6082, s6083, (1) | ((3) << 4));
  s6088 = _igen_dd_mm256_permute2f128_pd(s6084, s6085, (0) | ((2) << 4));
  s6089 = _igen_dd_mm256_permute2f128_pd(s6084, s6085, (1) | ((3) << 4));
  s6090 = _igen_dd_mm256_permute2f128_pd(s6078, s6086, (0) | ((2) << 4));
  s6091 = _igen_dd_mm256_permute2f128_pd(s6078, s6086, (1) | ((3) << 4));
  s6092 = _igen_dd_mm256_permute2f128_pd(s6079, s6087, (0) | ((2) << 4));
  s6093 = _igen_dd_mm256_permute2f128_pd(s6079, s6087, (1) | ((3) << 4));
  s6094 = _igen_dd_mm256_permute2f128_pd(s6080, s6088, (0) | ((2) << 4));
  s6095 = _igen_dd_mm256_permute2f128_pd(s6080, s6088, (1) | ((3) << 4));
  s6096 = _igen_dd_mm256_permute2f128_pd(s6081, s6089, (0) | ((2) << 4));
  s6097 = _igen_dd_mm256_permute2f128_pd(s6081, s6089, (1) | ((3) << 4));
  s6098 = _igen_dd_mm256_unpacklo_pd(t4730, t4734);
  s6099 = _igen_dd_mm256_unpackhi_pd(t4730, t4734);
  s6100 = _igen_dd_mm256_unpacklo_pd(t4731, t4735);
  s6101 = _igen_dd_mm256_unpackhi_pd(t4731, t4735);
  s6102 = _igen_dd_mm256_permute2f128_pd(s6098, s6099, (0) | ((2) << 4));
  s6103 = _igen_dd_mm256_permute2f128_pd(s6098, s6099, (1) | ((3) << 4));
  s6104 = _igen_dd_mm256_permute2f128_pd(s6100, s6101, (0) | ((2) << 4));
  s6105 = _igen_dd_mm256_permute2f128_pd(s6100, s6101, (1) | ((3) << 4));
  s6106 = _igen_dd_mm256_unpacklo_pd(t4738, t4742);
  s6107 = _igen_dd_mm256_unpackhi_pd(t4738, t4742);
  s6108 = _igen_dd_mm256_unpacklo_pd(t4739, t4743);
  s6109 = _igen_dd_mm256_unpackhi_pd(t4739, t4743);
  s6110 = _igen_dd_mm256_permute2f128_pd(s6106, s6107, (0) | ((2) << 4));
  s6111 = _igen_dd_mm256_permute2f128_pd(s6106, s6107, (1) | ((3) << 4));
  s6112 = _igen_dd_mm256_permute2f128_pd(s6108, s6109, (0) | ((2) << 4));
  s6113 = _igen_dd_mm256_permute2f128_pd(s6108, s6109, (1) | ((3) << 4));
  s6114 = _igen_dd_mm256_permute2f128_pd(s6102, s6110, (0) | ((2) << 4));
  s6115 = _igen_dd_mm256_permute2f128_pd(s6102, s6110, (1) | ((3) << 4));
  s6116 = _igen_dd_mm256_permute2f128_pd(s6103, s6111, (0) | ((2) << 4));
  s6117 = _igen_dd_mm256_permute2f128_pd(s6103, s6111, (1) | ((3) << 4));
  s6118 = _igen_dd_mm256_permute2f128_pd(s6104, s6112, (0) | ((2) << 4));
  s6119 = _igen_dd_mm256_permute2f128_pd(s6104, s6112, (1) | ((3) << 4));
  s6120 = _igen_dd_mm256_permute2f128_pd(s6105, s6113, (0) | ((2) << 4));
  s6121 = _igen_dd_mm256_permute2f128_pd(s6105, s6113, (1) | ((3) << 4));
  s6122 = *((a1476 + 2));
  s6123 = *((a1476 + 3));
  s6124 = _igen_dd_mm256_permute2f128_pd(s6122, s6123, (0) | ((2) << 4));
  s6125 = _igen_dd_mm256_permute2f128_pd(s6122, s6123, (1) | ((3) << 4));
  s6126 = _igen_dd_mm256_unpacklo_pd(s6124, s6125);
  s6127 = _igen_dd_mm256_unpackhi_pd(s6124, s6125);
  s6128 = *((a1476 + 18));
  s6129 = *((a1476 + 19));
  s6130 = _igen_dd_mm256_permute2f128_pd(s6128, s6129, (0) | ((2) << 4));
  s6131 = _igen_dd_mm256_permute2f128_pd(s6128, s6129, (1) | ((3) << 4));
  s6132 = _igen_dd_mm256_unpacklo_pd(s6130, s6131);
  s6133 = _igen_dd_mm256_unpackhi_pd(s6130, s6131);
  t4744 = _igen_dd_mm256_add_pd(s6126, s6132);
  t4745 = _igen_dd_mm256_add_pd(s6127, s6133);
  t4746 = _igen_dd_mm256_sub_pd(s6126, s6132);
  t4747 = _igen_dd_mm256_sub_pd(s6127, s6133);
  s6134 = *((a1476 + 10));
  s6135 = *((a1476 + 11));
  s6136 = _igen_dd_mm256_permute2f128_pd(s6134, s6135, (0) | ((2) << 4));
  s6137 = _igen_dd_mm256_permute2f128_pd(s6134, s6135, (1) | ((3) << 4));
  s6138 = _igen_dd_mm256_unpacklo_pd(s6136, s6137);
  s6139 = _igen_dd_mm256_unpackhi_pd(s6136, s6137);
  s6140 = *((a1476 + 26));
  s6141 = *((a1476 + 27));
  s6142 = _igen_dd_mm256_permute2f128_pd(s6140, s6141, (0) | ((2) << 4));
  s6143 = _igen_dd_mm256_permute2f128_pd(s6140, s6141, (1) | ((3) << 4));
  s6144 = _igen_dd_mm256_unpacklo_pd(s6142, s6143);
  s6145 = _igen_dd_mm256_unpackhi_pd(s6142, s6143);
  t4748 = _igen_dd_mm256_add_pd(s6138, s6144);
  t4749 = _igen_dd_mm256_add_pd(s6139, s6145);
  t4750 = _igen_dd_mm256_sub_pd(s6138, s6144);
  t4751 = _igen_dd_mm256_sub_pd(s6139, s6145);
  t4752 = _igen_dd_mm256_add_pd(t4744, t4748);
  t4753 = _igen_dd_mm256_add_pd(t4745, t4749);
  t4754 = _igen_dd_mm256_sub_pd(t4744, t4748);
  t4755 = _igen_dd_mm256_sub_pd(t4745, t4749);
  t4756 = _igen_dd_mm256_sub_pd(t4746, t4751);
  t4757 = _igen_dd_mm256_add_pd(t4747, t4750);
  t4758 = _igen_dd_mm256_add_pd(t4746, t4751);
  t4759 = _igen_dd_mm256_sub_pd(t4747, t4750);
  s6146 = *((a1476 + 6));
  s6147 = *((a1476 + 7));
  s6148 = _igen_dd_mm256_permute2f128_pd(s6146, s6147, (0) | ((2) << 4));
  s6149 = _igen_dd_mm256_permute2f128_pd(s6146, s6147, (1) | ((3) << 4));
  s6150 = _igen_dd_mm256_unpacklo_pd(s6148, s6149);
  s6151 = _igen_dd_mm256_unpackhi_pd(s6148, s6149);
  s6152 = *((a1476 + 22));
  s6153 = *((a1476 + 23));
  s6154 = _igen_dd_mm256_permute2f128_pd(s6152, s6153, (0) | ((2) << 4));
  s6155 = _igen_dd_mm256_permute2f128_pd(s6152, s6153, (1) | ((3) << 4));
  s6156 = _igen_dd_mm256_unpacklo_pd(s6154, s6155);
  s6157 = _igen_dd_mm256_unpackhi_pd(s6154, s6155);
  t4760 = _igen_dd_mm256_add_pd(s6150, s6156);
  t4761 = _igen_dd_mm256_add_pd(s6151, s6157);
  t4762 = _igen_dd_mm256_sub_pd(s6150, s6156);
  t4763 = _igen_dd_mm256_sub_pd(s6151, s6157);
  s6158 = *((a1476 + 14));
  s6159 = *((a1476 + 15));
  s6160 = _igen_dd_mm256_permute2f128_pd(s6158, s6159, (0) | ((2) << 4));
  s6161 = _igen_dd_mm256_permute2f128_pd(s6158, s6159, (1) | ((3) << 4));
  s6162 = _igen_dd_mm256_unpacklo_pd(s6160, s6161);
  s6163 = _igen_dd_mm256_unpackhi_pd(s6160, s6161);
  s6164 = *((a1476 + 30));
  s6165 = *((a1476 + 31));
  s6166 = _igen_dd_mm256_permute2f128_pd(s6164, s6165, (0) | ((2) << 4));
  s6167 = _igen_dd_mm256_permute2f128_pd(s6164, s6165, (1) | ((3) << 4));
  s6168 = _igen_dd_mm256_unpacklo_pd(s6166, s6167);
  s6169 = _igen_dd_mm256_unpackhi_pd(s6166, s6167);
  t4764 = _igen_dd_mm256_add_pd(s6162, s6168);
  t4765 = _igen_dd_mm256_add_pd(s6163, s6169);
  t4766 = _igen_dd_mm256_sub_pd(s6162, s6168);
  t4767 = _igen_dd_mm256_sub_pd(s6163, s6169);
  t4768 = _igen_dd_mm256_add_pd(t4760, t4764);
  t4769 = _igen_dd_mm256_add_pd(t4761, t4765);
  t4770 = _igen_dd_mm256_sub_pd(t4760, t4764);
  t4771 = _igen_dd_mm256_sub_pd(t4761, t4765);
  t4772 = _igen_dd_mm256_sub_pd(t4762, t4767);
  t4773 = _igen_dd_mm256_add_pd(t4763, t4766);
  dd_I _t14 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t15 = _igen_dd_mm256_set1_pd(_t14);
  ddi_4 _t16 = _igen_dd_mm256_sub_pd(t4772, t4773);
  s6170 = _igen_dd_mm256_mul_pd(_t15, _t16);
  dd_I _t17 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t18 = _igen_dd_mm256_set1_pd(_t17);
  ddi_4 _t19 = _igen_dd_mm256_add_pd(t4772, t4773);
  s6171 = _igen_dd_mm256_mul_pd(_t18, _t19);
  dd_I _t20 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t21 = _ia_neg_dd(_t20);
  ddi_4 _t22 = _igen_dd_mm256_set1_pd(_t21);
  ddi_4 _t23 = _igen_dd_mm256_add_pd(t4762, t4767);
  a1479 = _igen_dd_mm256_mul_pd(_t22, _t23);
  dd_I _t24 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t25 = _igen_dd_mm256_set1_pd(_t24);
  ddi_4 _t26 = _igen_dd_mm256_sub_pd(t4763, t4766);
  a1480 = _igen_dd_mm256_mul_pd(_t25, _t26);
  s6172 = _igen_dd_mm256_sub_pd(a1479, a1480);
  s6173 = _igen_dd_mm256_add_pd(a1479, a1480);
  t4774 = _igen_dd_mm256_add_pd(t4752, t4768);
  t4775 = _igen_dd_mm256_add_pd(t4753, t4769);
  t4776 = _igen_dd_mm256_sub_pd(t4752, t4768);
  t4777 = _igen_dd_mm256_sub_pd(t4753, t4769);
  t4778 = _igen_dd_mm256_add_pd(t4756, s6170);
  t4779 = _igen_dd_mm256_add_pd(t4757, s6171);
  t4780 = _igen_dd_mm256_sub_pd(t4756, s6170);
  t4781 = _igen_dd_mm256_sub_pd(t4757, s6171);
  t4782 = _igen_dd_mm256_sub_pd(t4754, t4771);
  t4783 = _igen_dd_mm256_add_pd(t4755, t4770);
  t4784 = _igen_dd_mm256_add_pd(t4754, t4771);
  t4785 = _igen_dd_mm256_sub_pd(t4755, t4770);
  t4786 = _igen_dd_mm256_add_pd(t4758, s6172);
  t4787 = _igen_dd_mm256_sub_pd(t4759, s6173);
  t4788 = _igen_dd_mm256_sub_pd(t4758, s6172);
  t4789 = _igen_dd_mm256_add_pd(t4759, s6173);
  s6174 = _igen_dd_mm256_unpacklo_pd(t4774, t4778);
  s6175 = _igen_dd_mm256_unpackhi_pd(t4774, t4778);
  s6176 = _igen_dd_mm256_unpacklo_pd(t4775, t4779);
  s6177 = _igen_dd_mm256_unpackhi_pd(t4775, t4779);
  s6178 = _igen_dd_mm256_permute2f128_pd(s6174, s6175, (0) | ((2) << 4));
  s6179 = _igen_dd_mm256_permute2f128_pd(s6174, s6175, (1) | ((3) << 4));
  s6180 = _igen_dd_mm256_permute2f128_pd(s6176, s6177, (0) | ((2) << 4));
  s6181 = _igen_dd_mm256_permute2f128_pd(s6176, s6177, (1) | ((3) << 4));
  s6182 = _igen_dd_mm256_unpacklo_pd(t4782, t4786);
  s6183 = _igen_dd_mm256_unpackhi_pd(t4782, t4786);
  s6184 = _igen_dd_mm256_unpacklo_pd(t4783, t4787);
  s6185 = _igen_dd_mm256_unpackhi_pd(t4783, t4787);
  s6186 = _igen_dd_mm256_permute2f128_pd(s6182, s6183, (0) | ((2) << 4));
  s6187 = _igen_dd_mm256_permute2f128_pd(s6182, s6183, (1) | ((3) << 4));
  s6188 = _igen_dd_mm256_permute2f128_pd(s6184, s6185, (0) | ((2) << 4));
  s6189 = _igen_dd_mm256_permute2f128_pd(s6184, s6185, (1) | ((3) << 4));
  s6190 = _igen_dd_mm256_permute2f128_pd(s6178, s6186, (0) | ((2) << 4));
  s6191 = _igen_dd_mm256_permute2f128_pd(s6178, s6186, (1) | ((3) << 4));
  s6192 = _igen_dd_mm256_permute2f128_pd(s6179, s6187, (0) | ((2) << 4));
  s6193 = _igen_dd_mm256_permute2f128_pd(s6179, s6187, (1) | ((3) << 4));
  s6194 = _igen_dd_mm256_permute2f128_pd(s6180, s6188, (0) | ((2) << 4));
  s6195 = _igen_dd_mm256_permute2f128_pd(s6180, s6188, (1) | ((3) << 4));
  s6196 = _igen_dd_mm256_permute2f128_pd(s6181, s6189, (0) | ((2) << 4));
  s6197 = _igen_dd_mm256_permute2f128_pd(s6181, s6189, (1) | ((3) << 4));
  s6198 = _igen_dd_mm256_unpacklo_pd(t4776, t4780);
  s6199 = _igen_dd_mm256_unpackhi_pd(t4776, t4780);
  s6200 = _igen_dd_mm256_unpacklo_pd(t4777, t4781);
  s6201 = _igen_dd_mm256_unpackhi_pd(t4777, t4781);
  s6202 = _igen_dd_mm256_permute2f128_pd(s6198, s6199, (0) | ((2) << 4));
  s6203 = _igen_dd_mm256_permute2f128_pd(s6198, s6199, (1) | ((3) << 4));
  s6204 = _igen_dd_mm256_permute2f128_pd(s6200, s6201, (0) | ((2) << 4));
  s6205 = _igen_dd_mm256_permute2f128_pd(s6200, s6201, (1) | ((3) << 4));
  s6206 = _igen_dd_mm256_unpacklo_pd(t4784, t4788);
  s6207 = _igen_dd_mm256_unpackhi_pd(t4784, t4788);
  s6208 = _igen_dd_mm256_unpacklo_pd(t4785, t4789);
  s6209 = _igen_dd_mm256_unpackhi_pd(t4785, t4789);
  s6210 = _igen_dd_mm256_permute2f128_pd(s6206, s6207, (0) | ((2) << 4));
  s6211 = _igen_dd_mm256_permute2f128_pd(s6206, s6207, (1) | ((3) << 4));
  s6212 = _igen_dd_mm256_permute2f128_pd(s6208, s6209, (0) | ((2) << 4));
  s6213 = _igen_dd_mm256_permute2f128_pd(s6208, s6209, (1) | ((3) << 4));
  s6214 = _igen_dd_mm256_permute2f128_pd(s6202, s6210, (0) | ((2) << 4));
  s6215 = _igen_dd_mm256_permute2f128_pd(s6202, s6210, (1) | ((3) << 4));
  s6216 = _igen_dd_mm256_permute2f128_pd(s6203, s6211, (0) | ((2) << 4));
  s6217 = _igen_dd_mm256_permute2f128_pd(s6203, s6211, (1) | ((3) << 4));
  s6218 = _igen_dd_mm256_permute2f128_pd(s6204, s6212, (0) | ((2) << 4));
  s6219 = _igen_dd_mm256_permute2f128_pd(s6204, s6212, (1) | ((3) << 4));
  s6220 = _igen_dd_mm256_permute2f128_pd(s6205, s6213, (0) | ((2) << 4));
  s6221 = _igen_dd_mm256_permute2f128_pd(s6205, s6213, (1) | ((3) << 4));
  dd_I _t27 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t28 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t29 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t30 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t31 = _igen_dd_mm256_set_pd(_t27, _t28, _t29, _t30);
  dd_I _t32 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t33 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t34 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t35 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t36 = _igen_dd_mm256_set_pd(_t32, _t33, _t34, _t35);
  ddi_4 _t37 = _igen_dd_mm256_mul_pd(_t31, s6190);
  ddi_4 _t38 = _igen_dd_mm256_mul_pd(_t36, s6194);
  s6222 = _igen_dd_mm256_sub_pd(_t37, _t38);
  dd_I _t39 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t40 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t41 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t42 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t43 = _igen_dd_mm256_set_pd(_t39, _t40, _t41, _t42);
  dd_I _t44 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t45 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t46 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t47 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t48 = _igen_dd_mm256_set_pd(_t44, _t45, _t46, _t47);
  ddi_4 _t49 = _igen_dd_mm256_mul_pd(_t43, s6190);
  ddi_4 _t50 = _igen_dd_mm256_mul_pd(_t48, s6194);
  s6223 = _igen_dd_mm256_add_pd(_t49, _t50);
  t4790 = _igen_dd_mm256_add_pd(s6090, s6222);
  t4791 = _igen_dd_mm256_add_pd(s6094, s6223);
  t4792 = _igen_dd_mm256_sub_pd(s6090, s6222);
  t4793 = _igen_dd_mm256_sub_pd(s6094, s6223);
  dd_I _t51 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                         0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t52 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                         0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t53 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                         0.99518472667219693, 1.268249368586112e-18);
  dd_I _t54 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t55 = _igen_dd_mm256_set_pd(_t51, _t52, _t53, _t54);
  dd_I _t56 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                         0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t57 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                         0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t58 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                         0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t59 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t60 = _igen_dd_mm256_set_pd(_t56, _t57, _t58, _t59);
  ddi_4 _t61 = _igen_dd_mm256_mul_pd(_t55, s6091);
  ddi_4 _t62 = _igen_dd_mm256_mul_pd(_t60, s6095);
  s6224 = _igen_dd_mm256_sub_pd(_t61, _t62);
  dd_I _t63 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                         0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t64 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                         0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t65 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                         0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t66 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t67 = _igen_dd_mm256_set_pd(_t63, _t64, _t65, _t66);
  dd_I _t68 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                         0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t69 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                         0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t70 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                         0.99518472667219693, 1.268249368586112e-18);
  dd_I _t71 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t72 = _igen_dd_mm256_set_pd(_t68, _t69, _t70, _t71);
  ddi_4 _t73 = _igen_dd_mm256_mul_pd(_t67, s6091);
  ddi_4 _t74 = _igen_dd_mm256_mul_pd(_t72, s6095);
  s6225 = _igen_dd_mm256_add_pd(_t73, _t74);
  dd_I _t75 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                         0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t76 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                         0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t77 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                         0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t78 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t79 = _igen_dd_mm256_set_pd(_t75, _t76, _t77, _t78);
  dd_I _t80 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                         0.99518472667219693, 1.268249368586112e-18);
  dd_I _t81 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                         0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t82 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                         0.47139673682599764, -2.039709489836241e-18);
  dd_I _t83 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t84 = _igen_dd_mm256_set_pd(_t80, _t81, _t82, _t83);
  ddi_4 _t85 = _igen_dd_mm256_mul_pd(_t79, s6191);
  ddi_4 _t86 = _igen_dd_mm256_mul_pd(_t84, s6195);
  s6226 = _igen_dd_mm256_sub_pd(_t85, _t86);
  dd_I _t87 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                         0.99518472667219693, 1.268249368586112e-18);
  dd_I _t88 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                         0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t89 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                         0.47139673682599764, -2.039709489836241e-18);
  dd_I _t90 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t91 = _igen_dd_mm256_set_pd(_t87, _t88, _t89, _t90);
  dd_I _t92 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                         0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t93 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                         0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t94 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                         0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t95 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t96 = _igen_dd_mm256_set_pd(_t92, _t93, _t94, _t95);
  ddi_4 _t97 = _igen_dd_mm256_mul_pd(_t91, s6191);
  ddi_4 _t98 = _igen_dd_mm256_mul_pd(_t96, s6195);
  s6227 = _igen_dd_mm256_add_pd(_t97, _t98);
  t4794 = _igen_dd_mm256_add_pd(s6224, s6226);
  t4795 = _igen_dd_mm256_add_pd(s6225, s6227);
  t4796 = _igen_dd_mm256_sub_pd(s6224, s6226);
  t4797 = _igen_dd_mm256_sub_pd(s6225, s6227);
  dd_I _t99 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t100 = _igen_dd_mm256_set1_pd(_t99);
  ddi_4 _t101 = _igen_dd_mm256_sub_pd(t4796, t4797);
  s6228 = _igen_dd_mm256_mul_pd(_t100, _t101);
  dd_I _t102 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t103 = _igen_dd_mm256_set1_pd(_t102);
  ddi_4 _t104 = _igen_dd_mm256_add_pd(t4796, t4797);
  s6229 = _igen_dd_mm256_mul_pd(_t103, _t104);
  dd_I _t105 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t106 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t107 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t108 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t109 = _igen_dd_mm256_set_pd(_t105, _t106, _t107, _t108);
  dd_I _t110 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t111 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t112 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t113 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t114 = _igen_dd_mm256_set_pd(_t110, _t111, _t112, _t113);
  ddi_4 _t115 = _igen_dd_mm256_mul_pd(_t109, s6092);
  ddi_4 _t116 = _igen_dd_mm256_mul_pd(_t114, s6096);
  s6230 = _igen_dd_mm256_sub_pd(_t115, _t116);
  dd_I _t117 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t118 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t119 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t120 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t121 = _igen_dd_mm256_set_pd(_t117, _t118, _t119, _t120);
  dd_I _t122 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t123 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t124 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t125 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t126 = _igen_dd_mm256_set_pd(_t122, _t123, _t124, _t125);
  ddi_4 _t127 = _igen_dd_mm256_mul_pd(_t121, s6092);
  ddi_4 _t128 = _igen_dd_mm256_mul_pd(_t126, s6096);
  s6231 = _igen_dd_mm256_add_pd(_t127, _t128);
  dd_I _t129 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t130 = _ia_neg_dd(_t129);
  dd_I _t131 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t132 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t133 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t134 = _igen_dd_mm256_set_pd(_t130, _t131, _t132, _t133);
  dd_I _t135 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t136 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t137 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t138 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t139 = _igen_dd_mm256_set_pd(_t135, _t136, _t137, _t138);
  ddi_4 _t140 = _igen_dd_mm256_mul_pd(_t134, s6192);
  ddi_4 _t141 = _igen_dd_mm256_mul_pd(_t139, s6196);
  s6232 = _igen_dd_mm256_sub_pd(_t140, _t141);
  dd_I _t142 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t143 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t144 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t145 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t146 = _igen_dd_mm256_set_pd(_t142, _t143, _t144, _t145);
  dd_I _t147 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t148 = _ia_neg_dd(_t147);
  dd_I _t149 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t150 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t151 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t152 = _igen_dd_mm256_set_pd(_t148, _t149, _t150, _t151);
  ddi_4 _t153 = _igen_dd_mm256_mul_pd(_t146, s6192);
  ddi_4 _t154 = _igen_dd_mm256_mul_pd(_t152, s6196);
  s6233 = _igen_dd_mm256_add_pd(_t153, _t154);
  t4798 = _igen_dd_mm256_add_pd(s6230, s6232);
  t4799 = _igen_dd_mm256_add_pd(s6231, s6233);
  t4800 = _igen_dd_mm256_sub_pd(s6230, s6232);
  t4801 = _igen_dd_mm256_sub_pd(s6231, s6233);
  dd_I _t155 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t156 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t157 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t158 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t159 = _igen_dd_mm256_set_pd(_t155, _t156, _t157, _t158);
  dd_I _t160 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t161 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t162 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t163 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t164 = _igen_dd_mm256_set_pd(_t160, _t161, _t162, _t163);
  ddi_4 _t165 = _igen_dd_mm256_mul_pd(_t159, s6093);
  ddi_4 _t166 = _igen_dd_mm256_mul_pd(_t164, s6097);
  s6234 = _igen_dd_mm256_sub_pd(_t165, _t166);
  dd_I _t167 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t168 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t169 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t170 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t171 = _igen_dd_mm256_set_pd(_t167, _t168, _t169, _t170);
  dd_I _t172 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t173 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t174 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t175 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t176 = _igen_dd_mm256_set_pd(_t172, _t173, _t174, _t175);
  ddi_4 _t177 = _igen_dd_mm256_mul_pd(_t171, s6093);
  ddi_4 _t178 = _igen_dd_mm256_mul_pd(_t176, s6097);
  s6235 = _igen_dd_mm256_add_pd(_t177, _t178);
  dd_I _t179 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t180 = _ia_neg_dd(_t179);
  dd_I _t181 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t182 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t183 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t184 = _igen_dd_mm256_set_pd(_t180, _t181, _t182, _t183);
  dd_I _t185 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t186 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t187 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t188 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t189 = _igen_dd_mm256_set_pd(_t185, _t186, _t187, _t188);
  ddi_4 _t190 = _igen_dd_mm256_mul_pd(_t184, s6193);
  ddi_4 _t191 = _igen_dd_mm256_mul_pd(_t189, s6197);
  s6236 = _igen_dd_mm256_sub_pd(_t190, _t191);
  dd_I _t192 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t193 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t194 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t195 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t196 = _igen_dd_mm256_set_pd(_t192, _t193, _t194, _t195);
  dd_I _t197 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t198 = _ia_neg_dd(_t197);
  dd_I _t199 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t200 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t201 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t202 = _igen_dd_mm256_set_pd(_t198, _t199, _t200, _t201);
  ddi_4 _t203 = _igen_dd_mm256_mul_pd(_t196, s6193);
  ddi_4 _t204 = _igen_dd_mm256_mul_pd(_t202, s6197);
  s6237 = _igen_dd_mm256_add_pd(_t203, _t204);
  t4802 = _igen_dd_mm256_add_pd(s6234, s6236);
  t4803 = _igen_dd_mm256_add_pd(s6235, s6237);
  dd_I _t205 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t206 = _ia_neg_dd(_t205);
  ddi_4 _t207 = _igen_dd_mm256_set1_pd(_t206);
  ddi_4 _t208 = _igen_dd_mm256_sub_pd(s6234, s6236);
  a1481 = _igen_dd_mm256_mul_pd(_t207, _t208);
  dd_I _t209 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t210 = _igen_dd_mm256_set1_pd(_t209);
  ddi_4 _t211 = _igen_dd_mm256_sub_pd(s6235, s6237);
  a1482 = _igen_dd_mm256_mul_pd(_t210, _t211);
  s6238 = _igen_dd_mm256_sub_pd(a1481, a1482);
  s6239 = _igen_dd_mm256_add_pd(a1481, a1482);
  t4804 = _igen_dd_mm256_add_pd(t4790, t4798);
  t4805 = _igen_dd_mm256_add_pd(t4791, t4799);
  t4806 = _igen_dd_mm256_sub_pd(t4790, t4798);
  t4807 = _igen_dd_mm256_sub_pd(t4791, t4799);
  t4808 = _igen_dd_mm256_add_pd(t4794, t4802);
  t4809 = _igen_dd_mm256_add_pd(t4795, t4803);
  t4810 = _igen_dd_mm256_sub_pd(t4794, t4802);
  t4811 = _igen_dd_mm256_sub_pd(t4795, t4803);
  t4812 = _igen_dd_mm256_add_pd(t4804, t4808);
  t4813 = _igen_dd_mm256_add_pd(t4805, t4809);
  t4814 = _igen_dd_mm256_sub_pd(t4804, t4808);
  t4815 = _igen_dd_mm256_sub_pd(t4805, t4809);
  s6240 = _igen_dd_mm256_unpacklo_pd(t4812, t4813);
  s6241 = _igen_dd_mm256_unpackhi_pd(t4812, t4813);
  a1483 = ((ddi_4 *)Y);
  s6242 = _igen_dd_mm256_permute2f128_pd(s6240, s6241, (0) | ((2) << 4));
  *(a1483) = s6242;
  s6243 = _igen_dd_mm256_permute2f128_pd(s6240, s6241, (1) | ((3) << 4));
  *((a1483 + 1)) = s6243;
  s6244 = _igen_dd_mm256_unpacklo_pd(t4814, t4815);
  s6245 = _igen_dd_mm256_unpackhi_pd(t4814, t4815);
  s6246 = _igen_dd_mm256_permute2f128_pd(s6244, s6245, (0) | ((2) << 4));
  *((a1483 + 16)) = s6246;
  s6247 = _igen_dd_mm256_permute2f128_pd(s6244, s6245, (1) | ((3) << 4));
  *((a1483 + 17)) = s6247;
  t4816 = _igen_dd_mm256_sub_pd(t4806, t4811);
  t4817 = _igen_dd_mm256_add_pd(t4807, t4810);
  t4818 = _igen_dd_mm256_add_pd(t4806, t4811);
  t4819 = _igen_dd_mm256_sub_pd(t4807, t4810);
  s6248 = _igen_dd_mm256_unpacklo_pd(t4816, t4817);
  s6249 = _igen_dd_mm256_unpackhi_pd(t4816, t4817);
  s6250 = _igen_dd_mm256_permute2f128_pd(s6248, s6249, (0) | ((2) << 4));
  *((a1483 + 8)) = s6250;
  s6251 = _igen_dd_mm256_permute2f128_pd(s6248, s6249, (1) | ((3) << 4));
  *((a1483 + 9)) = s6251;
  s6252 = _igen_dd_mm256_unpacklo_pd(t4818, t4819);
  s6253 = _igen_dd_mm256_unpackhi_pd(t4818, t4819);
  s6254 = _igen_dd_mm256_permute2f128_pd(s6252, s6253, (0) | ((2) << 4));
  *((a1483 + 24)) = s6254;
  s6255 = _igen_dd_mm256_permute2f128_pd(s6252, s6253, (1) | ((3) << 4));
  *((a1483 + 25)) = s6255;
  t4820 = _igen_dd_mm256_sub_pd(t4792, t4801);
  t4821 = _igen_dd_mm256_add_pd(t4793, t4800);
  t4822 = _igen_dd_mm256_add_pd(t4792, t4801);
  t4823 = _igen_dd_mm256_sub_pd(t4793, t4800);
  t4824 = _igen_dd_mm256_add_pd(s6228, s6238);
  t4825 = _igen_dd_mm256_sub_pd(s6229, s6239);
  t4826 = _igen_dd_mm256_sub_pd(s6228, s6238);
  t4827 = _igen_dd_mm256_add_pd(s6229, s6239);
  t4828 = _igen_dd_mm256_add_pd(t4820, t4824);
  t4829 = _igen_dd_mm256_add_pd(t4821, t4825);
  t4830 = _igen_dd_mm256_sub_pd(t4820, t4824);
  t4831 = _igen_dd_mm256_sub_pd(t4821, t4825);
  s6256 = _igen_dd_mm256_unpacklo_pd(t4828, t4829);
  s6257 = _igen_dd_mm256_unpackhi_pd(t4828, t4829);
  s6258 = _igen_dd_mm256_permute2f128_pd(s6256, s6257, (0) | ((2) << 4));
  *((a1483 + 4)) = s6258;
  s6259 = _igen_dd_mm256_permute2f128_pd(s6256, s6257, (1) | ((3) << 4));
  *((a1483 + 5)) = s6259;
  s6260 = _igen_dd_mm256_unpacklo_pd(t4830, t4831);
  s6261 = _igen_dd_mm256_unpackhi_pd(t4830, t4831);
  s6262 = _igen_dd_mm256_permute2f128_pd(s6260, s6261, (0) | ((2) << 4));
  *((a1483 + 20)) = s6262;
  s6263 = _igen_dd_mm256_permute2f128_pd(s6260, s6261, (1) | ((3) << 4));
  *((a1483 + 21)) = s6263;
  t4832 = _igen_dd_mm256_sub_pd(t4822, t4827);
  t4833 = _igen_dd_mm256_add_pd(t4823, t4826);
  t4834 = _igen_dd_mm256_add_pd(t4822, t4827);
  t4835 = _igen_dd_mm256_sub_pd(t4823, t4826);
  s6264 = _igen_dd_mm256_unpacklo_pd(t4832, t4833);
  s6265 = _igen_dd_mm256_unpackhi_pd(t4832, t4833);
  s6266 = _igen_dd_mm256_permute2f128_pd(s6264, s6265, (0) | ((2) << 4));
  *((a1483 + 12)) = s6266;
  s6267 = _igen_dd_mm256_permute2f128_pd(s6264, s6265, (1) | ((3) << 4));
  *((a1483 + 13)) = s6267;
  s6268 = _igen_dd_mm256_unpacklo_pd(t4834, t4835);
  s6269 = _igen_dd_mm256_unpackhi_pd(t4834, t4835);
  s6270 = _igen_dd_mm256_permute2f128_pd(s6268, s6269, (0) | ((2) << 4));
  *((a1483 + 28)) = s6270;
  s6271 = _igen_dd_mm256_permute2f128_pd(s6268, s6269, (1) | ((3) << 4));
  *((a1483 + 29)) = s6271;
  dd_I _t212 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t213 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t214 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t215 = _ia_neg_dd(_t212);
  dd_I _t216 = _ia_neg_dd(_t213);
  dd_I _t217 = _ia_neg_dd(_t214);
  dd_I _t218 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t219 = _igen_dd_mm256_set_pd(_t215, _t216, _t217, _t218);
  dd_I _t220 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t221 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t222 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t223 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t224 = _igen_dd_mm256_set_pd(_t220, _t221, _t222, _t223);
  ddi_4 _t225 = _igen_dd_mm256_mul_pd(_t219, s6214);
  ddi_4 _t226 = _igen_dd_mm256_mul_pd(_t224, s6218);
  s6272 = _igen_dd_mm256_sub_pd(_t225, _t226);
  dd_I _t227 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t228 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t229 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t230 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t231 = _igen_dd_mm256_set_pd(_t227, _t228, _t229, _t230);
  dd_I _t232 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t233 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t234 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t235 = _ia_neg_dd(_t232);
  dd_I _t236 = _ia_neg_dd(_t233);
  dd_I _t237 = _ia_neg_dd(_t234);
  dd_I _t238 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t239 = _igen_dd_mm256_set_pd(_t235, _t236, _t237, _t238);
  ddi_4 _t240 = _igen_dd_mm256_mul_pd(_t231, s6214);
  ddi_4 _t241 = _igen_dd_mm256_mul_pd(_t239, s6218);
  s6273 = _igen_dd_mm256_add_pd(_t240, _t241);
  t4836 = _igen_dd_mm256_add_pd(s6114, s6272);
  t4837 = _igen_dd_mm256_add_pd(s6118, s6273);
  t4838 = _igen_dd_mm256_sub_pd(s6114, s6272);
  t4839 = _igen_dd_mm256_sub_pd(s6118, s6273);
  dd_I _t242 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t243 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t244 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t245 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t246 = _igen_dd_mm256_set_pd(_t242, _t243, _t244, _t245);
  dd_I _t247 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t248 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t249 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t250 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t251 = _igen_dd_mm256_set_pd(_t247, _t248, _t249, _t250);
  ddi_4 _t252 = _igen_dd_mm256_mul_pd(_t246, s6115);
  ddi_4 _t253 = _igen_dd_mm256_mul_pd(_t251, s6119);
  s6274 = _igen_dd_mm256_sub_pd(_t252, _t253);
  dd_I _t254 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t255 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t256 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t257 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t258 = _igen_dd_mm256_set_pd(_t254, _t255, _t256, _t257);
  dd_I _t259 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t260 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t261 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t262 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t263 = _igen_dd_mm256_set_pd(_t259, _t260, _t261, _t262);
  ddi_4 _t264 = _igen_dd_mm256_mul_pd(_t258, s6115);
  ddi_4 _t265 = _igen_dd_mm256_mul_pd(_t263, s6119);
  s6275 = _igen_dd_mm256_add_pd(_t264, _t265);
  dd_I _t266 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t267 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t268 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t269 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t270 = _ia_neg_dd(_t266);
  dd_I _t271 = _ia_neg_dd(_t267);
  dd_I _t272 = _ia_neg_dd(_t268);
  dd_I _t273 = _ia_neg_dd(_t269);
  ddi_4 _t274 = _igen_dd_mm256_set_pd(_t270, _t271, _t272, _t273);
  dd_I _t275 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t276 = _ia_neg_dd(_t275);
  dd_I _t277 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t278 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t279 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t280 = _igen_dd_mm256_set_pd(_t276, _t277, _t278, _t279);
  ddi_4 _t281 = _igen_dd_mm256_mul_pd(_t274, s6215);
  ddi_4 _t282 = _igen_dd_mm256_mul_pd(_t280, s6219);
  s6276 = _igen_dd_mm256_sub_pd(_t281, _t282);
  dd_I _t283 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t284 = _ia_neg_dd(_t283);
  dd_I _t285 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t286 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t287 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t288 = _igen_dd_mm256_set_pd(_t284, _t285, _t286, _t287);
  dd_I _t289 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t290 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t291 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t292 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t293 = _ia_neg_dd(_t289);
  dd_I _t294 = _ia_neg_dd(_t290);
  dd_I _t295 = _ia_neg_dd(_t291);
  dd_I _t296 = _ia_neg_dd(_t292);
  ddi_4 _t297 = _igen_dd_mm256_set_pd(_t293, _t294, _t295, _t296);
  ddi_4 _t298 = _igen_dd_mm256_mul_pd(_t288, s6215);
  ddi_4 _t299 = _igen_dd_mm256_mul_pd(_t297, s6219);
  s6277 = _igen_dd_mm256_add_pd(_t298, _t299);
  t4840 = _igen_dd_mm256_add_pd(s6274, s6276);
  t4841 = _igen_dd_mm256_add_pd(s6275, s6277);
  t4842 = _igen_dd_mm256_sub_pd(s6274, s6276);
  t4843 = _igen_dd_mm256_sub_pd(s6275, s6277);
  dd_I _t300 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t301 = _igen_dd_mm256_set1_pd(_t300);
  ddi_4 _t302 = _igen_dd_mm256_sub_pd(t4842, t4843);
  s6278 = _igen_dd_mm256_mul_pd(_t301, _t302);
  dd_I _t303 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t304 = _igen_dd_mm256_set1_pd(_t303);
  ddi_4 _t305 = _igen_dd_mm256_add_pd(t4842, t4843);
  s6279 = _igen_dd_mm256_mul_pd(_t304, _t305);
  dd_I _t306 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t307 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t308 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t309 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t310 = _igen_dd_mm256_set_pd(_t306, _t307, _t308, _t309);
  dd_I _t311 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t312 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t313 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t314 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t315 = _igen_dd_mm256_set_pd(_t311, _t312, _t313, _t314);
  ddi_4 _t316 = _igen_dd_mm256_mul_pd(_t310, s6116);
  ddi_4 _t317 = _igen_dd_mm256_mul_pd(_t315, s6120);
  s6280 = _igen_dd_mm256_sub_pd(_t316, _t317);
  dd_I _t318 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t319 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t320 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t321 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t322 = _igen_dd_mm256_set_pd(_t318, _t319, _t320, _t321);
  dd_I _t323 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t324 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t325 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t326 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t327 = _igen_dd_mm256_set_pd(_t323, _t324, _t325, _t326);
  ddi_4 _t328 = _igen_dd_mm256_mul_pd(_t322, s6116);
  ddi_4 _t329 = _igen_dd_mm256_mul_pd(_t327, s6120);
  s6281 = _igen_dd_mm256_add_pd(_t328, _t329);
  dd_I _t330 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t331 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t332 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t333 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t334 = _ia_neg_dd(_t330);
  dd_I _t335 = _ia_neg_dd(_t331);
  dd_I _t336 = _ia_neg_dd(_t332);
  dd_I _t337 = _ia_neg_dd(_t333);
  ddi_4 _t338 = _igen_dd_mm256_set_pd(_t334, _t335, _t336, _t337);
  dd_I _t339 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t340 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t341 = _ia_neg_dd(_t339);
  dd_I _t342 = _ia_neg_dd(_t340);
  dd_I _t343 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t344 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t345 = _igen_dd_mm256_set_pd(_t341, _t342, _t343, _t344);
  ddi_4 _t346 = _igen_dd_mm256_mul_pd(_t338, s6216);
  ddi_4 _t347 = _igen_dd_mm256_mul_pd(_t345, s6220);
  s6282 = _igen_dd_mm256_sub_pd(_t346, _t347);
  dd_I _t348 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t349 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t350 = _ia_neg_dd(_t348);
  dd_I _t351 = _ia_neg_dd(_t349);
  dd_I _t352 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t353 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t354 = _igen_dd_mm256_set_pd(_t350, _t351, _t352, _t353);
  dd_I _t355 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t356 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t357 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t358 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t359 = _ia_neg_dd(_t355);
  dd_I _t360 = _ia_neg_dd(_t356);
  dd_I _t361 = _ia_neg_dd(_t357);
  dd_I _t362 = _ia_neg_dd(_t358);
  ddi_4 _t363 = _igen_dd_mm256_set_pd(_t359, _t360, _t361, _t362);
  ddi_4 _t364 = _igen_dd_mm256_mul_pd(_t354, s6216);
  ddi_4 _t365 = _igen_dd_mm256_mul_pd(_t363, s6220);
  s6283 = _igen_dd_mm256_add_pd(_t364, _t365);
  t4844 = _igen_dd_mm256_add_pd(s6280, s6282);
  t4845 = _igen_dd_mm256_add_pd(s6281, s6283);
  t4846 = _igen_dd_mm256_sub_pd(s6280, s6282);
  t4847 = _igen_dd_mm256_sub_pd(s6281, s6283);
  dd_I _t366 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t367 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t368 = _ia_neg_dd(_t366);
  dd_I _t369 = _ia_neg_dd(_t367);
  dd_I _t370 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t371 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t372 = _igen_dd_mm256_set_pd(_t368, _t369, _t370, _t371);
  dd_I _t373 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t374 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t375 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t376 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t377 = _igen_dd_mm256_set_pd(_t373, _t374, _t375, _t376);
  ddi_4 _t378 = _igen_dd_mm256_mul_pd(_t372, s6117);
  ddi_4 _t379 = _igen_dd_mm256_mul_pd(_t377, s6121);
  s6284 = _igen_dd_mm256_sub_pd(_t378, _t379);
  dd_I _t380 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t381 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t382 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t383 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t384 = _igen_dd_mm256_set_pd(_t380, _t381, _t382, _t383);
  dd_I _t385 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t386 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t387 = _ia_neg_dd(_t385);
  dd_I _t388 = _ia_neg_dd(_t386);
  dd_I _t389 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t390 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t391 = _igen_dd_mm256_set_pd(_t387, _t388, _t389, _t390);
  ddi_4 _t392 = _igen_dd_mm256_mul_pd(_t384, s6117);
  ddi_4 _t393 = _igen_dd_mm256_mul_pd(_t391, s6121);
  s6285 = _igen_dd_mm256_add_pd(_t392, _t393);
  dd_I _t394 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t395 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t396 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t397 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t398 = _ia_neg_dd(_t394);
  dd_I _t399 = _ia_neg_dd(_t395);
  dd_I _t400 = _ia_neg_dd(_t396);
  ddi_4 _t401 = _igen_dd_mm256_set_pd(_t397, _t398, _t399, _t400);
  dd_I _t402 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t403 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t404 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t405 = _ia_neg_dd(_t402);
  dd_I _t406 = _ia_neg_dd(_t403);
  dd_I _t407 = _ia_neg_dd(_t404);
  dd_I _t408 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t409 = _igen_dd_mm256_set_pd(_t405, _t406, _t407, _t408);
  ddi_4 _t410 = _igen_dd_mm256_mul_pd(_t401, s6217);
  ddi_4 _t411 = _igen_dd_mm256_mul_pd(_t409, s6221);
  s6286 = _igen_dd_mm256_sub_pd(_t410, _t411);
  dd_I _t412 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t413 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t414 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t415 = _ia_neg_dd(_t412);
  dd_I _t416 = _ia_neg_dd(_t413);
  dd_I _t417 = _ia_neg_dd(_t414);
  dd_I _t418 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t419 = _igen_dd_mm256_set_pd(_t415, _t416, _t417, _t418);
  dd_I _t420 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t421 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t422 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t423 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t424 = _ia_neg_dd(_t420);
  dd_I _t425 = _ia_neg_dd(_t421);
  dd_I _t426 = _ia_neg_dd(_t422);
  ddi_4 _t427 = _igen_dd_mm256_set_pd(_t423, _t424, _t425, _t426);
  ddi_4 _t428 = _igen_dd_mm256_mul_pd(_t419, s6217);
  ddi_4 _t429 = _igen_dd_mm256_mul_pd(_t427, s6221);
  s6287 = _igen_dd_mm256_add_pd(_t428, _t429);
  t4848 = _igen_dd_mm256_add_pd(s6284, s6286);
  t4849 = _igen_dd_mm256_add_pd(s6285, s6287);
  dd_I _t430 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t431 = _ia_neg_dd(_t430);
  ddi_4 _t432 = _igen_dd_mm256_set1_pd(_t431);
  ddi_4 _t433 = _igen_dd_mm256_sub_pd(s6284, s6286);
  a1484 = _igen_dd_mm256_mul_pd(_t432, _t433);
  dd_I _t434 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t435 = _igen_dd_mm256_set1_pd(_t434);
  ddi_4 _t436 = _igen_dd_mm256_sub_pd(s6285, s6287);
  a1485 = _igen_dd_mm256_mul_pd(_t435, _t436);
  s6288 = _igen_dd_mm256_sub_pd(a1484, a1485);
  s6289 = _igen_dd_mm256_add_pd(a1484, a1485);
  t4850 = _igen_dd_mm256_add_pd(t4836, t4844);
  t4851 = _igen_dd_mm256_add_pd(t4837, t4845);
  t4852 = _igen_dd_mm256_sub_pd(t4836, t4844);
  t4853 = _igen_dd_mm256_sub_pd(t4837, t4845);
  t4854 = _igen_dd_mm256_add_pd(t4840, t4848);
  t4855 = _igen_dd_mm256_add_pd(t4841, t4849);
  t4856 = _igen_dd_mm256_sub_pd(t4840, t4848);
  t4857 = _igen_dd_mm256_sub_pd(t4841, t4849);
  t4858 = _igen_dd_mm256_add_pd(t4850, t4854);
  t4859 = _igen_dd_mm256_add_pd(t4851, t4855);
  t4860 = _igen_dd_mm256_sub_pd(t4850, t4854);
  t4861 = _igen_dd_mm256_sub_pd(t4851, t4855);
  s6290 = _igen_dd_mm256_unpacklo_pd(t4858, t4859);
  s6291 = _igen_dd_mm256_unpackhi_pd(t4858, t4859);
  s6292 = _igen_dd_mm256_permute2f128_pd(s6290, s6291, (0) | ((2) << 4));
  *((a1483 + 2)) = s6292;
  s6293 = _igen_dd_mm256_permute2f128_pd(s6290, s6291, (1) | ((3) << 4));
  *((a1483 + 3)) = s6293;
  s6294 = _igen_dd_mm256_unpacklo_pd(t4860, t4861);
  s6295 = _igen_dd_mm256_unpackhi_pd(t4860, t4861);
  s6296 = _igen_dd_mm256_permute2f128_pd(s6294, s6295, (0) | ((2) << 4));
  *((a1483 + 18)) = s6296;
  s6297 = _igen_dd_mm256_permute2f128_pd(s6294, s6295, (1) | ((3) << 4));
  *((a1483 + 19)) = s6297;
  t4862 = _igen_dd_mm256_sub_pd(t4852, t4857);
  t4863 = _igen_dd_mm256_add_pd(t4853, t4856);
  t4864 = _igen_dd_mm256_add_pd(t4852, t4857);
  t4865 = _igen_dd_mm256_sub_pd(t4853, t4856);
  s6298 = _igen_dd_mm256_unpacklo_pd(t4862, t4863);
  s6299 = _igen_dd_mm256_unpackhi_pd(t4862, t4863);
  s6300 = _igen_dd_mm256_permute2f128_pd(s6298, s6299, (0) | ((2) << 4));
  *((a1483 + 10)) = s6300;
  s6301 = _igen_dd_mm256_permute2f128_pd(s6298, s6299, (1) | ((3) << 4));
  *((a1483 + 11)) = s6301;
  s6302 = _igen_dd_mm256_unpacklo_pd(t4864, t4865);
  s6303 = _igen_dd_mm256_unpackhi_pd(t4864, t4865);
  s6304 = _igen_dd_mm256_permute2f128_pd(s6302, s6303, (0) | ((2) << 4));
  *((a1483 + 26)) = s6304;
  s6305 = _igen_dd_mm256_permute2f128_pd(s6302, s6303, (1) | ((3) << 4));
  *((a1483 + 27)) = s6305;
  t4866 = _igen_dd_mm256_sub_pd(t4838, t4847);
  t4867 = _igen_dd_mm256_add_pd(t4839, t4846);
  t4868 = _igen_dd_mm256_add_pd(t4838, t4847);
  t4869 = _igen_dd_mm256_sub_pd(t4839, t4846);
  t4870 = _igen_dd_mm256_add_pd(s6278, s6288);
  t4871 = _igen_dd_mm256_sub_pd(s6279, s6289);
  t4872 = _igen_dd_mm256_sub_pd(s6278, s6288);
  t4873 = _igen_dd_mm256_add_pd(s6279, s6289);
  t4874 = _igen_dd_mm256_add_pd(t4866, t4870);
  t4875 = _igen_dd_mm256_add_pd(t4867, t4871);
  t4876 = _igen_dd_mm256_sub_pd(t4866, t4870);
  t4877 = _igen_dd_mm256_sub_pd(t4867, t4871);
  s6306 = _igen_dd_mm256_unpacklo_pd(t4874, t4875);
  s6307 = _igen_dd_mm256_unpackhi_pd(t4874, t4875);
  s6308 = _igen_dd_mm256_permute2f128_pd(s6306, s6307, (0) | ((2) << 4));
  *((a1483 + 6)) = s6308;
  s6309 = _igen_dd_mm256_permute2f128_pd(s6306, s6307, (1) | ((3) << 4));
  *((a1483 + 7)) = s6309;
  s6310 = _igen_dd_mm256_unpacklo_pd(t4876, t4877);
  s6311 = _igen_dd_mm256_unpackhi_pd(t4876, t4877);
  s6312 = _igen_dd_mm256_permute2f128_pd(s6310, s6311, (0) | ((2) << 4));
  *((a1483 + 22)) = s6312;
  s6313 = _igen_dd_mm256_permute2f128_pd(s6310, s6311, (1) | ((3) << 4));
  *((a1483 + 23)) = s6313;
  t4878 = _igen_dd_mm256_sub_pd(t4868, t4873);
  t4879 = _igen_dd_mm256_add_pd(t4869, t4872);
  t4880 = _igen_dd_mm256_add_pd(t4868, t4873);
  t4881 = _igen_dd_mm256_sub_pd(t4869, t4872);
  s6314 = _igen_dd_mm256_unpacklo_pd(t4878, t4879);
  s6315 = _igen_dd_mm256_unpackhi_pd(t4878, t4879);
  s6316 = _igen_dd_mm256_permute2f128_pd(s6314, s6315, (0) | ((2) << 4));
  *((a1483 + 14)) = s6316;
  s6317 = _igen_dd_mm256_permute2f128_pd(s6314, s6315, (1) | ((3) << 4));
  *((a1483 + 15)) = s6317;
  s6318 = _igen_dd_mm256_unpacklo_pd(t4880, t4881);
  s6319 = _igen_dd_mm256_unpackhi_pd(t4880, t4881);
  s6320 = _igen_dd_mm256_permute2f128_pd(s6318, s6319, (0) | ((2) << 4));
  *((a1483 + 30)) = s6320;
  s6321 = _igen_dd_mm256_permute2f128_pd(s6318, s6319, (1) | ((3) << 4));
  *((a1483 + 31)) = s6321;
}
