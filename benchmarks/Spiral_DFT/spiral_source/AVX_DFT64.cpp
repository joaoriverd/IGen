#include <immintrin.h>

void init_AVX_DFT64(double a) {
}

void AVX_DFT64(double  *Y, double  *X) {
    __m256d a1477, a1478, a1479, a1480, a1481, a1482, a1484, a1485
    , s6022, s6023, s6024, s6025, s6026, s6027, s6028, s6029
    , s6030, s6031, s6032, s6033, s6034, s6035, s6036, s6037
    , s6038, s6039, s6040, s6041, s6042, s6043, s6044, s6045
    , s6046, s6047, s6048, s6049, s6050, s6051, s6052, s6053
    , s6054, s6055, s6056, s6057, s6058, s6059, s6060, s6061
    , s6062, s6063, s6064, s6065, s6066, s6067, s6068, s6069
    , s6070, s6071, s6072, s6073, s6074, s6075, s6076, s6077
    , s6078, s6079, s6080, s6081, s6082, s6083, s6084, s6085
    , s6086, s6087, s6088, s6089, s6090, s6091, s6092, s6093
    , s6094, s6095, s6096, s6097, s6098, s6099, s6100, s6101
    , s6102, s6103, s6104, s6105, s6106, s6107, s6108, s6109
    , s6110, s6111, s6112, s6113, s6114, s6115, s6116, s6117
    , s6118, s6119, s6120, s6121, s6122, s6123, s6124, s6125
    , s6126, s6127, s6128, s6129, s6130, s6131, s6132, s6133
    , s6134, s6135, s6136, s6137, s6138, s6139, s6140, s6141
    , s6142, s6143, s6144, s6145, s6146, s6147, s6148, s6149
    , s6150, s6151, s6152, s6153, s6154, s6155, s6156, s6157
    , s6158, s6159, s6160, s6161, s6162, s6163, s6164, s6165
    , s6166, s6167, s6168, s6169, s6170, s6171, s6172, s6173
    , s6174, s6175, s6176, s6177, s6178, s6179, s6180, s6181
    , s6182, s6183, s6184, s6185, s6186, s6187, s6188, s6189
    , s6190, s6191, s6192, s6193, s6194, s6195, s6196, s6197
    , s6198, s6199, s6200, s6201, s6202, s6203, s6204, s6205
    , s6206, s6207, s6208, s6209, s6210, s6211, s6212, s6213
    , s6214, s6215, s6216, s6217, s6218, s6219, s6220, s6221
    , s6222, s6223, s6224, s6225, s6226, s6227, s6228, s6229
    , s6230, s6231, s6232, s6233, s6234, s6235, s6236, s6237
    , s6238, s6239, s6240, s6241, s6242, s6243, s6244, s6245
    , s6246, s6247, s6248, s6249, s6250, s6251, s6252, s6253
    , s6254, s6255, s6256, s6257, s6258, s6259, s6260, s6261
    , s6262, s6263, s6264, s6265, s6266, s6267, s6268, s6269
    , s6270, s6271, s6272, s6273, s6274, s6275, s6276, s6277
    , s6278, s6279, s6280, s6281, s6282, s6283, s6284, s6285
    , s6286, s6287, s6288, s6289, s6290, s6291, s6292, s6293
    , s6294, s6295, s6296, s6297, s6298, s6299, s6300, s6301
    , s6302, s6303, s6304, s6305, s6306, s6307, s6308, s6309
    , s6310, s6311, s6312, s6313, s6314, s6315, s6316, s6317
    , s6318, s6319, s6320, s6321, t4698, t4699, t4700, t4701
    , t4702, t4703, t4704, t4705, t4706, t4707, t4708, t4709
    , t4710, t4711, t4712, t4713, t4714, t4715, t4716, t4717
    , t4718, t4719, t4720, t4721, t4722, t4723, t4724, t4725
    , t4726, t4727, t4728, t4729, t4730, t4731, t4732, t4733
    , t4734, t4735, t4736, t4737, t4738, t4739, t4740, t4741
    , t4742, t4743, t4744, t4745, t4746, t4747, t4748, t4749
    , t4750, t4751, t4752, t4753, t4754, t4755, t4756, t4757
    , t4758, t4759, t4760, t4761, t4762, t4763, t4764, t4765
    , t4766, t4767, t4768, t4769, t4770, t4771, t4772, t4773
    , t4774, t4775, t4776, t4777, t4778, t4779, t4780, t4781
    , t4782, t4783, t4784, t4785, t4786, t4787, t4788, t4789
    , t4790, t4791, t4792, t4793, t4794, t4795, t4796, t4797
    , t4798, t4799, t4800, t4801, t4802, t4803, t4804, t4805
    , t4806, t4807, t4808, t4809, t4810, t4811, t4812, t4813
    , t4814, t4815, t4816, t4817, t4818, t4819, t4820, t4821
    , t4822, t4823, t4824, t4825, t4826, t4827, t4828, t4829
    , t4830, t4831, t4832, t4833, t4834, t4835, t4836, t4837
    , t4838, t4839, t4840, t4841, t4842, t4843, t4844, t4845
    , t4846, t4847, t4848, t4849, t4850, t4851, t4852, t4853
    , t4854, t4855, t4856, t4857, t4858, t4859, t4860, t4861
    , t4862, t4863, t4864, t4865, t4866, t4867, t4868, t4869
    , t4870, t4871, t4872, t4873, t4874, t4875, t4876, t4877
    , t4878, t4879, t4880, t4881;
    __m256d  *a1476, *a1483;
    a1476 = ((__m256d  *) X);
    s6022 = *(a1476);
    s6023 = *((a1476 + 1));
    s6024 = _mm256_permute2f128_pd(s6022, s6023, (0) | ((2) << 4));
    s6025 = _mm256_permute2f128_pd(s6022, s6023, (1) | ((3) << 4));
    s6026 = _mm256_unpacklo_pd(s6024, s6025);
    s6027 = _mm256_unpackhi_pd(s6024, s6025);
    s6028 = *((a1476 + 16));
    s6029 = *((a1476 + 17));
    s6030 = _mm256_permute2f128_pd(s6028, s6029, (0) | ((2) << 4));
    s6031 = _mm256_permute2f128_pd(s6028, s6029, (1) | ((3) << 4));
    s6032 = _mm256_unpacklo_pd(s6030, s6031);
    s6033 = _mm256_unpackhi_pd(s6030, s6031);
    t4698 = _mm256_add_pd(s6026, s6032);
    t4699 = _mm256_add_pd(s6027, s6033);
    t4700 = _mm256_sub_pd(s6026, s6032);
    t4701 = _mm256_sub_pd(s6027, s6033);
    s6034 = *((a1476 + 8));
    s6035 = *((a1476 + 9));
    s6036 = _mm256_permute2f128_pd(s6034, s6035, (0) | ((2) << 4));
    s6037 = _mm256_permute2f128_pd(s6034, s6035, (1) | ((3) << 4));
    s6038 = _mm256_unpacklo_pd(s6036, s6037);
    s6039 = _mm256_unpackhi_pd(s6036, s6037);
    s6040 = *((a1476 + 24));
    s6041 = *((a1476 + 25));
    s6042 = _mm256_permute2f128_pd(s6040, s6041, (0) | ((2) << 4));
    s6043 = _mm256_permute2f128_pd(s6040, s6041, (1) | ((3) << 4));
    s6044 = _mm256_unpacklo_pd(s6042, s6043);
    s6045 = _mm256_unpackhi_pd(s6042, s6043);
    t4702 = _mm256_add_pd(s6038, s6044);
    t4703 = _mm256_add_pd(s6039, s6045);
    t4704 = _mm256_sub_pd(s6038, s6044);
    t4705 = _mm256_sub_pd(s6039, s6045);
    t4706 = _mm256_add_pd(t4698, t4702);
    t4707 = _mm256_add_pd(t4699, t4703);
    t4708 = _mm256_sub_pd(t4698, t4702);
    t4709 = _mm256_sub_pd(t4699, t4703);
    t4710 = _mm256_sub_pd(t4700, t4705);
    t4711 = _mm256_add_pd(t4701, t4704);
    t4712 = _mm256_add_pd(t4700, t4705);
    t4713 = _mm256_sub_pd(t4701, t4704);
    s6046 = *((a1476 + 4));
    s6047 = *((a1476 + 5));
    s6048 = _mm256_permute2f128_pd(s6046, s6047, (0) | ((2) << 4));
    s6049 = _mm256_permute2f128_pd(s6046, s6047, (1) | ((3) << 4));
    s6050 = _mm256_unpacklo_pd(s6048, s6049);
    s6051 = _mm256_unpackhi_pd(s6048, s6049);
    s6052 = *((a1476 + 20));
    s6053 = *((a1476 + 21));
    s6054 = _mm256_permute2f128_pd(s6052, s6053, (0) | ((2) << 4));
    s6055 = _mm256_permute2f128_pd(s6052, s6053, (1) | ((3) << 4));
    s6056 = _mm256_unpacklo_pd(s6054, s6055);
    s6057 = _mm256_unpackhi_pd(s6054, s6055);
    t4714 = _mm256_add_pd(s6050, s6056);
    t4715 = _mm256_add_pd(s6051, s6057);
    t4716 = _mm256_sub_pd(s6050, s6056);
    t4717 = _mm256_sub_pd(s6051, s6057);
    s6058 = *((a1476 + 12));
    s6059 = *((a1476 + 13));
    s6060 = _mm256_permute2f128_pd(s6058, s6059, (0) | ((2) << 4));
    s6061 = _mm256_permute2f128_pd(s6058, s6059, (1) | ((3) << 4));
    s6062 = _mm256_unpacklo_pd(s6060, s6061);
    s6063 = _mm256_unpackhi_pd(s6060, s6061);
    s6064 = *((a1476 + 28));
    s6065 = *((a1476 + 29));
    s6066 = _mm256_permute2f128_pd(s6064, s6065, (0) | ((2) << 4));
    s6067 = _mm256_permute2f128_pd(s6064, s6065, (1) | ((3) << 4));
    s6068 = _mm256_unpacklo_pd(s6066, s6067);
    s6069 = _mm256_unpackhi_pd(s6066, s6067);
    t4718 = _mm256_add_pd(s6062, s6068);
    t4719 = _mm256_add_pd(s6063, s6069);
    t4720 = _mm256_sub_pd(s6062, s6068);
    t4721 = _mm256_sub_pd(s6063, s6069);
    t4722 = _mm256_add_pd(t4714, t4718);
    t4723 = _mm256_add_pd(t4715, t4719);
    t4724 = _mm256_sub_pd(t4714, t4718);
    t4725 = _mm256_sub_pd(t4715, t4719);
    t4726 = _mm256_sub_pd(t4716, t4721);
    t4727 = _mm256_add_pd(t4717, t4720);
    s6070 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(t4726, t4727));
    s6071 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_add_pd(t4726, t4727));
    a1477 = _mm256_mul_pd(_mm256_set1_pd((-0.70710678118654757)), _mm256_add_pd(t4716, t4721));
    a1478 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(t4717, t4720));
    s6072 = _mm256_sub_pd(a1477, a1478);
    s6073 = _mm256_add_pd(a1477, a1478);
    t4728 = _mm256_add_pd(t4706, t4722);
    t4729 = _mm256_add_pd(t4707, t4723);
    t4730 = _mm256_sub_pd(t4706, t4722);
    t4731 = _mm256_sub_pd(t4707, t4723);
    t4732 = _mm256_add_pd(t4710, s6070);
    t4733 = _mm256_add_pd(t4711, s6071);
    t4734 = _mm256_sub_pd(t4710, s6070);
    t4735 = _mm256_sub_pd(t4711, s6071);
    t4736 = _mm256_sub_pd(t4708, t4725);
    t4737 = _mm256_add_pd(t4709, t4724);
    t4738 = _mm256_add_pd(t4708, t4725);
    t4739 = _mm256_sub_pd(t4709, t4724);
    t4740 = _mm256_add_pd(t4712, s6072);
    t4741 = _mm256_sub_pd(t4713, s6073);
    t4742 = _mm256_sub_pd(t4712, s6072);
    t4743 = _mm256_add_pd(t4713, s6073);
    s6074 = _mm256_unpacklo_pd(t4728, t4732);
    s6075 = _mm256_unpackhi_pd(t4728, t4732);
    s6076 = _mm256_unpacklo_pd(t4729, t4733);
    s6077 = _mm256_unpackhi_pd(t4729, t4733);
    s6078 = _mm256_permute2f128_pd(s6074, s6075, (0) | ((2) << 4));
    s6079 = _mm256_permute2f128_pd(s6074, s6075, (1) | ((3) << 4));
    s6080 = _mm256_permute2f128_pd(s6076, s6077, (0) | ((2) << 4));
    s6081 = _mm256_permute2f128_pd(s6076, s6077, (1) | ((3) << 4));
    s6082 = _mm256_unpacklo_pd(t4736, t4740);
    s6083 = _mm256_unpackhi_pd(t4736, t4740);
    s6084 = _mm256_unpacklo_pd(t4737, t4741);
    s6085 = _mm256_unpackhi_pd(t4737, t4741);
    s6086 = _mm256_permute2f128_pd(s6082, s6083, (0) | ((2) << 4));
    s6087 = _mm256_permute2f128_pd(s6082, s6083, (1) | ((3) << 4));
    s6088 = _mm256_permute2f128_pd(s6084, s6085, (0) | ((2) << 4));
    s6089 = _mm256_permute2f128_pd(s6084, s6085, (1) | ((3) << 4));
    s6090 = _mm256_permute2f128_pd(s6078, s6086, (0) | ((2) << 4));
    s6091 = _mm256_permute2f128_pd(s6078, s6086, (1) | ((3) << 4));
    s6092 = _mm256_permute2f128_pd(s6079, s6087, (0) | ((2) << 4));
    s6093 = _mm256_permute2f128_pd(s6079, s6087, (1) | ((3) << 4));
    s6094 = _mm256_permute2f128_pd(s6080, s6088, (0) | ((2) << 4));
    s6095 = _mm256_permute2f128_pd(s6080, s6088, (1) | ((3) << 4));
    s6096 = _mm256_permute2f128_pd(s6081, s6089, (0) | ((2) << 4));
    s6097 = _mm256_permute2f128_pd(s6081, s6089, (1) | ((3) << 4));
    s6098 = _mm256_unpacklo_pd(t4730, t4734);
    s6099 = _mm256_unpackhi_pd(t4730, t4734);
    s6100 = _mm256_unpacklo_pd(t4731, t4735);
    s6101 = _mm256_unpackhi_pd(t4731, t4735);
    s6102 = _mm256_permute2f128_pd(s6098, s6099, (0) | ((2) << 4));
    s6103 = _mm256_permute2f128_pd(s6098, s6099, (1) | ((3) << 4));
    s6104 = _mm256_permute2f128_pd(s6100, s6101, (0) | ((2) << 4));
    s6105 = _mm256_permute2f128_pd(s6100, s6101, (1) | ((3) << 4));
    s6106 = _mm256_unpacklo_pd(t4738, t4742);
    s6107 = _mm256_unpackhi_pd(t4738, t4742);
    s6108 = _mm256_unpacklo_pd(t4739, t4743);
    s6109 = _mm256_unpackhi_pd(t4739, t4743);
    s6110 = _mm256_permute2f128_pd(s6106, s6107, (0) | ((2) << 4));
    s6111 = _mm256_permute2f128_pd(s6106, s6107, (1) | ((3) << 4));
    s6112 = _mm256_permute2f128_pd(s6108, s6109, (0) | ((2) << 4));
    s6113 = _mm256_permute2f128_pd(s6108, s6109, (1) | ((3) << 4));
    s6114 = _mm256_permute2f128_pd(s6102, s6110, (0) | ((2) << 4));
    s6115 = _mm256_permute2f128_pd(s6102, s6110, (1) | ((3) << 4));
    s6116 = _mm256_permute2f128_pd(s6103, s6111, (0) | ((2) << 4));
    s6117 = _mm256_permute2f128_pd(s6103, s6111, (1) | ((3) << 4));
    s6118 = _mm256_permute2f128_pd(s6104, s6112, (0) | ((2) << 4));
    s6119 = _mm256_permute2f128_pd(s6104, s6112, (1) | ((3) << 4));
    s6120 = _mm256_permute2f128_pd(s6105, s6113, (0) | ((2) << 4));
    s6121 = _mm256_permute2f128_pd(s6105, s6113, (1) | ((3) << 4));
    s6122 = *((a1476 + 2));
    s6123 = *((a1476 + 3));
    s6124 = _mm256_permute2f128_pd(s6122, s6123, (0) | ((2) << 4));
    s6125 = _mm256_permute2f128_pd(s6122, s6123, (1) | ((3) << 4));
    s6126 = _mm256_unpacklo_pd(s6124, s6125);
    s6127 = _mm256_unpackhi_pd(s6124, s6125);
    s6128 = *((a1476 + 18));
    s6129 = *((a1476 + 19));
    s6130 = _mm256_permute2f128_pd(s6128, s6129, (0) | ((2) << 4));
    s6131 = _mm256_permute2f128_pd(s6128, s6129, (1) | ((3) << 4));
    s6132 = _mm256_unpacklo_pd(s6130, s6131);
    s6133 = _mm256_unpackhi_pd(s6130, s6131);
    t4744 = _mm256_add_pd(s6126, s6132);
    t4745 = _mm256_add_pd(s6127, s6133);
    t4746 = _mm256_sub_pd(s6126, s6132);
    t4747 = _mm256_sub_pd(s6127, s6133);
    s6134 = *((a1476 + 10));
    s6135 = *((a1476 + 11));
    s6136 = _mm256_permute2f128_pd(s6134, s6135, (0) | ((2) << 4));
    s6137 = _mm256_permute2f128_pd(s6134, s6135, (1) | ((3) << 4));
    s6138 = _mm256_unpacklo_pd(s6136, s6137);
    s6139 = _mm256_unpackhi_pd(s6136, s6137);
    s6140 = *((a1476 + 26));
    s6141 = *((a1476 + 27));
    s6142 = _mm256_permute2f128_pd(s6140, s6141, (0) | ((2) << 4));
    s6143 = _mm256_permute2f128_pd(s6140, s6141, (1) | ((3) << 4));
    s6144 = _mm256_unpacklo_pd(s6142, s6143);
    s6145 = _mm256_unpackhi_pd(s6142, s6143);
    t4748 = _mm256_add_pd(s6138, s6144);
    t4749 = _mm256_add_pd(s6139, s6145);
    t4750 = _mm256_sub_pd(s6138, s6144);
    t4751 = _mm256_sub_pd(s6139, s6145);
    t4752 = _mm256_add_pd(t4744, t4748);
    t4753 = _mm256_add_pd(t4745, t4749);
    t4754 = _mm256_sub_pd(t4744, t4748);
    t4755 = _mm256_sub_pd(t4745, t4749);
    t4756 = _mm256_sub_pd(t4746, t4751);
    t4757 = _mm256_add_pd(t4747, t4750);
    t4758 = _mm256_add_pd(t4746, t4751);
    t4759 = _mm256_sub_pd(t4747, t4750);
    s6146 = *((a1476 + 6));
    s6147 = *((a1476 + 7));
    s6148 = _mm256_permute2f128_pd(s6146, s6147, (0) | ((2) << 4));
    s6149 = _mm256_permute2f128_pd(s6146, s6147, (1) | ((3) << 4));
    s6150 = _mm256_unpacklo_pd(s6148, s6149);
    s6151 = _mm256_unpackhi_pd(s6148, s6149);
    s6152 = *((a1476 + 22));
    s6153 = *((a1476 + 23));
    s6154 = _mm256_permute2f128_pd(s6152, s6153, (0) | ((2) << 4));
    s6155 = _mm256_permute2f128_pd(s6152, s6153, (1) | ((3) << 4));
    s6156 = _mm256_unpacklo_pd(s6154, s6155);
    s6157 = _mm256_unpackhi_pd(s6154, s6155);
    t4760 = _mm256_add_pd(s6150, s6156);
    t4761 = _mm256_add_pd(s6151, s6157);
    t4762 = _mm256_sub_pd(s6150, s6156);
    t4763 = _mm256_sub_pd(s6151, s6157);
    s6158 = *((a1476 + 14));
    s6159 = *((a1476 + 15));
    s6160 = _mm256_permute2f128_pd(s6158, s6159, (0) | ((2) << 4));
    s6161 = _mm256_permute2f128_pd(s6158, s6159, (1) | ((3) << 4));
    s6162 = _mm256_unpacklo_pd(s6160, s6161);
    s6163 = _mm256_unpackhi_pd(s6160, s6161);
    s6164 = *((a1476 + 30));
    s6165 = *((a1476 + 31));
    s6166 = _mm256_permute2f128_pd(s6164, s6165, (0) | ((2) << 4));
    s6167 = _mm256_permute2f128_pd(s6164, s6165, (1) | ((3) << 4));
    s6168 = _mm256_unpacklo_pd(s6166, s6167);
    s6169 = _mm256_unpackhi_pd(s6166, s6167);
    t4764 = _mm256_add_pd(s6162, s6168);
    t4765 = _mm256_add_pd(s6163, s6169);
    t4766 = _mm256_sub_pd(s6162, s6168);
    t4767 = _mm256_sub_pd(s6163, s6169);
    t4768 = _mm256_add_pd(t4760, t4764);
    t4769 = _mm256_add_pd(t4761, t4765);
    t4770 = _mm256_sub_pd(t4760, t4764);
    t4771 = _mm256_sub_pd(t4761, t4765);
    t4772 = _mm256_sub_pd(t4762, t4767);
    t4773 = _mm256_add_pd(t4763, t4766);
    s6170 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(t4772, t4773));
    s6171 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_add_pd(t4772, t4773));
    a1479 = _mm256_mul_pd(_mm256_set1_pd((-0.70710678118654757)), _mm256_add_pd(t4762, t4767));
    a1480 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(t4763, t4766));
    s6172 = _mm256_sub_pd(a1479, a1480);
    s6173 = _mm256_add_pd(a1479, a1480);
    t4774 = _mm256_add_pd(t4752, t4768);
    t4775 = _mm256_add_pd(t4753, t4769);
    t4776 = _mm256_sub_pd(t4752, t4768);
    t4777 = _mm256_sub_pd(t4753, t4769);
    t4778 = _mm256_add_pd(t4756, s6170);
    t4779 = _mm256_add_pd(t4757, s6171);
    t4780 = _mm256_sub_pd(t4756, s6170);
    t4781 = _mm256_sub_pd(t4757, s6171);
    t4782 = _mm256_sub_pd(t4754, t4771);
    t4783 = _mm256_add_pd(t4755, t4770);
    t4784 = _mm256_add_pd(t4754, t4771);
    t4785 = _mm256_sub_pd(t4755, t4770);
    t4786 = _mm256_add_pd(t4758, s6172);
    t4787 = _mm256_sub_pd(t4759, s6173);
    t4788 = _mm256_sub_pd(t4758, s6172);
    t4789 = _mm256_add_pd(t4759, s6173);
    s6174 = _mm256_unpacklo_pd(t4774, t4778);
    s6175 = _mm256_unpackhi_pd(t4774, t4778);
    s6176 = _mm256_unpacklo_pd(t4775, t4779);
    s6177 = _mm256_unpackhi_pd(t4775, t4779);
    s6178 = _mm256_permute2f128_pd(s6174, s6175, (0) | ((2) << 4));
    s6179 = _mm256_permute2f128_pd(s6174, s6175, (1) | ((3) << 4));
    s6180 = _mm256_permute2f128_pd(s6176, s6177, (0) | ((2) << 4));
    s6181 = _mm256_permute2f128_pd(s6176, s6177, (1) | ((3) << 4));
    s6182 = _mm256_unpacklo_pd(t4782, t4786);
    s6183 = _mm256_unpackhi_pd(t4782, t4786);
    s6184 = _mm256_unpacklo_pd(t4783, t4787);
    s6185 = _mm256_unpackhi_pd(t4783, t4787);
    s6186 = _mm256_permute2f128_pd(s6182, s6183, (0) | ((2) << 4));
    s6187 = _mm256_permute2f128_pd(s6182, s6183, (1) | ((3) << 4));
    s6188 = _mm256_permute2f128_pd(s6184, s6185, (0) | ((2) << 4));
    s6189 = _mm256_permute2f128_pd(s6184, s6185, (1) | ((3) << 4));
    s6190 = _mm256_permute2f128_pd(s6178, s6186, (0) | ((2) << 4));
    s6191 = _mm256_permute2f128_pd(s6178, s6186, (1) | ((3) << 4));
    s6192 = _mm256_permute2f128_pd(s6179, s6187, (0) | ((2) << 4));
    s6193 = _mm256_permute2f128_pd(s6179, s6187, (1) | ((3) << 4));
    s6194 = _mm256_permute2f128_pd(s6180, s6188, (0) | ((2) << 4));
    s6195 = _mm256_permute2f128_pd(s6180, s6188, (1) | ((3) << 4));
    s6196 = _mm256_permute2f128_pd(s6181, s6189, (0) | ((2) << 4));
    s6197 = _mm256_permute2f128_pd(s6181, s6189, (1) | ((3) << 4));
    s6198 = _mm256_unpacklo_pd(t4776, t4780);
    s6199 = _mm256_unpackhi_pd(t4776, t4780);
    s6200 = _mm256_unpacklo_pd(t4777, t4781);
    s6201 = _mm256_unpackhi_pd(t4777, t4781);
    s6202 = _mm256_permute2f128_pd(s6198, s6199, (0) | ((2) << 4));
    s6203 = _mm256_permute2f128_pd(s6198, s6199, (1) | ((3) << 4));
    s6204 = _mm256_permute2f128_pd(s6200, s6201, (0) | ((2) << 4));
    s6205 = _mm256_permute2f128_pd(s6200, s6201, (1) | ((3) << 4));
    s6206 = _mm256_unpacklo_pd(t4784, t4788);
    s6207 = _mm256_unpackhi_pd(t4784, t4788);
    s6208 = _mm256_unpacklo_pd(t4785, t4789);
    s6209 = _mm256_unpackhi_pd(t4785, t4789);
    s6210 = _mm256_permute2f128_pd(s6206, s6207, (0) | ((2) << 4));
    s6211 = _mm256_permute2f128_pd(s6206, s6207, (1) | ((3) << 4));
    s6212 = _mm256_permute2f128_pd(s6208, s6209, (0) | ((2) << 4));
    s6213 = _mm256_permute2f128_pd(s6208, s6209, (1) | ((3) << 4));
    s6214 = _mm256_permute2f128_pd(s6202, s6210, (0) | ((2) << 4));
    s6215 = _mm256_permute2f128_pd(s6202, s6210, (1) | ((3) << 4));
    s6216 = _mm256_permute2f128_pd(s6203, s6211, (0) | ((2) << 4));
    s6217 = _mm256_permute2f128_pd(s6203, s6211, (1) | ((3) << 4));
    s6218 = _mm256_permute2f128_pd(s6204, s6212, (0) | ((2) << 4));
    s6219 = _mm256_permute2f128_pd(s6204, s6212, (1) | ((3) << 4));
    s6220 = _mm256_permute2f128_pd(s6205, s6213, (0) | ((2) << 4));
    s6221 = _mm256_permute2f128_pd(s6205, s6213, (1) | ((3) << 4));
    s6222 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s6190), _mm256_mul_pd(_mm256_set_pd(0.92387953251128674, 0.70710678118654757, 0.38268343236508978, 0.0), s6194));
    s6223 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.92387953251128674, 0.70710678118654757, 0.38268343236508978, 0.0), s6190), _mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s6194));
    t4790 = _mm256_add_pd(s6090, s6222);
    t4791 = _mm256_add_pd(s6094, s6223);
    t4792 = _mm256_sub_pd(s6090, s6222);
    t4793 = _mm256_sub_pd(s6094, s6223);
    s6224 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.95694033573220882, 0.98078528040323043, 0.99518472667219693, 1.0), s6091), _mm256_mul_pd(_mm256_set_pd(0.29028467725446233, 0.19509032201612825, 0.098017140329560604, 0.0), s6095));
    s6225 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.29028467725446233, 0.19509032201612825, 0.098017140329560604, 0.0), s6091), _mm256_mul_pd(_mm256_set_pd(0.95694033573220882, 0.98078528040323043, 0.99518472667219693, 1.0), s6095));
    s6226 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.098017140329560604, 0.55557023301960218, 0.88192126434835505, 1.0), s6191), _mm256_mul_pd(_mm256_set_pd(0.99518472667219693, 0.83146961230254524, 0.47139673682599764, 0.0), s6195));
    s6227 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.99518472667219693, 0.83146961230254524, 0.47139673682599764, 0.0), s6191), _mm256_mul_pd(_mm256_set_pd(0.098017140329560604, 0.55557023301960218, 0.88192126434835505, 1.0), s6195));
    t4794 = _mm256_add_pd(s6224, s6226);
    t4795 = _mm256_add_pd(s6225, s6227);
    t4796 = _mm256_sub_pd(s6224, s6226);
    t4797 = _mm256_sub_pd(s6225, s6227);
    s6228 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(t4796, t4797));
    s6229 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_add_pd(t4796, t4797));
    s6230 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.83146961230254524, 0.92387953251128674, 0.98078528040323043, 1.0), s6092), _mm256_mul_pd(_mm256_set_pd(0.55557023301960218, 0.38268343236508978, 0.19509032201612825, 0.0), s6096));
    s6231 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.55557023301960218, 0.38268343236508978, 0.19509032201612825, 0.0), s6092), _mm256_mul_pd(_mm256_set_pd(0.83146961230254524, 0.92387953251128674, 0.98078528040323043, 1.0), s6096));
    s6232 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.19509032201612825), 0.38268343236508978, 0.83146961230254524, 1.0), s6192), _mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.55557023301960218, 0.0), s6196));
    s6233 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.55557023301960218, 0.0), s6192), _mm256_mul_pd(_mm256_set_pd((-0.19509032201612825), 0.38268343236508978, 0.83146961230254524, 1.0), s6196));
    t4798 = _mm256_add_pd(s6230, s6232);
    t4799 = _mm256_add_pd(s6231, s6233);
    t4800 = _mm256_sub_pd(s6230, s6232);
    t4801 = _mm256_sub_pd(s6231, s6233);
    s6234 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.63439328416364549, 0.83146961230254524, 0.95694033573220882, 1.0), s6093), _mm256_mul_pd(_mm256_set_pd(0.77301045336273699, 0.55557023301960218, 0.29028467725446233, 0.0), s6097));
    s6235 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.77301045336273699, 0.55557023301960218, 0.29028467725446233, 0.0), s6093), _mm256_mul_pd(_mm256_set_pd(0.63439328416364549, 0.83146961230254524, 0.95694033573220882, 1.0), s6097));
    s6236 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.47139673682599764), 0.19509032201612825, 0.77301045336273699, 1.0), s6193), _mm256_mul_pd(_mm256_set_pd(0.88192126434835505, 0.98078528040323043, 0.63439328416364549, 0.0), s6197));
    s6237 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.88192126434835505, 0.98078528040323043, 0.63439328416364549, 0.0), s6193), _mm256_mul_pd(_mm256_set_pd((-0.47139673682599764), 0.19509032201612825, 0.77301045336273699, 1.0), s6197));
    t4802 = _mm256_add_pd(s6234, s6236);
    t4803 = _mm256_add_pd(s6235, s6237);
    a1481 = _mm256_mul_pd(_mm256_set1_pd((-0.70710678118654757)), _mm256_sub_pd(s6234, s6236));
    a1482 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(s6235, s6237));
    s6238 = _mm256_sub_pd(a1481, a1482);
    s6239 = _mm256_add_pd(a1481, a1482);
    t4804 = _mm256_add_pd(t4790, t4798);
    t4805 = _mm256_add_pd(t4791, t4799);
    t4806 = _mm256_sub_pd(t4790, t4798);
    t4807 = _mm256_sub_pd(t4791, t4799);
    t4808 = _mm256_add_pd(t4794, t4802);
    t4809 = _mm256_add_pd(t4795, t4803);
    t4810 = _mm256_sub_pd(t4794, t4802);
    t4811 = _mm256_sub_pd(t4795, t4803);
    t4812 = _mm256_add_pd(t4804, t4808);
    t4813 = _mm256_add_pd(t4805, t4809);
    t4814 = _mm256_sub_pd(t4804, t4808);
    t4815 = _mm256_sub_pd(t4805, t4809);
    s6240 = _mm256_unpacklo_pd(t4812, t4813);
    s6241 = _mm256_unpackhi_pd(t4812, t4813);
    a1483 = ((__m256d  *) Y);
    s6242 = _mm256_permute2f128_pd(s6240, s6241, (0) | ((2) << 4));
    *(a1483) = s6242;
    s6243 = _mm256_permute2f128_pd(s6240, s6241, (1) | ((3) << 4));
    *((a1483 + 1)) = s6243;
    s6244 = _mm256_unpacklo_pd(t4814, t4815);
    s6245 = _mm256_unpackhi_pd(t4814, t4815);
    s6246 = _mm256_permute2f128_pd(s6244, s6245, (0) | ((2) << 4));
    *((a1483 + 16)) = s6246;
    s6247 = _mm256_permute2f128_pd(s6244, s6245, (1) | ((3) << 4));
    *((a1483 + 17)) = s6247;
    t4816 = _mm256_sub_pd(t4806, t4811);
    t4817 = _mm256_add_pd(t4807, t4810);
    t4818 = _mm256_add_pd(t4806, t4811);
    t4819 = _mm256_sub_pd(t4807, t4810);
    s6248 = _mm256_unpacklo_pd(t4816, t4817);
    s6249 = _mm256_unpackhi_pd(t4816, t4817);
    s6250 = _mm256_permute2f128_pd(s6248, s6249, (0) | ((2) << 4));
    *((a1483 + 8)) = s6250;
    s6251 = _mm256_permute2f128_pd(s6248, s6249, (1) | ((3) << 4));
    *((a1483 + 9)) = s6251;
    s6252 = _mm256_unpacklo_pd(t4818, t4819);
    s6253 = _mm256_unpackhi_pd(t4818, t4819);
    s6254 = _mm256_permute2f128_pd(s6252, s6253, (0) | ((2) << 4));
    *((a1483 + 24)) = s6254;
    s6255 = _mm256_permute2f128_pd(s6252, s6253, (1) | ((3) << 4));
    *((a1483 + 25)) = s6255;
    t4820 = _mm256_sub_pd(t4792, t4801);
    t4821 = _mm256_add_pd(t4793, t4800);
    t4822 = _mm256_add_pd(t4792, t4801);
    t4823 = _mm256_sub_pd(t4793, t4800);
    t4824 = _mm256_add_pd(s6228, s6238);
    t4825 = _mm256_sub_pd(s6229, s6239);
    t4826 = _mm256_sub_pd(s6228, s6238);
    t4827 = _mm256_add_pd(s6229, s6239);
    t4828 = _mm256_add_pd(t4820, t4824);
    t4829 = _mm256_add_pd(t4821, t4825);
    t4830 = _mm256_sub_pd(t4820, t4824);
    t4831 = _mm256_sub_pd(t4821, t4825);
    s6256 = _mm256_unpacklo_pd(t4828, t4829);
    s6257 = _mm256_unpackhi_pd(t4828, t4829);
    s6258 = _mm256_permute2f128_pd(s6256, s6257, (0) | ((2) << 4));
    *((a1483 + 4)) = s6258;
    s6259 = _mm256_permute2f128_pd(s6256, s6257, (1) | ((3) << 4));
    *((a1483 + 5)) = s6259;
    s6260 = _mm256_unpacklo_pd(t4830, t4831);
    s6261 = _mm256_unpackhi_pd(t4830, t4831);
    s6262 = _mm256_permute2f128_pd(s6260, s6261, (0) | ((2) << 4));
    *((a1483 + 20)) = s6262;
    s6263 = _mm256_permute2f128_pd(s6260, s6261, (1) | ((3) << 4));
    *((a1483 + 21)) = s6263;
    t4832 = _mm256_sub_pd(t4822, t4827);
    t4833 = _mm256_add_pd(t4823, t4826);
    t4834 = _mm256_add_pd(t4822, t4827);
    t4835 = _mm256_sub_pd(t4823, t4826);
    s6264 = _mm256_unpacklo_pd(t4832, t4833);
    s6265 = _mm256_unpackhi_pd(t4832, t4833);
    s6266 = _mm256_permute2f128_pd(s6264, s6265, (0) | ((2) << 4));
    *((a1483 + 12)) = s6266;
    s6267 = _mm256_permute2f128_pd(s6264, s6265, (1) | ((3) << 4));
    *((a1483 + 13)) = s6267;
    s6268 = _mm256_unpacklo_pd(t4834, t4835);
    s6269 = _mm256_unpackhi_pd(t4834, t4835);
    s6270 = _mm256_permute2f128_pd(s6268, s6269, (0) | ((2) << 4));
    *((a1483 + 28)) = s6270;
    s6271 = _mm256_permute2f128_pd(s6268, s6269, (1) | ((3) << 4));
    *((a1483 + 29)) = s6271;
    s6272 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.92387953251128674), (-0.70710678118654757), (-0.38268343236508978), 0.0), s6214), _mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s6218));
    s6273 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s6214), _mm256_mul_pd(_mm256_set_pd((-0.92387953251128674), (-0.70710678118654757), (-0.38268343236508978), 0.0), s6218));
    t4836 = _mm256_add_pd(s6114, s6272);
    t4837 = _mm256_add_pd(s6118, s6273);
    t4838 = _mm256_sub_pd(s6114, s6272);
    t4839 = _mm256_sub_pd(s6118, s6273);
    s6274 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.77301045336273699, 0.83146961230254524, 0.88192126434835505, 0.92387953251128674), s6115), _mm256_mul_pd(_mm256_set_pd(0.63439328416364549, 0.55557023301960218, 0.47139673682599764, 0.38268343236508978), s6119));
    s6275 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.63439328416364549, 0.55557023301960218, 0.47139673682599764, 0.38268343236508978), s6115), _mm256_mul_pd(_mm256_set_pd(0.77301045336273699, 0.83146961230254524, 0.88192126434835505, 0.92387953251128674), s6119));
    s6276 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.95694033573220882), (-0.98078528040323043), (-0.77301045336273699), (-0.38268343236508978)), s6215), _mm256_mul_pd(_mm256_set_pd((-0.29028467725446233), 0.19509032201612825, 0.63439328416364549, 0.92387953251128674), s6219));
    s6277 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd((-0.29028467725446233), 0.19509032201612825, 0.63439328416364549, 0.92387953251128674), s6215), _mm256_mul_pd(_mm256_set_pd((-0.95694033573220882), (-0.98078528040323043), (-0.77301045336273699), (-0.38268343236508978)), s6219));
    t4840 = _mm256_add_pd(s6274, s6276);
    t4841 = _mm256_add_pd(s6275, s6277);
    t4842 = _mm256_sub_pd(s6274, s6276);
    t4843 = _mm256_sub_pd(s6275, s6277);
    s6278 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(t4842, t4843));
    s6279 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_add_pd(t4842, t4843));
    s6280 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.19509032201612825, 0.38268343236508978, 0.55557023301960218, 0.70710678118654757), s6116), _mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.83146961230254524, 0.70710678118654757), s6120));
    s6281 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.83146961230254524, 0.70710678118654757), s6116), _mm256_mul_pd(_mm256_set_pd(0.19509032201612825, 0.38268343236508978, 0.55557023301960218, 0.70710678118654757), s6120));
    s6282 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.55557023301960218), (-0.92387953251128674), (-0.98078528040323043), (-0.70710678118654757)), s6216), _mm256_mul_pd(_mm256_set_pd((-0.83146961230254524), (-0.38268343236508978), 0.19509032201612825, 0.70710678118654757), s6220));
    s6283 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd((-0.83146961230254524), (-0.38268343236508978), 0.19509032201612825, 0.70710678118654757), s6216), _mm256_mul_pd(_mm256_set_pd((-0.55557023301960218), (-0.92387953251128674), (-0.98078528040323043), (-0.70710678118654757)), s6220));
    t4844 = _mm256_add_pd(s6280, s6282);
    t4845 = _mm256_add_pd(s6281, s6283);
    t4846 = _mm256_sub_pd(s6280, s6282);
    t4847 = _mm256_sub_pd(s6281, s6283);
    s6284 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.47139673682599764), (-0.19509032201612825), 0.098017140329560604, 0.38268343236508978), s6117), _mm256_mul_pd(_mm256_set_pd(0.88192126434835505, 0.98078528040323043, 0.99518472667219693, 0.92387953251128674), s6121));
    s6285 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.88192126434835505, 0.98078528040323043, 0.99518472667219693, 0.92387953251128674), s6117), _mm256_mul_pd(_mm256_set_pd((-0.47139673682599764), (-0.19509032201612825), 0.098017140329560604, 0.38268343236508978), s6121));
    s6286 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.098017140329560604, (-0.55557023301960218), (-0.95694033573220882), (-0.92387953251128674)), s6217), _mm256_mul_pd(_mm256_set_pd((-0.99518472667219693), (-0.83146961230254524), (-0.29028467725446233), 0.38268343236508978), s6221));
    s6287 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd((-0.99518472667219693), (-0.83146961230254524), (-0.29028467725446233), 0.38268343236508978), s6217), _mm256_mul_pd(_mm256_set_pd(0.098017140329560604, (-0.55557023301960218), (-0.95694033573220882), (-0.92387953251128674)), s6221));
    t4848 = _mm256_add_pd(s6284, s6286);
    t4849 = _mm256_add_pd(s6285, s6287);
    a1484 = _mm256_mul_pd(_mm256_set1_pd((-0.70710678118654757)), _mm256_sub_pd(s6284, s6286));
    a1485 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(s6285, s6287));
    s6288 = _mm256_sub_pd(a1484, a1485);
    s6289 = _mm256_add_pd(a1484, a1485);
    t4850 = _mm256_add_pd(t4836, t4844);
    t4851 = _mm256_add_pd(t4837, t4845);
    t4852 = _mm256_sub_pd(t4836, t4844);
    t4853 = _mm256_sub_pd(t4837, t4845);
    t4854 = _mm256_add_pd(t4840, t4848);
    t4855 = _mm256_add_pd(t4841, t4849);
    t4856 = _mm256_sub_pd(t4840, t4848);
    t4857 = _mm256_sub_pd(t4841, t4849);
    t4858 = _mm256_add_pd(t4850, t4854);
    t4859 = _mm256_add_pd(t4851, t4855);
    t4860 = _mm256_sub_pd(t4850, t4854);
    t4861 = _mm256_sub_pd(t4851, t4855);
    s6290 = _mm256_unpacklo_pd(t4858, t4859);
    s6291 = _mm256_unpackhi_pd(t4858, t4859);
    s6292 = _mm256_permute2f128_pd(s6290, s6291, (0) | ((2) << 4));
    *((a1483 + 2)) = s6292;
    s6293 = _mm256_permute2f128_pd(s6290, s6291, (1) | ((3) << 4));
    *((a1483 + 3)) = s6293;
    s6294 = _mm256_unpacklo_pd(t4860, t4861);
    s6295 = _mm256_unpackhi_pd(t4860, t4861);
    s6296 = _mm256_permute2f128_pd(s6294, s6295, (0) | ((2) << 4));
    *((a1483 + 18)) = s6296;
    s6297 = _mm256_permute2f128_pd(s6294, s6295, (1) | ((3) << 4));
    *((a1483 + 19)) = s6297;
    t4862 = _mm256_sub_pd(t4852, t4857);
    t4863 = _mm256_add_pd(t4853, t4856);
    t4864 = _mm256_add_pd(t4852, t4857);
    t4865 = _mm256_sub_pd(t4853, t4856);
    s6298 = _mm256_unpacklo_pd(t4862, t4863);
    s6299 = _mm256_unpackhi_pd(t4862, t4863);
    s6300 = _mm256_permute2f128_pd(s6298, s6299, (0) | ((2) << 4));
    *((a1483 + 10)) = s6300;
    s6301 = _mm256_permute2f128_pd(s6298, s6299, (1) | ((3) << 4));
    *((a1483 + 11)) = s6301;
    s6302 = _mm256_unpacklo_pd(t4864, t4865);
    s6303 = _mm256_unpackhi_pd(t4864, t4865);
    s6304 = _mm256_permute2f128_pd(s6302, s6303, (0) | ((2) << 4));
    *((a1483 + 26)) = s6304;
    s6305 = _mm256_permute2f128_pd(s6302, s6303, (1) | ((3) << 4));
    *((a1483 + 27)) = s6305;
    t4866 = _mm256_sub_pd(t4838, t4847);
    t4867 = _mm256_add_pd(t4839, t4846);
    t4868 = _mm256_add_pd(t4838, t4847);
    t4869 = _mm256_sub_pd(t4839, t4846);
    t4870 = _mm256_add_pd(s6278, s6288);
    t4871 = _mm256_sub_pd(s6279, s6289);
    t4872 = _mm256_sub_pd(s6278, s6288);
    t4873 = _mm256_add_pd(s6279, s6289);
    t4874 = _mm256_add_pd(t4866, t4870);
    t4875 = _mm256_add_pd(t4867, t4871);
    t4876 = _mm256_sub_pd(t4866, t4870);
    t4877 = _mm256_sub_pd(t4867, t4871);
    s6306 = _mm256_unpacklo_pd(t4874, t4875);
    s6307 = _mm256_unpackhi_pd(t4874, t4875);
    s6308 = _mm256_permute2f128_pd(s6306, s6307, (0) | ((2) << 4));
    *((a1483 + 6)) = s6308;
    s6309 = _mm256_permute2f128_pd(s6306, s6307, (1) | ((3) << 4));
    *((a1483 + 7)) = s6309;
    s6310 = _mm256_unpacklo_pd(t4876, t4877);
    s6311 = _mm256_unpackhi_pd(t4876, t4877);
    s6312 = _mm256_permute2f128_pd(s6310, s6311, (0) | ((2) << 4));
    *((a1483 + 22)) = s6312;
    s6313 = _mm256_permute2f128_pd(s6310, s6311, (1) | ((3) << 4));
    *((a1483 + 23)) = s6313;
    t4878 = _mm256_sub_pd(t4868, t4873);
    t4879 = _mm256_add_pd(t4869, t4872);
    t4880 = _mm256_add_pd(t4868, t4873);
    t4881 = _mm256_sub_pd(t4869, t4872);
    s6314 = _mm256_unpacklo_pd(t4878, t4879);
    s6315 = _mm256_unpackhi_pd(t4878, t4879);
    s6316 = _mm256_permute2f128_pd(s6314, s6315, (0) | ((2) << 4));
    *((a1483 + 14)) = s6316;
    s6317 = _mm256_permute2f128_pd(s6314, s6315, (1) | ((3) << 4));
    *((a1483 + 15)) = s6317;
    s6318 = _mm256_unpacklo_pd(t4880, t4881);
    s6319 = _mm256_unpackhi_pd(t4880, t4881);
    s6320 = _mm256_permute2f128_pd(s6318, s6319, (0) | ((2) << 4));
    *((a1483 + 30)) = s6320;
    s6321 = _mm256_permute2f128_pd(s6318, s6319, (1) | ((3) << 4));
    *((a1483 + 31)) = s6321;
}