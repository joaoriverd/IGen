#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
void init_AVX_DFT256(dd_I a) {}

void AVX_DFT256(dd_I *Y, dd_I *X) {
  ddi_4 a1283;
  ddi_4 a1284;
  ddi_4 a1285;
  ddi_4 a1286;
  ddi_4 a1287;
  ddi_4 a1288;
  ddi_4 a1289;
  ddi_4 a1290;
  ddi_4 a1291;
  ddi_4 a1292;
  ddi_4 a1293;
  ddi_4 a1294;
  ddi_4 a1295;
  ddi_4 a1296;
  ddi_4 a1297;
  ddi_4 a1298;
  ddi_4 a1299;
  ddi_4 a1300;
  ddi_4 a1301;
  ddi_4 a1302;
  ddi_4 a1303;
  ddi_4 a1304;
  ddi_4 a1305;
  ddi_4 a1306;
  ddi_4 a1307;
  ddi_4 a1308;
  ddi_4 s3878;
  ddi_4 s3879;
  ddi_4 s3880;
  ddi_4 s3881;
  ddi_4 s3882;
  ddi_4 s3883;
  ddi_4 s3884;
  ddi_4 s3885;
  ddi_4 s3886;
  ddi_4 s3887;
  ddi_4 s3888;
  ddi_4 s3889;
  ddi_4 s3890;
  ddi_4 s3891;
  ddi_4 s3892;
  ddi_4 s3893;
  ddi_4 s3894;
  ddi_4 s3895;
  ddi_4 s3896;
  ddi_4 s3897;
  ddi_4 s3898;
  ddi_4 s3899;
  ddi_4 s3900;
  ddi_4 s3901;
  ddi_4 s3902;
  ddi_4 s3903;
  ddi_4 s3904;
  ddi_4 s3905;
  ddi_4 s3906;
  ddi_4 s3907;
  ddi_4 s3908;
  ddi_4 s3909;
  ddi_4 s3910;
  ddi_4 s3911;
  ddi_4 s3912;
  ddi_4 s3913;
  ddi_4 s3914;
  ddi_4 s3915;
  ddi_4 s3916;
  ddi_4 s3917;
  ddi_4 s3918;
  ddi_4 s3919;
  ddi_4 s3920;
  ddi_4 s3921;
  ddi_4 s3922;
  ddi_4 s3923;
  ddi_4 s3924;
  ddi_4 s3925;
  ddi_4 s3926;
  ddi_4 s3927;
  ddi_4 s3928;
  ddi_4 s3929;
  ddi_4 s3930;
  ddi_4 s3931;
  ddi_4 s3932;
  ddi_4 s3933;
  ddi_4 s3934;
  ddi_4 s3935;
  ddi_4 s3936;
  ddi_4 s3937;
  ddi_4 s3938;
  ddi_4 s3939;
  ddi_4 s3940;
  ddi_4 s3941;
  ddi_4 s3942;
  ddi_4 s3943;
  ddi_4 s3944;
  ddi_4 s3945;
  ddi_4 s3946;
  ddi_4 s3947;
  ddi_4 s3948;
  ddi_4 s3949;
  ddi_4 s3950;
  ddi_4 s3951;
  ddi_4 s3952;
  ddi_4 s3953;
  ddi_4 s3954;
  ddi_4 s3955;
  ddi_4 s3956;
  ddi_4 s3957;
  ddi_4 s3958;
  ddi_4 s3959;
  ddi_4 s3960;
  ddi_4 s3961;
  ddi_4 s3962;
  ddi_4 s3963;
  ddi_4 s3964;
  ddi_4 s3965;
  ddi_4 s3966;
  ddi_4 s3967;
  ddi_4 s3968;
  ddi_4 s3969;
  ddi_4 s3970;
  ddi_4 s3971;
  ddi_4 s3972;
  ddi_4 s3973;
  ddi_4 s3974;
  ddi_4 s3975;
  ddi_4 s3976;
  ddi_4 s3977;
  ddi_4 s3978;
  ddi_4 s3979;
  ddi_4 s3980;
  ddi_4 s3981;
  ddi_4 s3982;
  ddi_4 s3983;
  ddi_4 s3984;
  ddi_4 s3985;
  ddi_4 s3986;
  ddi_4 s3987;
  ddi_4 s3988;
  ddi_4 s3989;
  ddi_4 s3990;
  ddi_4 s3991;
  ddi_4 s3992;
  ddi_4 s3993;
  ddi_4 s3994;
  ddi_4 s3995;
  ddi_4 s3996;
  ddi_4 s3997;
  ddi_4 s3998;
  ddi_4 s3999;
  ddi_4 s4000;
  ddi_4 s4001;
  ddi_4 s4002;
  ddi_4 s4003;
  ddi_4 s4004;
  ddi_4 s4005;
  ddi_4 s4006;
  ddi_4 s4007;
  ddi_4 s4008;
  ddi_4 s4009;
  ddi_4 s4010;
  ddi_4 s4011;
  ddi_4 s4012;
  ddi_4 s4013;
  ddi_4 s4014;
  ddi_4 s4015;
  ddi_4 s4016;
  ddi_4 s4017;
  ddi_4 s4018;
  ddi_4 s4019;
  ddi_4 s4020;
  ddi_4 s4021;
  ddi_4 s4022;
  ddi_4 s4023;
  ddi_4 s4024;
  ddi_4 s4025;
  ddi_4 s4026;
  ddi_4 s4027;
  ddi_4 s4028;
  ddi_4 s4029;
  ddi_4 s4030;
  ddi_4 s4031;
  ddi_4 s4032;
  ddi_4 s4033;
  ddi_4 s4034;
  ddi_4 s4035;
  ddi_4 s4036;
  ddi_4 s4037;
  ddi_4 s4038;
  ddi_4 s4039;
  ddi_4 s4040;
  ddi_4 s4041;
  ddi_4 s4042;
  ddi_4 s4043;
  ddi_4 s4044;
  ddi_4 s4045;
  ddi_4 s4046;
  ddi_4 s4047;
  ddi_4 s4048;
  ddi_4 s4049;
  ddi_4 s4050;
  ddi_4 s4051;
  ddi_4 s4052;
  ddi_4 s4053;
  ddi_4 s4054;
  ddi_4 s4055;
  ddi_4 s4056;
  ddi_4 s4057;
  ddi_4 s4058;
  ddi_4 s4059;
  ddi_4 s4060;
  ddi_4 s4061;
  ddi_4 s4062;
  ddi_4 s4063;
  ddi_4 s4064;
  ddi_4 s4065;
  ddi_4 s4066;
  ddi_4 s4067;
  ddi_4 s4068;
  ddi_4 s4069;
  ddi_4 s4070;
  ddi_4 s4071;
  ddi_4 s4072;
  ddi_4 s4073;
  ddi_4 s4074;
  ddi_4 s4075;
  ddi_4 s4076;
  ddi_4 s4077;
  ddi_4 s4078;
  ddi_4 s4079;
  ddi_4 s4080;
  ddi_4 s4081;
  ddi_4 s4082;
  ddi_4 s4083;
  ddi_4 s4084;
  ddi_4 s4085;
  ddi_4 s4086;
  ddi_4 s4087;
  ddi_4 s4088;
  ddi_4 s4089;
  ddi_4 s4090;
  ddi_4 s4091;
  ddi_4 s4092;
  ddi_4 s4093;
  ddi_4 s4094;
  ddi_4 s4095;
  ddi_4 s4096;
  ddi_4 s4097;
  ddi_4 s4098;
  ddi_4 s4099;
  ddi_4 s4100;
  ddi_4 s4101;
  ddi_4 s4102;
  ddi_4 s4103;
  ddi_4 s4104;
  ddi_4 s4105;
  ddi_4 s4106;
  ddi_4 s4107;
  ddi_4 s4108;
  ddi_4 s4109;
  ddi_4 s4110;
  ddi_4 s4111;
  ddi_4 s4112;
  ddi_4 s4113;
  ddi_4 s4114;
  ddi_4 s4115;
  ddi_4 s4116;
  ddi_4 s4117;
  ddi_4 s4118;
  ddi_4 s4119;
  ddi_4 s4120;
  ddi_4 s4121;
  ddi_4 s4122;
  ddi_4 s4123;
  ddi_4 s4124;
  ddi_4 s4125;
  ddi_4 s4126;
  ddi_4 s4127;
  ddi_4 s4128;
  ddi_4 s4129;
  ddi_4 s4130;
  ddi_4 s4131;
  ddi_4 s4132;
  ddi_4 s4133;
  ddi_4 s4134;
  ddi_4 s4135;
  ddi_4 s4136;
  ddi_4 s4137;
  ddi_4 s4138;
  ddi_4 s4139;
  ddi_4 s4140;
  ddi_4 s4141;
  ddi_4 s4142;
  ddi_4 s4143;
  ddi_4 s4144;
  ddi_4 s4145;
  ddi_4 s4146;
  ddi_4 s4147;
  ddi_4 s4148;
  ddi_4 s4149;
  ddi_4 s4150;
  ddi_4 s4151;
  ddi_4 s4152;
  ddi_4 s4153;
  ddi_4 s4154;
  ddi_4 s4155;
  ddi_4 s4156;
  ddi_4 s4157;
  ddi_4 s4158;
  ddi_4 s4159;
  ddi_4 s4160;
  ddi_4 s4161;
  ddi_4 s4162;
  ddi_4 s4163;
  ddi_4 s4164;
  ddi_4 s4165;
  ddi_4 s4166;
  ddi_4 s4167;
  ddi_4 s4168;
  ddi_4 s4169;
  ddi_4 s4170;
  ddi_4 s4171;
  ddi_4 s4172;
  ddi_4 s4173;
  ddi_4 s4174;
  ddi_4 s4175;
  ddi_4 s4176;
  ddi_4 s4177;
  ddi_4 s4178;
  ddi_4 s4179;
  ddi_4 s4180;
  ddi_4 s4181;
  ddi_4 s4182;
  ddi_4 s4183;
  ddi_4 s4184;
  ddi_4 s4185;
  ddi_4 s4186;
  ddi_4 s4187;
  ddi_4 s4188;
  ddi_4 s4189;
  ddi_4 s4190;
  ddi_4 s4191;
  ddi_4 s4192;
  ddi_4 s4193;
  ddi_4 s4194;
  ddi_4 s4195;
  ddi_4 s4196;
  ddi_4 s4197;
  ddi_4 s4198;
  ddi_4 s4199;
  ddi_4 s4200;
  ddi_4 s4201;
  ddi_4 s4202;
  ddi_4 s4203;
  ddi_4 s4204;
  ddi_4 s4205;
  ddi_4 s4206;
  ddi_4 s4207;
  ddi_4 s4208;
  ddi_4 s4209;
  ddi_4 s4210;
  ddi_4 s4211;
  ddi_4 s4212;
  ddi_4 s4213;
  ddi_4 s4214;
  ddi_4 s4215;
  ddi_4 s4216;
  ddi_4 s4217;
  ddi_4 s4218;
  ddi_4 s4219;
  ddi_4 s4220;
  ddi_4 s4221;
  ddi_4 s4222;
  ddi_4 s4223;
  ddi_4 s4224;
  ddi_4 s4225;
  ddi_4 s4226;
  ddi_4 s4227;
  ddi_4 s4228;
  ddi_4 s4229;
  ddi_4 s4230;
  ddi_4 s4231;
  ddi_4 s4232;
  ddi_4 s4233;
  ddi_4 s4234;
  ddi_4 s4235;
  ddi_4 s4236;
  ddi_4 s4237;
  ddi_4 s4238;
  ddi_4 s4239;
  ddi_4 s4240;
  ddi_4 s4241;
  ddi_4 s4242;
  ddi_4 s4243;
  ddi_4 s4244;
  ddi_4 s4245;
  ddi_4 s4246;
  ddi_4 s4247;
  ddi_4 s4248;
  ddi_4 s4249;
  ddi_4 s4250;
  ddi_4 s4251;
  ddi_4 s4252;
  ddi_4 s4253;
  ddi_4 s4254;
  ddi_4 s4255;
  ddi_4 s4256;
  ddi_4 s4257;
  ddi_4 s4258;
  ddi_4 s4259;
  ddi_4 s4260;
  ddi_4 s4261;
  ddi_4 s4262;
  ddi_4 s4263;
  ddi_4 s4264;
  ddi_4 s4265;
  ddi_4 s4266;
  ddi_4 s4267;
  ddi_4 s4268;
  ddi_4 s4269;
  ddi_4 s4270;
  ddi_4 s4271;
  ddi_4 s4272;
  ddi_4 s4273;
  ddi_4 s4274;
  ddi_4 s4275;
  ddi_4 s4276;
  ddi_4 s4277;
  ddi_4 s4278;
  ddi_4 s4279;
  ddi_4 s4280;
  ddi_4 s4281;
  ddi_4 s4282;
  ddi_4 s4283;
  ddi_4 s4284;
  ddi_4 s4285;
  ddi_4 s4286;
  ddi_4 s4287;
  ddi_4 s4288;
  ddi_4 s4289;
  ddi_4 s4290;
  ddi_4 s4291;
  ddi_4 s4292;
  ddi_4 s4293;
  ddi_4 s4294;
  ddi_4 s4295;
  ddi_4 s4296;
  ddi_4 s4297;
  ddi_4 s4298;
  ddi_4 s4299;
  ddi_4 s4300;
  ddi_4 s4301;
  ddi_4 s4302;
  ddi_4 s4303;
  ddi_4 s4304;
  ddi_4 s4305;
  ddi_4 s4306;
  ddi_4 s4307;
  ddi_4 s4308;
  ddi_4 s4309;
  ddi_4 s4310;
  ddi_4 s4311;
  ddi_4 s4312;
  ddi_4 s4313;
  ddi_4 s4314;
  ddi_4 s4315;
  ddi_4 s4316;
  ddi_4 s4317;
  ddi_4 s4318;
  ddi_4 s4319;
  ddi_4 s4320;
  ddi_4 s4321;
  ddi_4 s4322;
  ddi_4 s4323;
  ddi_4 s4324;
  ddi_4 s4325;
  ddi_4 s4326;
  ddi_4 s4327;
  ddi_4 s4328;
  ddi_4 s4329;
  ddi_4 s4330;
  ddi_4 s4331;
  ddi_4 s4332;
  ddi_4 s4333;
  ddi_4 s4334;
  ddi_4 s4335;
  ddi_4 s4336;
  ddi_4 s4337;
  ddi_4 s4338;
  ddi_4 s4339;
  ddi_4 s4340;
  ddi_4 s4341;
  ddi_4 s4342;
  ddi_4 s4343;
  ddi_4 s4344;
  ddi_4 s4345;
  ddi_4 s4346;
  ddi_4 s4347;
  ddi_4 s4348;
  ddi_4 s4349;
  ddi_4 s4350;
  ddi_4 s4351;
  ddi_4 s4352;
  ddi_4 s4353;
  ddi_4 s4354;
  ddi_4 s4355;
  ddi_4 s4356;
  ddi_4 s4357;
  ddi_4 s4358;
  ddi_4 s4359;
  ddi_4 s4360;
  ddi_4 s4361;
  ddi_4 s4362;
  ddi_4 s4363;
  ddi_4 s4364;
  ddi_4 s4365;
  ddi_4 s4366;
  ddi_4 s4367;
  ddi_4 s4368;
  ddi_4 s4369;
  ddi_4 s4370;
  ddi_4 s4371;
  ddi_4 s4372;
  ddi_4 s4373;
  ddi_4 s4374;
  ddi_4 s4375;
  ddi_4 s4376;
  ddi_4 s4377;
  ddi_4 s4378;
  ddi_4 s4379;
  ddi_4 s4380;
  ddi_4 s4381;
  ddi_4 s4382;
  ddi_4 s4383;
  ddi_4 s4384;
  ddi_4 s4385;
  ddi_4 s4386;
  ddi_4 s4387;
  ddi_4 s4388;
  ddi_4 s4389;
  ddi_4 s4390;
  ddi_4 s4391;
  ddi_4 s4392;
  ddi_4 s4393;
  ddi_4 s4394;
  ddi_4 s4395;
  ddi_4 s4396;
  ddi_4 s4397;
  ddi_4 s4398;
  ddi_4 s4399;
  ddi_4 s4400;
  ddi_4 s4401;
  ddi_4 s4402;
  ddi_4 s4403;
  ddi_4 s4404;
  ddi_4 s4405;
  ddi_4 s4406;
  ddi_4 s4407;
  ddi_4 s4408;
  ddi_4 s4409;
  ddi_4 s4410;
  ddi_4 s4411;
  ddi_4 s4412;
  ddi_4 s4413;
  ddi_4 s4414;
  ddi_4 s4415;
  ddi_4 s4416;
  ddi_4 s4417;
  ddi_4 s4418;
  ddi_4 s4419;
  ddi_4 s4420;
  ddi_4 s4421;
  ddi_4 s4422;
  ddi_4 s4423;
  ddi_4 s4424;
  ddi_4 s4425;
  ddi_4 s4426;
  ddi_4 s4427;
  ddi_4 s4428;
  ddi_4 s4429;
  ddi_4 s4430;
  ddi_4 s4431;
  ddi_4 s4432;
  ddi_4 s4433;
  ddi_4 s4434;
  ddi_4 s4435;
  ddi_4 s4436;
  ddi_4 s4437;
  ddi_4 s4438;
  ddi_4 s4439;
  ddi_4 s4440;
  ddi_4 s4441;
  ddi_4 s4442;
  ddi_4 s4443;
  ddi_4 s4444;
  ddi_4 s4445;
  ddi_4 s4446;
  ddi_4 s4447;
  ddi_4 s4448;
  ddi_4 s4449;
  ddi_4 s4450;
  ddi_4 s4451;
  ddi_4 s4452;
  ddi_4 s4453;
  ddi_4 s4454;
  ddi_4 s4455;
  ddi_4 s4456;
  ddi_4 s4457;
  ddi_4 s4458;
  ddi_4 s4459;
  ddi_4 s4460;
  ddi_4 s4461;
  ddi_4 s4462;
  ddi_4 s4463;
  ddi_4 s4464;
  ddi_4 s4465;
  ddi_4 s4466;
  ddi_4 s4467;
  ddi_4 s4468;
  ddi_4 s4469;
  ddi_4 s4470;
  ddi_4 s4471;
  ddi_4 s4472;
  ddi_4 s4473;
  ddi_4 s4474;
  ddi_4 s4475;
  ddi_4 s4476;
  ddi_4 s4477;
  ddi_4 s4478;
  ddi_4 s4479;
  ddi_4 s4480;
  ddi_4 s4481;
  ddi_4 s4482;
  ddi_4 s4483;
  ddi_4 s4484;
  ddi_4 s4485;
  ddi_4 s4486;
  ddi_4 s4487;
  ddi_4 s4488;
  ddi_4 s4489;
  ddi_4 s4490;
  ddi_4 s4491;
  ddi_4 s4492;
  ddi_4 s4493;
  ddi_4 s4494;
  ddi_4 s4495;
  ddi_4 s4496;
  ddi_4 s4497;
  ddi_4 s4498;
  ddi_4 s4499;
  ddi_4 s4500;
  ddi_4 s4501;
  ddi_4 s4502;
  ddi_4 s4503;
  ddi_4 s4504;
  ddi_4 s4505;
  ddi_4 s4506;
  ddi_4 s4507;
  ddi_4 s4508;
  ddi_4 s4509;
  ddi_4 s4510;
  ddi_4 s4511;
  ddi_4 s4512;
  ddi_4 s4513;
  ddi_4 s4514;
  ddi_4 s4515;
  ddi_4 s4516;
  ddi_4 s4517;
  ddi_4 s4518;
  ddi_4 s4519;
  ddi_4 s4520;
  ddi_4 s4521;
  ddi_4 s4522;
  ddi_4 s4523;
  ddi_4 s4524;
  ddi_4 s4525;
  ddi_4 s4526;
  ddi_4 s4527;
  ddi_4 s4528;
  ddi_4 s4529;
  ddi_4 s4530;
  ddi_4 s4531;
  ddi_4 s4532;
  ddi_4 s4533;
  ddi_4 s4534;
  ddi_4 s4535;
  ddi_4 s4536;
  ddi_4 s4537;
  ddi_4 s4538;
  ddi_4 s4539;
  ddi_4 s4540;
  ddi_4 s4541;
  ddi_4 s4542;
  ddi_4 s4543;
  ddi_4 s4544;
  ddi_4 s4545;
  ddi_4 s4546;
  ddi_4 s4547;
  ddi_4 s4548;
  ddi_4 s4549;
  ddi_4 s4550;
  ddi_4 s4551;
  ddi_4 s4552;
  ddi_4 s4553;
  ddi_4 s4554;
  ddi_4 s4555;
  ddi_4 s4556;
  ddi_4 s4557;
  ddi_4 s4558;
  ddi_4 s4559;
  ddi_4 s4560;
  ddi_4 s4561;
  ddi_4 s4562;
  ddi_4 s4563;
  ddi_4 s4564;
  ddi_4 s4565;
  ddi_4 s4566;
  ddi_4 s4567;
  ddi_4 s4568;
  ddi_4 s4569;
  ddi_4 s4570;
  ddi_4 s4571;
  ddi_4 s4572;
  ddi_4 s4573;
  ddi_4 s4574;
  ddi_4 s4575;
  ddi_4 s4576;
  ddi_4 s4577;
  ddi_4 s4578;
  ddi_4 s4579;
  ddi_4 s4580;
  ddi_4 s4581;
  ddi_4 s4582;
  ddi_4 s4583;
  ddi_4 s4584;
  ddi_4 s4585;
  ddi_4 s4586;
  ddi_4 s4587;
  ddi_4 s4588;
  ddi_4 s4589;
  ddi_4 s4590;
  ddi_4 s4591;
  ddi_4 s4592;
  ddi_4 s4593;
  ddi_4 s4594;
  ddi_4 s4595;
  ddi_4 s4596;
  ddi_4 s4597;
  ddi_4 s4598;
  ddi_4 s4599;
  ddi_4 s4600;
  ddi_4 s4601;
  ddi_4 s4602;
  ddi_4 s4603;
  ddi_4 s4604;
  ddi_4 s4605;
  ddi_4 s4606;
  ddi_4 s4607;
  ddi_4 s4608;
  ddi_4 s4609;
  ddi_4 s4610;
  ddi_4 s4611;
  ddi_4 s4612;
  ddi_4 s4613;
  ddi_4 s4614;
  ddi_4 s4615;
  ddi_4 s4616;
  ddi_4 s4617;
  ddi_4 s4618;
  ddi_4 s4619;
  ddi_4 s4620;
  ddi_4 s4621;
  ddi_4 s4622;
  ddi_4 s4623;
  ddi_4 s4624;
  ddi_4 s4625;
  ddi_4 s4626;
  ddi_4 s4627;
  ddi_4 s4628;
  ddi_4 s4629;
  ddi_4 s4630;
  ddi_4 s4631;
  ddi_4 s4632;
  ddi_4 s4633;
  ddi_4 s4634;
  ddi_4 s4635;
  ddi_4 s4636;
  ddi_4 s4637;
  ddi_4 s4638;
  ddi_4 s4639;
  ddi_4 s4640;
  ddi_4 s4641;
  ddi_4 s4642;
  ddi_4 s4643;
  ddi_4 s4644;
  ddi_4 s4645;
  ddi_4 s4646;
  ddi_4 s4647;
  ddi_4 s4648;
  ddi_4 s4649;
  ddi_4 s4650;
  ddi_4 s4651;
  ddi_4 s4652;
  ddi_4 s4653;
  ddi_4 s4654;
  ddi_4 s4655;
  ddi_4 s4656;
  ddi_4 s4657;
  ddi_4 s4658;
  ddi_4 s4659;
  ddi_4 s4660;
  ddi_4 s4661;
  ddi_4 s4662;
  ddi_4 s4663;
  ddi_4 s4664;
  ddi_4 s4665;
  ddi_4 s4666;
  ddi_4 s4667;
  ddi_4 s4668;
  ddi_4 s4669;
  ddi_4 s4670;
  ddi_4 s4671;
  ddi_4 s4672;
  ddi_4 s4673;
  ddi_4 s4674;
  ddi_4 s4675;
  ddi_4 s4676;
  ddi_4 s4677;
  ddi_4 s4678;
  ddi_4 s4679;
  ddi_4 s4680;
  ddi_4 s4681;
  ddi_4 s4682;
  ddi_4 s4683;
  ddi_4 s4684;
  ddi_4 s4685;
  ddi_4 s4686;
  ddi_4 s4687;
  ddi_4 s4688;
  ddi_4 s4689;
  ddi_4 s4690;
  ddi_4 s4691;
  ddi_4 s4692;
  ddi_4 s4693;
  ddi_4 s4694;
  ddi_4 s4695;
  ddi_4 s4696;
  ddi_4 s4697;
  ddi_4 s4698;
  ddi_4 s4699;
  ddi_4 s4700;
  ddi_4 s4701;
  ddi_4 s4702;
  ddi_4 s4703;
  ddi_4 s4704;
  ddi_4 s4705;
  ddi_4 s4706;
  ddi_4 s4707;
  ddi_4 s4708;
  ddi_4 s4709;
  ddi_4 s4710;
  ddi_4 s4711;
  ddi_4 s4712;
  ddi_4 s4713;
  ddi_4 s4714;
  ddi_4 s4715;
  ddi_4 s4716;
  ddi_4 s4717;
  ddi_4 s4718;
  ddi_4 s4719;
  ddi_4 s4720;
  ddi_4 s4721;
  ddi_4 s4722;
  ddi_4 s4723;
  ddi_4 s4724;
  ddi_4 s4725;
  ddi_4 s4726;
  ddi_4 s4727;
  ddi_4 s4728;
  ddi_4 s4729;
  ddi_4 s4730;
  ddi_4 s4731;
  ddi_4 s4732;
  ddi_4 s4733;
  ddi_4 s4734;
  ddi_4 s4735;
  ddi_4 s4736;
  ddi_4 s4737;
  ddi_4 s4738;
  ddi_4 s4739;
  ddi_4 s4740;
  ddi_4 s4741;
  ddi_4 s4742;
  ddi_4 s4743;
  ddi_4 s4744;
  ddi_4 s4745;
  ddi_4 s4746;
  ddi_4 s4747;
  ddi_4 s4748;
  ddi_4 s4749;
  ddi_4 s4750;
  ddi_4 s4751;
  ddi_4 s4752;
  ddi_4 s4753;
  ddi_4 s4754;
  ddi_4 s4755;
  ddi_4 s4756;
  ddi_4 s4757;
  ddi_4 s4758;
  ddi_4 s4759;
  ddi_4 s4760;
  ddi_4 s4761;
  ddi_4 s4762;
  ddi_4 s4763;
  ddi_4 s4764;
  ddi_4 s4765;
  ddi_4 s4766;
  ddi_4 s4767;
  ddi_4 s4768;
  ddi_4 s4769;
  ddi_4 s4770;
  ddi_4 s4771;
  ddi_4 s4772;
  ddi_4 s4773;
  ddi_4 s4774;
  ddi_4 s4775;
  ddi_4 s4776;
  ddi_4 s4777;
  ddi_4 s4778;
  ddi_4 s4779;
  ddi_4 s4780;
  ddi_4 s4781;
  ddi_4 s4782;
  ddi_4 s4783;
  ddi_4 s4784;
  ddi_4 s4785;
  ddi_4 s4786;
  ddi_4 s4787;
  ddi_4 s4788;
  ddi_4 s4789;
  ddi_4 s4790;
  ddi_4 s4791;
  ddi_4 s4792;
  ddi_4 s4793;
  ddi_4 s4794;
  ddi_4 s4795;
  ddi_4 s4796;
  ddi_4 s4797;
  ddi_4 s4798;
  ddi_4 s4799;
  ddi_4 s4800;
  ddi_4 s4801;
  ddi_4 s4802;
  ddi_4 s4803;
  ddi_4 s4804;
  ddi_4 s4805;
  ddi_4 s4806;
  ddi_4 s4807;
  ddi_4 s4808;
  ddi_4 s4809;
  ddi_4 s4810;
  ddi_4 s4811;
  ddi_4 s4812;
  ddi_4 s4813;
  ddi_4 s4814;
  ddi_4 s4815;
  ddi_4 s4816;
  ddi_4 s4817;
  ddi_4 s4818;
  ddi_4 s4819;
  ddi_4 s4820;
  ddi_4 s4821;
  ddi_4 s4822;
  ddi_4 s4823;
  ddi_4 s4824;
  ddi_4 s4825;
  ddi_4 s4826;
  ddi_4 s4827;
  ddi_4 s4828;
  ddi_4 s4829;
  ddi_4 s4830;
  ddi_4 s4831;
  ddi_4 s4832;
  ddi_4 s4833;
  ddi_4 s4834;
  ddi_4 s4835;
  ddi_4 s4836;
  ddi_4 s4837;
  ddi_4 s4838;
  ddi_4 s4839;
  ddi_4 s4840;
  ddi_4 s4841;
  ddi_4 s4842;
  ddi_4 s4843;
  ddi_4 s4844;
  ddi_4 s4845;
  ddi_4 s4846;
  ddi_4 s4847;
  ddi_4 s4848;
  ddi_4 s4849;
  ddi_4 s4850;
  ddi_4 s4851;
  ddi_4 s4852;
  ddi_4 s4853;
  ddi_4 s4854;
  ddi_4 s4855;
  ddi_4 s4856;
  ddi_4 s4857;
  ddi_4 s4858;
  ddi_4 s4859;
  ddi_4 s4860;
  ddi_4 s4861;
  ddi_4 s4862;
  ddi_4 s4863;
  ddi_4 s4864;
  ddi_4 s4865;
  ddi_4 s4866;
  ddi_4 s4867;
  ddi_4 s4868;
  ddi_4 s4869;
  ddi_4 s4870;
  ddi_4 s4871;
  ddi_4 s4872;
  ddi_4 s4873;
  ddi_4 s4874;
  ddi_4 s4875;
  ddi_4 s4876;
  ddi_4 s4877;
  ddi_4 s4878;
  ddi_4 s4879;
  ddi_4 s4880;
  ddi_4 s4881;
  ddi_4 s4882;
  ddi_4 s4883;
  ddi_4 s4884;
  ddi_4 s4885;
  ddi_4 s4886;
  ddi_4 s4887;
  ddi_4 s4888;
  ddi_4 s4889;
  ddi_4 s4890;
  ddi_4 s4891;
  ddi_4 s4892;
  ddi_4 s4893;
  ddi_4 s4894;
  ddi_4 s4895;
  ddi_4 s4896;
  ddi_4 s4897;
  ddi_4 s4898;
  ddi_4 s4899;
  ddi_4 s4900;
  ddi_4 s4901;
  ddi_4 s4902;
  ddi_4 s4903;
  ddi_4 s4904;
  ddi_4 s4905;
  ddi_4 s4906;
  ddi_4 s4907;
  ddi_4 s4908;
  ddi_4 s4909;
  ddi_4 s4910;
  ddi_4 s4911;
  ddi_4 s4912;
  ddi_4 s4913;
  ddi_4 s4914;
  ddi_4 s4915;
  ddi_4 s4916;
  ddi_4 s4917;
  ddi_4 s4918;
  ddi_4 s4919;
  ddi_4 s4920;
  ddi_4 s4921;
  ddi_4 s4922;
  ddi_4 s4923;
  ddi_4 s4924;
  ddi_4 s4925;
  ddi_4 s4926;
  ddi_4 s4927;
  ddi_4 s4928;
  ddi_4 s4929;
  ddi_4 s4930;
  ddi_4 s4931;
  ddi_4 s4932;
  ddi_4 s4933;
  ddi_4 s4934;
  ddi_4 s4935;
  ddi_4 s4936;
  ddi_4 s4937;
  ddi_4 s4938;
  ddi_4 s4939;
  ddi_4 s4940;
  ddi_4 s4941;
  ddi_4 s4942;
  ddi_4 s4943;
  ddi_4 s4944;
  ddi_4 s4945;
  ddi_4 s4946;
  ddi_4 s4947;
  ddi_4 s4948;
  ddi_4 s4949;
  ddi_4 s4950;
  ddi_4 s4951;
  ddi_4 s4952;
  ddi_4 s4953;
  ddi_4 s4954;
  ddi_4 s4955;
  ddi_4 s4956;
  ddi_4 s4957;
  ddi_4 s4958;
  ddi_4 s4959;
  ddi_4 s4960;
  ddi_4 s4961;
  ddi_4 s4962;
  ddi_4 s4963;
  ddi_4 s4964;
  ddi_4 s4965;
  ddi_4 s4966;
  ddi_4 s4967;
  ddi_4 s4968;
  ddi_4 s4969;
  ddi_4 s4970;
  ddi_4 s4971;
  ddi_4 s4972;
  ddi_4 s4973;
  ddi_4 s4974;
  ddi_4 s4975;
  ddi_4 s4976;
  ddi_4 s4977;
  ddi_4 s4978;
  ddi_4 s4979;
  ddi_4 s4980;
  ddi_4 s4981;
  ddi_4 s4982;
  ddi_4 s4983;
  ddi_4 s4984;
  ddi_4 s4985;
  ddi_4 s4986;
  ddi_4 s4987;
  ddi_4 s4988;
  ddi_4 s4989;
  ddi_4 s4990;
  ddi_4 s4991;
  ddi_4 s4992;
  ddi_4 s4993;
  ddi_4 s4994;
  ddi_4 s4995;
  ddi_4 s4996;
  ddi_4 s4997;
  ddi_4 s4998;
  ddi_4 s4999;
  ddi_4 s5000;
  ddi_4 s5001;
  ddi_4 s5002;
  ddi_4 s5003;
  ddi_4 s5004;
  ddi_4 s5005;
  ddi_4 s5006;
  ddi_4 s5007;
  ddi_4 s5008;
  ddi_4 s5009;
  ddi_4 s5010;
  ddi_4 s5011;
  ddi_4 s5012;
  ddi_4 s5013;
  ddi_4 s5014;
  ddi_4 s5015;
  ddi_4 s5016;
  ddi_4 s5017;
  ddi_4 s5018;
  ddi_4 s5019;
  ddi_4 s5020;
  ddi_4 s5021;
  ddi_4 s5022;
  ddi_4 s5023;
  ddi_4 s5024;
  ddi_4 s5025;
  ddi_4 s5026;
  ddi_4 s5027;
  ddi_4 s5028;
  ddi_4 s5029;
  ddi_4 s5030;
  ddi_4 s5031;
  ddi_4 s5032;
  ddi_4 s5033;
  ddi_4 s5034;
  ddi_4 s5035;
  ddi_4 s5036;
  ddi_4 s5037;
  ddi_4 s5038;
  ddi_4 s5039;
  ddi_4 s5040;
  ddi_4 s5041;
  ddi_4 s5042;
  ddi_4 s5043;
  ddi_4 s5044;
  ddi_4 s5045;
  ddi_4 s5046;
  ddi_4 s5047;
  ddi_4 s5048;
  ddi_4 s5049;
  ddi_4 s5050;
  ddi_4 s5051;
  ddi_4 s5052;
  ddi_4 s5053;
  ddi_4 s5054;
  ddi_4 s5055;
  ddi_4 s5056;
  ddi_4 s5057;
  ddi_4 s5058;
  ddi_4 s5059;
  ddi_4 s5060;
  ddi_4 s5061;
  ddi_4 s5062;
  ddi_4 s5063;
  ddi_4 s5064;
  ddi_4 s5065;
  ddi_4 s5066;
  ddi_4 s5067;
  ddi_4 s5068;
  ddi_4 s5069;
  ddi_4 s5070;
  ddi_4 s5071;
  ddi_4 s5072;
  ddi_4 s5073;
  ddi_4 s5074;
  ddi_4 s5075;
  ddi_4 s5076;
  ddi_4 s5077;
  ddi_4 s5078;
  ddi_4 s5079;
  ddi_4 s5080;
  ddi_4 s5081;
  ddi_4 s5082;
  ddi_4 s5083;
  ddi_4 s5084;
  ddi_4 s5085;
  ddi_4 s5086;
  ddi_4 s5087;
  ddi_4 s5088;
  ddi_4 s5089;
  ddi_4 s5090;
  ddi_4 s5091;
  ddi_4 s5092;
  ddi_4 s5093;
  ddi_4 s5094;
  ddi_4 s5095;
  ddi_4 s5096;
  ddi_4 s5097;
  ddi_4 s5098;
  ddi_4 s5099;
  ddi_4 s5100;
  ddi_4 s5101;
  ddi_4 s5102;
  ddi_4 s5103;
  ddi_4 s5104;
  ddi_4 s5105;
  ddi_4 s5106;
  ddi_4 s5107;
  ddi_4 s5108;
  ddi_4 s5109;
  ddi_4 s5110;
  ddi_4 s5111;
  ddi_4 s5112;
  ddi_4 s5113;
  ddi_4 s5114;
  ddi_4 s5115;
  ddi_4 s5116;
  ddi_4 s5117;
  ddi_4 s5118;
  ddi_4 s5119;
  ddi_4 s5120;
  ddi_4 s5121;
  ddi_4 s5122;
  ddi_4 s5123;
  ddi_4 s5124;
  ddi_4 s5125;
  ddi_4 s5126;
  ddi_4 s5127;
  ddi_4 s5128;
  ddi_4 s5129;
  ddi_4 s5130;
  ddi_4 s5131;
  ddi_4 s5132;
  ddi_4 s5133;
  ddi_4 s5134;
  ddi_4 s5135;
  ddi_4 s5136;
  ddi_4 s5137;
  ddi_4 s5138;
  ddi_4 s5139;
  ddi_4 s5140;
  ddi_4 s5141;
  ddi_4 s5142;
  ddi_4 s5143;
  ddi_4 s5144;
  ddi_4 s5145;
  ddi_4 s5146;
  ddi_4 s5147;
  ddi_4 s5148;
  ddi_4 s5149;
  ddi_4 s5150;
  ddi_4 s5151;
  ddi_4 s5152;
  ddi_4 s5153;
  ddi_4 s5154;
  ddi_4 s5155;
  ddi_4 s5156;
  ddi_4 s5157;
  ddi_4 s5158;
  ddi_4 s5159;
  ddi_4 s5160;
  ddi_4 s5161;
  ddi_4 s5162;
  ddi_4 s5163;
  ddi_4 s5164;
  ddi_4 s5165;
  ddi_4 s5166;
  ddi_4 s5167;
  ddi_4 s5168;
  ddi_4 s5169;
  ddi_4 t3112;
  ddi_4 t3113;
  ddi_4 t3114;
  ddi_4 t3115;
  ddi_4 t3116;
  ddi_4 t3117;
  ddi_4 t3118;
  ddi_4 t3119;
  ddi_4 t3120;
  ddi_4 t3121;
  ddi_4 t3122;
  ddi_4 t3123;
  ddi_4 t3124;
  ddi_4 t3125;
  ddi_4 t3126;
  ddi_4 t3127;
  ddi_4 t3128;
  ddi_4 t3129;
  ddi_4 t3130;
  ddi_4 t3131;
  ddi_4 t3132;
  ddi_4 t3133;
  ddi_4 t3134;
  ddi_4 t3135;
  ddi_4 t3136;
  ddi_4 t3137;
  ddi_4 t3138;
  ddi_4 t3139;
  ddi_4 t3140;
  ddi_4 t3141;
  ddi_4 t3142;
  ddi_4 t3143;
  ddi_4 t3144;
  ddi_4 t3145;
  ddi_4 t3146;
  ddi_4 t3147;
  ddi_4 t3148;
  ddi_4 t3149;
  ddi_4 t3150;
  ddi_4 t3151;
  ddi_4 t3152;
  ddi_4 t3153;
  ddi_4 t3154;
  ddi_4 t3155;
  ddi_4 t3156;
  ddi_4 t3157;
  ddi_4 t3158;
  ddi_4 t3159;
  ddi_4 t3160;
  ddi_4 t3161;
  ddi_4 t3162;
  ddi_4 t3163;
  ddi_4 t3164;
  ddi_4 t3165;
  ddi_4 t3166;
  ddi_4 t3167;
  ddi_4 t3168;
  ddi_4 t3169;
  ddi_4 t3170;
  ddi_4 t3171;
  ddi_4 t3172;
  ddi_4 t3173;
  ddi_4 t3174;
  ddi_4 t3175;
  ddi_4 t3176;
  ddi_4 t3177;
  ddi_4 t3178;
  ddi_4 t3179;
  ddi_4 t3180;
  ddi_4 t3181;
  ddi_4 t3182;
  ddi_4 t3183;
  ddi_4 t3184;
  ddi_4 t3185;
  ddi_4 t3186;
  ddi_4 t3187;
  ddi_4 t3188;
  ddi_4 t3189;
  ddi_4 t3190;
  ddi_4 t3191;
  ddi_4 t3192;
  ddi_4 t3193;
  ddi_4 t3194;
  ddi_4 t3195;
  ddi_4 t3196;
  ddi_4 t3197;
  ddi_4 t3198;
  ddi_4 t3199;
  ddi_4 t3200;
  ddi_4 t3201;
  ddi_4 t3202;
  ddi_4 t3203;
  ddi_4 t3204;
  ddi_4 t3205;
  ddi_4 t3206;
  ddi_4 t3207;
  ddi_4 t3208;
  ddi_4 t3209;
  ddi_4 t3210;
  ddi_4 t3211;
  ddi_4 t3212;
  ddi_4 t3213;
  ddi_4 t3214;
  ddi_4 t3215;
  ddi_4 t3216;
  ddi_4 t3217;
  ddi_4 t3218;
  ddi_4 t3219;
  ddi_4 t3220;
  ddi_4 t3221;
  ddi_4 t3222;
  ddi_4 t3223;
  ddi_4 t3224;
  ddi_4 t3225;
  ddi_4 t3226;
  ddi_4 t3227;
  ddi_4 t3228;
  ddi_4 t3229;
  ddi_4 t3230;
  ddi_4 t3231;
  ddi_4 t3232;
  ddi_4 t3233;
  ddi_4 t3234;
  ddi_4 t3235;
  ddi_4 t3236;
  ddi_4 t3237;
  ddi_4 t3238;
  ddi_4 t3239;
  ddi_4 t3240;
  ddi_4 t3241;
  ddi_4 t3242;
  ddi_4 t3243;
  ddi_4 t3244;
  ddi_4 t3245;
  ddi_4 t3246;
  ddi_4 t3247;
  ddi_4 t3248;
  ddi_4 t3249;
  ddi_4 t3250;
  ddi_4 t3251;
  ddi_4 t3252;
  ddi_4 t3253;
  ddi_4 t3254;
  ddi_4 t3255;
  ddi_4 t3256;
  ddi_4 t3257;
  ddi_4 t3258;
  ddi_4 t3259;
  ddi_4 t3260;
  ddi_4 t3261;
  ddi_4 t3262;
  ddi_4 t3263;
  ddi_4 t3264;
  ddi_4 t3265;
  ddi_4 t3266;
  ddi_4 t3267;
  ddi_4 t3268;
  ddi_4 t3269;
  ddi_4 t3270;
  ddi_4 t3271;
  ddi_4 t3272;
  ddi_4 t3273;
  ddi_4 t3274;
  ddi_4 t3275;
  ddi_4 t3276;
  ddi_4 t3277;
  ddi_4 t3278;
  ddi_4 t3279;
  ddi_4 t3280;
  ddi_4 t3281;
  ddi_4 t3282;
  ddi_4 t3283;
  ddi_4 t3284;
  ddi_4 t3285;
  ddi_4 t3286;
  ddi_4 t3287;
  ddi_4 t3288;
  ddi_4 t3289;
  ddi_4 t3290;
  ddi_4 t3291;
  ddi_4 t3292;
  ddi_4 t3293;
  ddi_4 t3294;
  ddi_4 t3295;
  ddi_4 t3296;
  ddi_4 t3297;
  ddi_4 t3298;
  ddi_4 t3299;
  ddi_4 t3300;
  ddi_4 t3301;
  ddi_4 t3302;
  ddi_4 t3303;
  ddi_4 t3304;
  ddi_4 t3305;
  ddi_4 t3306;
  ddi_4 t3307;
  ddi_4 t3308;
  ddi_4 t3309;
  ddi_4 t3310;
  ddi_4 t3311;
  ddi_4 t3312;
  ddi_4 t3313;
  ddi_4 t3314;
  ddi_4 t3315;
  ddi_4 t3316;
  ddi_4 t3317;
  ddi_4 t3318;
  ddi_4 t3319;
  ddi_4 t3320;
  ddi_4 t3321;
  ddi_4 t3322;
  ddi_4 t3323;
  ddi_4 t3324;
  ddi_4 t3325;
  ddi_4 t3326;
  ddi_4 t3327;
  ddi_4 t3328;
  ddi_4 t3329;
  ddi_4 t3330;
  ddi_4 t3331;
  ddi_4 t3332;
  ddi_4 t3333;
  ddi_4 t3334;
  ddi_4 t3335;
  ddi_4 t3336;
  ddi_4 t3337;
  ddi_4 t3338;
  ddi_4 t3339;
  ddi_4 t3340;
  ddi_4 t3341;
  ddi_4 t3342;
  ddi_4 t3343;
  ddi_4 t3344;
  ddi_4 t3345;
  ddi_4 t3346;
  ddi_4 t3347;
  ddi_4 t3348;
  ddi_4 t3349;
  ddi_4 t3350;
  ddi_4 t3351;
  ddi_4 t3352;
  ddi_4 t3353;
  ddi_4 t3354;
  ddi_4 t3355;
  ddi_4 t3356;
  ddi_4 t3357;
  ddi_4 t3358;
  ddi_4 t3359;
  ddi_4 t3360;
  ddi_4 t3361;
  ddi_4 t3362;
  ddi_4 t3363;
  ddi_4 t3364;
  ddi_4 t3365;
  ddi_4 t3366;
  ddi_4 t3367;
  ddi_4 t3368;
  ddi_4 t3369;
  ddi_4 t3370;
  ddi_4 t3371;
  ddi_4 t3372;
  ddi_4 t3373;
  ddi_4 t3374;
  ddi_4 t3375;
  ddi_4 t3376;
  ddi_4 t3377;
  ddi_4 t3378;
  ddi_4 t3379;
  ddi_4 t3380;
  ddi_4 t3381;
  ddi_4 t3382;
  ddi_4 t3383;
  ddi_4 t3384;
  ddi_4 t3385;
  ddi_4 t3386;
  ddi_4 t3387;
  ddi_4 t3388;
  ddi_4 t3389;
  ddi_4 t3390;
  ddi_4 t3391;
  ddi_4 t3392;
  ddi_4 t3393;
  ddi_4 t3394;
  ddi_4 t3395;
  ddi_4 t3396;
  ddi_4 t3397;
  ddi_4 t3398;
  ddi_4 t3399;
  ddi_4 t3400;
  ddi_4 t3401;
  ddi_4 t3402;
  ddi_4 t3403;
  ddi_4 t3404;
  ddi_4 t3405;
  ddi_4 t3406;
  ddi_4 t3407;
  ddi_4 t3408;
  ddi_4 t3409;
  ddi_4 t3410;
  ddi_4 t3411;
  ddi_4 t3412;
  ddi_4 t3413;
  ddi_4 t3414;
  ddi_4 t3415;
  ddi_4 t3416;
  ddi_4 t3417;
  ddi_4 t3418;
  ddi_4 t3419;
  ddi_4 t3420;
  ddi_4 t3421;
  ddi_4 t3422;
  ddi_4 t3423;
  ddi_4 t3424;
  ddi_4 t3425;
  ddi_4 t3426;
  ddi_4 t3427;
  ddi_4 t3428;
  ddi_4 t3429;
  ddi_4 t3430;
  ddi_4 t3431;
  ddi_4 t3432;
  ddi_4 t3433;
  ddi_4 t3434;
  ddi_4 t3435;
  ddi_4 t3436;
  ddi_4 t3437;
  ddi_4 t3438;
  ddi_4 t3439;
  ddi_4 t3440;
  ddi_4 t3441;
  ddi_4 t3442;
  ddi_4 t3443;
  ddi_4 t3444;
  ddi_4 t3445;
  ddi_4 t3446;
  ddi_4 t3447;
  ddi_4 t3448;
  ddi_4 t3449;
  ddi_4 t3450;
  ddi_4 t3451;
  ddi_4 t3452;
  ddi_4 t3453;
  ddi_4 t3454;
  ddi_4 t3455;
  ddi_4 t3456;
  ddi_4 t3457;
  ddi_4 t3458;
  ddi_4 t3459;
  ddi_4 t3460;
  ddi_4 t3461;
  ddi_4 t3462;
  ddi_4 t3463;
  ddi_4 t3464;
  ddi_4 t3465;
  ddi_4 t3466;
  ddi_4 t3467;
  ddi_4 t3468;
  ddi_4 t3469;
  ddi_4 t3470;
  ddi_4 t3471;
  ddi_4 t3472;
  ddi_4 t3473;
  ddi_4 t3474;
  ddi_4 t3475;
  ddi_4 t3476;
  ddi_4 t3477;
  ddi_4 t3478;
  ddi_4 t3479;
  ddi_4 t3480;
  ddi_4 t3481;
  ddi_4 t3482;
  ddi_4 t3483;
  ddi_4 t3484;
  ddi_4 t3485;
  ddi_4 t3486;
  ddi_4 t3487;
  ddi_4 t3488;
  ddi_4 t3489;
  ddi_4 t3490;
  ddi_4 t3491;
  ddi_4 t3492;
  ddi_4 t3493;
  ddi_4 t3494;
  ddi_4 t3495;
  ddi_4 t3496;
  ddi_4 t3497;
  ddi_4 t3498;
  ddi_4 t3499;
  ddi_4 t3500;
  ddi_4 t3501;
  ddi_4 t3502;
  ddi_4 t3503;
  ddi_4 t3504;
  ddi_4 t3505;
  ddi_4 t3506;
  ddi_4 t3507;
  ddi_4 t3508;
  ddi_4 t3509;
  ddi_4 t3510;
  ddi_4 t3511;
  ddi_4 t3512;
  ddi_4 t3513;
  ddi_4 t3514;
  ddi_4 t3515;
  ddi_4 t3516;
  ddi_4 t3517;
  ddi_4 t3518;
  ddi_4 t3519;
  ddi_4 t3520;
  ddi_4 t3521;
  ddi_4 t3522;
  ddi_4 t3523;
  ddi_4 t3524;
  ddi_4 t3525;
  ddi_4 t3526;
  ddi_4 t3527;
  ddi_4 t3528;
  ddi_4 t3529;
  ddi_4 t3530;
  ddi_4 t3531;
  ddi_4 t3532;
  ddi_4 t3533;
  ddi_4 t3534;
  ddi_4 t3535;
  ddi_4 t3536;
  ddi_4 t3537;
  ddi_4 t3538;
  ddi_4 t3539;
  ddi_4 t3540;
  ddi_4 t3541;
  ddi_4 t3542;
  ddi_4 t3543;
  ddi_4 t3544;
  ddi_4 t3545;
  ddi_4 t3546;
  ddi_4 t3547;
  ddi_4 t3548;
  ddi_4 t3549;
  ddi_4 t3550;
  ddi_4 t3551;
  ddi_4 t3552;
  ddi_4 t3553;
  ddi_4 t3554;
  ddi_4 t3555;
  ddi_4 t3556;
  ddi_4 t3557;
  ddi_4 t3558;
  ddi_4 t3559;
  ddi_4 t3560;
  ddi_4 t3561;
  ddi_4 t3562;
  ddi_4 t3563;
  ddi_4 t3564;
  ddi_4 t3565;
  ddi_4 t3566;
  ddi_4 t3567;
  ddi_4 t3568;
  ddi_4 t3569;
  ddi_4 t3570;
  ddi_4 t3571;
  ddi_4 t3572;
  ddi_4 t3573;
  ddi_4 t3574;
  ddi_4 t3575;
  ddi_4 t3576;
  ddi_4 t3577;
  ddi_4 t3578;
  ddi_4 t3579;
  ddi_4 t3580;
  ddi_4 t3581;
  ddi_4 t3582;
  ddi_4 t3583;
  ddi_4 t3584;
  ddi_4 t3585;
  ddi_4 t3586;
  ddi_4 t3587;
  ddi_4 t3588;
  ddi_4 t3589;
  ddi_4 t3590;
  ddi_4 t3591;
  ddi_4 t3592;
  ddi_4 t3593;
  ddi_4 t3594;
  ddi_4 t3595;
  ddi_4 t3596;
  ddi_4 t3597;
  ddi_4 t3598;
  ddi_4 t3599;
  ddi_4 t3600;
  ddi_4 t3601;
  ddi_4 t3602;
  ddi_4 t3603;
  ddi_4 t3604;
  ddi_4 t3605;
  ddi_4 t3606;
  ddi_4 t3607;
  ddi_4 t3608;
  ddi_4 t3609;
  ddi_4 t3610;
  ddi_4 t3611;
  ddi_4 t3612;
  ddi_4 t3613;
  ddi_4 t3614;
  ddi_4 t3615;
  ddi_4 t3616;
  ddi_4 t3617;
  ddi_4 t3618;
  ddi_4 t3619;
  ddi_4 t3620;
  ddi_4 t3621;
  ddi_4 t3622;
  ddi_4 t3623;
  ddi_4 t3624;
  ddi_4 t3625;
  ddi_4 t3626;
  ddi_4 t3627;
  ddi_4 t3628;
  ddi_4 t3629;
  ddi_4 t3630;
  ddi_4 t3631;
  ddi_4 t3632;
  ddi_4 t3633;
  ddi_4 t3634;
  ddi_4 t3635;
  ddi_4 t3636;
  ddi_4 t3637;
  ddi_4 t3638;
  ddi_4 t3639;
  ddi_4 t3640;
  ddi_4 t3641;
  ddi_4 t3642;
  ddi_4 t3643;
  ddi_4 t3644;
  ddi_4 t3645;
  ddi_4 t3646;
  ddi_4 t3647;
  ddi_4 t3648;
  ddi_4 t3649;
  ddi_4 t3650;
  ddi_4 t3651;
  ddi_4 t3652;
  ddi_4 t3653;
  ddi_4 t3654;
  ddi_4 t3655;
  ddi_4 t3656;
  ddi_4 t3657;
  ddi_4 t3658;
  ddi_4 t3659;
  ddi_4 t3660;
  ddi_4 t3661;
  ddi_4 t3662;
  ddi_4 t3663;
  ddi_4 t3664;
  ddi_4 t3665;
  ddi_4 t3666;
  ddi_4 t3667;
  ddi_4 t3668;
  ddi_4 t3669;
  ddi_4 t3670;
  ddi_4 t3671;
  ddi_4 t3672;
  ddi_4 t3673;
  ddi_4 t3674;
  ddi_4 t3675;
  ddi_4 t3676;
  ddi_4 t3677;
  ddi_4 t3678;
  ddi_4 t3679;
  ddi_4 t3680;
  ddi_4 t3681;
  ddi_4 t3682;
  ddi_4 t3683;
  ddi_4 t3684;
  ddi_4 t3685;
  ddi_4 t3686;
  ddi_4 t3687;
  ddi_4 t3688;
  ddi_4 t3689;
  ddi_4 t3690;
  ddi_4 t3691;
  ddi_4 t3692;
  ddi_4 t3693;
  ddi_4 t3694;
  ddi_4 t3695;
  ddi_4 t3696;
  ddi_4 t3697;
  ddi_4 t3698;
  ddi_4 t3699;
  ddi_4 t3700;
  ddi_4 t3701;
  ddi_4 t3702;
  ddi_4 t3703;
  ddi_4 t3704;
  ddi_4 t3705;
  ddi_4 t3706;
  ddi_4 t3707;
  ddi_4 t3708;
  ddi_4 t3709;
  ddi_4 t3710;
  ddi_4 t3711;
  ddi_4 t3712;
  ddi_4 t3713;
  ddi_4 t3714;
  ddi_4 t3715;
  ddi_4 t3716;
  ddi_4 t3717;
  ddi_4 t3718;
  ddi_4 t3719;
  ddi_4 t3720;
  ddi_4 t3721;
  ddi_4 t3722;
  ddi_4 t3723;
  ddi_4 t3724;
  ddi_4 t3725;
  ddi_4 t3726;
  ddi_4 t3727;
  ddi_4 t3728;
  ddi_4 t3729;
  ddi_4 t3730;
  ddi_4 t3731;
  ddi_4 t3732;
  ddi_4 t3733;
  ddi_4 t3734;
  ddi_4 t3735;
  ddi_4 t3736;
  ddi_4 t3737;
  ddi_4 t3738;
  ddi_4 t3739;
  ddi_4 t3740;
  ddi_4 t3741;
  ddi_4 t3742;
  ddi_4 t3743;
  ddi_4 t3744;
  ddi_4 t3745;
  ddi_4 t3746;
  ddi_4 t3747;
  ddi_4 t3748;
  ddi_4 t3749;
  ddi_4 t3750;
  ddi_4 t3751;
  ddi_4 t3752;
  ddi_4 t3753;
  ddi_4 t3754;
  ddi_4 t3755;
  ddi_4 t3756;
  ddi_4 t3757;
  ddi_4 t3758;
  ddi_4 t3759;
  ddi_4 t3760;
  ddi_4 t3761;
  ddi_4 t3762;
  ddi_4 t3763;
  ddi_4 t3764;
  ddi_4 t3765;
  ddi_4 t3766;
  ddi_4 t3767;
  ddi_4 t3768;
  ddi_4 t3769;
  ddi_4 t3770;
  ddi_4 t3771;
  ddi_4 t3772;
  ddi_4 t3773;
  ddi_4 t3774;
  ddi_4 t3775;
  ddi_4 t3776;
  ddi_4 t3777;
  ddi_4 t3778;
  ddi_4 t3779;
  ddi_4 t3780;
  ddi_4 t3781;
  ddi_4 t3782;
  ddi_4 t3783;
  ddi_4 t3784;
  ddi_4 t3785;
  ddi_4 t3786;
  ddi_4 t3787;
  ddi_4 t3788;
  ddi_4 t3789;
  ddi_4 t3790;
  ddi_4 t3791;
  ddi_4 t3792;
  ddi_4 t3793;
  ddi_4 t3794;
  ddi_4 t3795;
  ddi_4 t3796;
  ddi_4 t3797;
  ddi_4 t3798;
  ddi_4 t3799;
  ddi_4 t3800;
  ddi_4 t3801;
  ddi_4 t3802;
  ddi_4 t3803;
  ddi_4 t3804;
  ddi_4 t3805;
  ddi_4 t3806;
  ddi_4 t3807;
  ddi_4 t3808;
  ddi_4 t3809;
  ddi_4 t3810;
  ddi_4 t3811;
  ddi_4 t3812;
  ddi_4 t3813;
  ddi_4 t3814;
  ddi_4 t3815;
  ddi_4 t3816;
  ddi_4 t3817;
  ddi_4 t3818;
  ddi_4 t3819;
  ddi_4 t3820;
  ddi_4 t3821;
  ddi_4 t3822;
  ddi_4 t3823;
  ddi_4 t3824;
  ddi_4 t3825;
  ddi_4 t3826;
  ddi_4 t3827;
  ddi_4 t3828;
  ddi_4 t3829;
  ddi_4 t3830;
  ddi_4 t3831;
  ddi_4 t3832;
  ddi_4 t3833;
  ddi_4 t3834;
  ddi_4 t3835;
  ddi_4 t3836;
  ddi_4 t3837;
  ddi_4 t3838;
  ddi_4 t3839;
  ddi_4 t3840;
  ddi_4 t3841;
  ddi_4 t3842;
  ddi_4 t3843;
  ddi_4 t3844;
  ddi_4 t3845;
  ddi_4 t3846;
  ddi_4 t3847;
  ddi_4 t3848;
  ddi_4 t3849;
  ddi_4 t3850;
  ddi_4 t3851;
  ddi_4 t3852;
  ddi_4 t3853;
  ddi_4 t3854;
  ddi_4 t3855;
  ddi_4 t3856;
  ddi_4 t3857;
  ddi_4 t3858;
  ddi_4 t3859;
  ddi_4 t3860;
  ddi_4 t3861;
  ddi_4 t3862;
  ddi_4 t3863;
  ddi_4 t3864;
  ddi_4 t3865;
  ddi_4 t3866;
  ddi_4 t3867;
  ddi_4 t3868;
  ddi_4 t3869;
  ddi_4 t3870;
  ddi_4 t3871;
  ddi_4 t3872;
  ddi_4 t3873;
  ddi_4 t3874;
  ddi_4 t3875;
  ddi_4 t3876;
  ddi_4 t3877;
  ddi_4 t3878;
  ddi_4 t3879;
  ddi_4 t3880;
  ddi_4 t3881;
  ddi_4 t3882;
  ddi_4 t3883;
  ddi_4 t3884;
  ddi_4 t3885;
  ddi_4 t3886;
  ddi_4 t3887;
  ddi_4 t3888;
  ddi_4 t3889;
  ddi_4 t3890;
  ddi_4 t3891;
  ddi_4 t3892;
  ddi_4 t3893;
  ddi_4 t3894;
  ddi_4 t3895;
  ddi_4 t3896;
  ddi_4 t3897;
  ddi_4 t3898;
  ddi_4 t3899;
  ddi_4 t3900;
  ddi_4 t3901;
  ddi_4 t3902;
  ddi_4 t3903;
  ddi_4 t3904;
  ddi_4 t3905;
  ddi_4 t3906;
  ddi_4 t3907;
  ddi_4 t3908;
  ddi_4 t3909;
  ddi_4 t3910;
  ddi_4 t3911;
  ddi_4 t3912;
  ddi_4 t3913;
  ddi_4 t3914;
  ddi_4 t3915;
  ddi_4 t3916;
  ddi_4 t3917;
  ddi_4 t3918;
  ddi_4 t3919;
  ddi_4 t3920;
  ddi_4 t3921;
  ddi_4 t3922;
  ddi_4 t3923;
  ddi_4 t3924;
  ddi_4 t3925;
  ddi_4 t3926;
  ddi_4 t3927;
  ddi_4 t3928;
  ddi_4 t3929;
  ddi_4 t3930;
  ddi_4 t3931;
  ddi_4 t3932;
  ddi_4 t3933;
  ddi_4 t3934;
  ddi_4 t3935;
  ddi_4 t3936;
  ddi_4 t3937;
  ddi_4 t3938;
  ddi_4 t3939;
  ddi_4 t3940;
  ddi_4 t3941;
  ddi_4 t3942;
  ddi_4 t3943;
  ddi_4 t3944;
  ddi_4 t3945;
  ddi_4 t3946;
  ddi_4 t3947;
  ddi_4 t3948;
  ddi_4 t3949;
  ddi_4 t3950;
  ddi_4 t3951;
  ddi_4 t3952;
  ddi_4 t3953;
  ddi_4 t3954;
  ddi_4 t3955;
  ddi_4 t3956;
  ddi_4 t3957;
  ddi_4 t3958;
  ddi_4 t3959;
  ddi_4 t3960;
  ddi_4 t3961;
  ddi_4 t3962;
  ddi_4 t3963;
  ddi_4 t3964;
  ddi_4 t3965;
  ddi_4 t3966;
  ddi_4 t3967;
  ddi_4 t3968;
  ddi_4 t3969;
  ddi_4 t3970;
  ddi_4 t3971;
  ddi_4 t3972;
  ddi_4 t3973;
  ddi_4 t3974;
  ddi_4 t3975;
  ddi_4 t3976;
  ddi_4 t3977;
  ddi_4 t3978;
  ddi_4 t3979;
  ddi_4 t3980;
  ddi_4 t3981;
  ddi_4 t3982;
  ddi_4 t3983;
  ddi_4 t3984;
  ddi_4 t3985;
  ddi_4 t3986;
  ddi_4 t3987;
  ddi_4 t3988;
  ddi_4 t3989;
  ddi_4 t3990;
  ddi_4 t3991;
  ddi_4 t3992;
  ddi_4 t3993;
  ddi_4 t3994;
  ddi_4 t3995;
  ddi_4 t3996;
  ddi_4 t3997;
  ddi_4 t3998;
  ddi_4 t3999;
  ddi_4 t4000;
  ddi_4 t4001;
  ddi_4 t4002;
  ddi_4 t4003;
  ddi_4 t4004;
  ddi_4 t4005;
  ddi_4 t4006;
  ddi_4 t4007;
  ddi_4 t4008;
  ddi_4 t4009;
  ddi_4 t4010;
  ddi_4 t4011;
  ddi_4 t4012;
  ddi_4 t4013;
  ddi_4 t4014;
  ddi_4 t4015;
  ddi_4 t4016;
  ddi_4 t4017;
  ddi_4 t4018;
  ddi_4 t4019;
  ddi_4 t4020;
  ddi_4 t4021;
  ddi_4 t4022;
  ddi_4 t4023;
  ddi_4 t4024;
  ddi_4 t4025;
  ddi_4 t4026;
  ddi_4 t4027;
  ddi_4 t4028;
  ddi_4 t4029;
  ddi_4 t4030;
  ddi_4 t4031;
  ddi_4 t4032;
  ddi_4 t4033;
  ddi_4 t4034;
  ddi_4 t4035;
  ddi_4 t4036;
  ddi_4 t4037;
  ddi_4 t4038;
  ddi_4 t4039;
  ddi_4 t4040;
  ddi_4 t4041;
  ddi_4 t4042;
  ddi_4 t4043;
  ddi_4 t4044;
  ddi_4 t4045;
  ddi_4 t4046;
  ddi_4 t4047;
  ddi_4 t4048;
  ddi_4 t4049;
  ddi_4 t4050;
  ddi_4 t4051;
  ddi_4 t4052;
  ddi_4 t4053;
  ddi_4 t4054;
  ddi_4 t4055;
  ddi_4 t4056;
  ddi_4 t4057;
  ddi_4 t4058;
  ddi_4 t4059;
  ddi_4 t4060;
  ddi_4 t4061;
  ddi_4 t4062;
  ddi_4 t4063;
  ddi_4 t4064;
  ddi_4 t4065;
  ddi_4 t4066;
  ddi_4 t4067;
  ddi_4 t4068;
  ddi_4 t4069;
  ddi_4 t4070;
  ddi_4 t4071;
  ddi_4 t4072;
  ddi_4 t4073;
  ddi_4 t4074;
  ddi_4 t4075;
  ddi_4 t4076;
  ddi_4 t4077;
  ddi_4 t4078;
  ddi_4 t4079;
  ddi_4 t4080;
  ddi_4 t4081;
  ddi_4 t4082;
  ddi_4 t4083;
  ddi_4 t4084;
  ddi_4 t4085;
  ddi_4 t4086;
  ddi_4 t4087;
  ddi_4 t4088;
  ddi_4 t4089;
  ddi_4 t4090;
  ddi_4 t4091;
  ddi_4 t4092;
  ddi_4 t4093;
  ddi_4 t4094;
  ddi_4 t4095;
  ddi_4 t4096;
  ddi_4 t4097;
  ddi_4 t4098;
  ddi_4 t4099;
  ddi_4 t4100;
  ddi_4 t4101;
  ddi_4 t4102;
  ddi_4 t4103;
  ddi_4 t4104;
  ddi_4 t4105;
  ddi_4 t4106;
  ddi_4 t4107;
  ddi_4 t4108;
  ddi_4 t4109;
  ddi_4 *a1282;
  ddi_4 *a1309;
  a1282 = ((ddi_4 *)X);
  s3878 = *(a1282);
  s3879 = *((a1282 + 1));
  s3880 = _igen_dd_mm256_permute2f128_pd(s3878, s3879, (0) | ((2) << 4));
  s3881 = _igen_dd_mm256_permute2f128_pd(s3878, s3879, (1) | ((3) << 4));
  s3882 = _igen_dd_mm256_unpacklo_pd(s3880, s3881);
  s3883 = _igen_dd_mm256_unpackhi_pd(s3880, s3881);
  s3884 = *((a1282 + 64));
  s3885 = *((a1282 + 65));
  s3886 = _igen_dd_mm256_permute2f128_pd(s3884, s3885, (0) | ((2) << 4));
  s3887 = _igen_dd_mm256_permute2f128_pd(s3884, s3885, (1) | ((3) << 4));
  s3888 = _igen_dd_mm256_unpacklo_pd(s3886, s3887);
  s3889 = _igen_dd_mm256_unpackhi_pd(s3886, s3887);
  t3112 = _igen_dd_mm256_add_pd(s3882, s3888);
  t3113 = _igen_dd_mm256_add_pd(s3883, s3889);
  t3114 = _igen_dd_mm256_sub_pd(s3882, s3888);
  t3115 = _igen_dd_mm256_sub_pd(s3883, s3889);
  s3890 = *((a1282 + 32));
  s3891 = *((a1282 + 33));
  s3892 = _igen_dd_mm256_permute2f128_pd(s3890, s3891, (0) | ((2) << 4));
  s3893 = _igen_dd_mm256_permute2f128_pd(s3890, s3891, (1) | ((3) << 4));
  s3894 = _igen_dd_mm256_unpacklo_pd(s3892, s3893);
  s3895 = _igen_dd_mm256_unpackhi_pd(s3892, s3893);
  s3896 = *((a1282 + 96));
  s3897 = *((a1282 + 97));
  s3898 = _igen_dd_mm256_permute2f128_pd(s3896, s3897, (0) | ((2) << 4));
  s3899 = _igen_dd_mm256_permute2f128_pd(s3896, s3897, (1) | ((3) << 4));
  s3900 = _igen_dd_mm256_unpacklo_pd(s3898, s3899);
  s3901 = _igen_dd_mm256_unpackhi_pd(s3898, s3899);
  t3116 = _igen_dd_mm256_add_pd(s3894, s3900);
  t3117 = _igen_dd_mm256_add_pd(s3895, s3901);
  t3118 = _igen_dd_mm256_sub_pd(s3894, s3900);
  t3119 = _igen_dd_mm256_sub_pd(s3895, s3901);
  t3120 = _igen_dd_mm256_add_pd(t3112, t3116);
  t3121 = _igen_dd_mm256_add_pd(t3113, t3117);
  t3122 = _igen_dd_mm256_sub_pd(t3112, t3116);
  t3123 = _igen_dd_mm256_sub_pd(t3113, t3117);
  t3124 = _igen_dd_mm256_sub_pd(t3114, t3119);
  t3125 = _igen_dd_mm256_add_pd(t3115, t3118);
  t3126 = _igen_dd_mm256_add_pd(t3114, t3119);
  t3127 = _igen_dd_mm256_sub_pd(t3115, t3118);
  s3902 = *((a1282 + 4));
  s3903 = *((a1282 + 5));
  s3904 = _igen_dd_mm256_permute2f128_pd(s3902, s3903, (0) | ((2) << 4));
  s3905 = _igen_dd_mm256_permute2f128_pd(s3902, s3903, (1) | ((3) << 4));
  s3906 = _igen_dd_mm256_unpacklo_pd(s3904, s3905);
  s3907 = _igen_dd_mm256_unpackhi_pd(s3904, s3905);
  s3908 = *((a1282 + 68));
  s3909 = *((a1282 + 69));
  s3910 = _igen_dd_mm256_permute2f128_pd(s3908, s3909, (0) | ((2) << 4));
  s3911 = _igen_dd_mm256_permute2f128_pd(s3908, s3909, (1) | ((3) << 4));
  s3912 = _igen_dd_mm256_unpacklo_pd(s3910, s3911);
  s3913 = _igen_dd_mm256_unpackhi_pd(s3910, s3911);
  t3128 = _igen_dd_mm256_add_pd(s3906, s3912);
  t3129 = _igen_dd_mm256_add_pd(s3907, s3913);
  t3130 = _igen_dd_mm256_sub_pd(s3906, s3912);
  t3131 = _igen_dd_mm256_sub_pd(s3907, s3913);
  s3914 = *((a1282 + 36));
  s3915 = *((a1282 + 37));
  s3916 = _igen_dd_mm256_permute2f128_pd(s3914, s3915, (0) | ((2) << 4));
  s3917 = _igen_dd_mm256_permute2f128_pd(s3914, s3915, (1) | ((3) << 4));
  s3918 = _igen_dd_mm256_unpacklo_pd(s3916, s3917);
  s3919 = _igen_dd_mm256_unpackhi_pd(s3916, s3917);
  s3920 = *((a1282 + 100));
  s3921 = *((a1282 + 101));
  s3922 = _igen_dd_mm256_permute2f128_pd(s3920, s3921, (0) | ((2) << 4));
  s3923 = _igen_dd_mm256_permute2f128_pd(s3920, s3921, (1) | ((3) << 4));
  s3924 = _igen_dd_mm256_unpacklo_pd(s3922, s3923);
  s3925 = _igen_dd_mm256_unpackhi_pd(s3922, s3923);
  t3132 = _igen_dd_mm256_add_pd(s3918, s3924);
  t3133 = _igen_dd_mm256_add_pd(s3919, s3925);
  t3134 = _igen_dd_mm256_sub_pd(s3918, s3924);
  t3135 = _igen_dd_mm256_sub_pd(s3919, s3925);
  t3136 = _igen_dd_mm256_add_pd(t3128, t3132);
  t3137 = _igen_dd_mm256_add_pd(t3129, t3133);
  t3138 = _igen_dd_mm256_sub_pd(t3128, t3132);
  t3139 = _igen_dd_mm256_sub_pd(t3129, t3133);
  dd_I _t1 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                        0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t2 = _igen_dd_mm256_set1_pd(_t1);
  dd_I _t3 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                        0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t4 = _igen_dd_mm256_set1_pd(_t3);
  ddi_4 _t5 = _igen_dd_mm256_mul_pd(_t2, t3138);
  ddi_4 _t6 = _igen_dd_mm256_mul_pd(_t4, t3139);
  s3926 = _igen_dd_mm256_sub_pd(_t5, _t6);
  dd_I _t7 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                        0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t8 = _igen_dd_mm256_set1_pd(_t7);
  dd_I _t9 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                        0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t10 = _igen_dd_mm256_set1_pd(_t9);
  ddi_4 _t11 = _igen_dd_mm256_mul_pd(_t8, t3138);
  ddi_4 _t12 = _igen_dd_mm256_mul_pd(_t10, t3139);
  s3927 = _igen_dd_mm256_add_pd(_t11, _t12);
  t3140 = _igen_dd_mm256_sub_pd(t3130, t3135);
  t3141 = _igen_dd_mm256_add_pd(t3131, t3134);
  t3142 = _igen_dd_mm256_add_pd(t3130, t3135);
  t3143 = _igen_dd_mm256_sub_pd(t3131, t3134);
  dd_I _t13 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                         0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t14 = _igen_dd_mm256_set1_pd(_t13);
  dd_I _t15 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                         0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t16 = _igen_dd_mm256_set1_pd(_t15);
  ddi_4 _t17 = _igen_dd_mm256_mul_pd(_t14, t3140);
  ddi_4 _t18 = _igen_dd_mm256_mul_pd(_t16, t3141);
  s3928 = _igen_dd_mm256_sub_pd(_t17, _t18);
  dd_I _t19 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                         0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t20 = _igen_dd_mm256_set1_pd(_t19);
  dd_I _t21 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                         0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t22 = _igen_dd_mm256_set1_pd(_t21);
  ddi_4 _t23 = _igen_dd_mm256_mul_pd(_t20, t3140);
  ddi_4 _t24 = _igen_dd_mm256_mul_pd(_t22, t3141);
  s3929 = _igen_dd_mm256_add_pd(_t23, _t24);
  dd_I _t25 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                         0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t26 = _igen_dd_mm256_set1_pd(_t25);
  dd_I _t27 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                         0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t28 = _igen_dd_mm256_set1_pd(_t27);
  ddi_4 _t29 = _igen_dd_mm256_mul_pd(_t26, t3142);
  ddi_4 _t30 = _igen_dd_mm256_mul_pd(_t28, t3143);
  s3930 = _igen_dd_mm256_sub_pd(_t29, _t30);
  dd_I _t31 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                         0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t32 = _igen_dd_mm256_set1_pd(_t31);
  dd_I _t33 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                         0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t34 = _igen_dd_mm256_set1_pd(_t33);
  ddi_4 _t35 = _igen_dd_mm256_mul_pd(_t32, t3142);
  ddi_4 _t36 = _igen_dd_mm256_mul_pd(_t34, t3143);
  s3931 = _igen_dd_mm256_add_pd(_t35, _t36);
  s3932 = *((a1282 + 8));
  s3933 = *((a1282 + 9));
  s3934 = _igen_dd_mm256_permute2f128_pd(s3932, s3933, (0) | ((2) << 4));
  s3935 = _igen_dd_mm256_permute2f128_pd(s3932, s3933, (1) | ((3) << 4));
  s3936 = _igen_dd_mm256_unpacklo_pd(s3934, s3935);
  s3937 = _igen_dd_mm256_unpackhi_pd(s3934, s3935);
  s3938 = *((a1282 + 72));
  s3939 = *((a1282 + 73));
  s3940 = _igen_dd_mm256_permute2f128_pd(s3938, s3939, (0) | ((2) << 4));
  s3941 = _igen_dd_mm256_permute2f128_pd(s3938, s3939, (1) | ((3) << 4));
  s3942 = _igen_dd_mm256_unpacklo_pd(s3940, s3941);
  s3943 = _igen_dd_mm256_unpackhi_pd(s3940, s3941);
  t3144 = _igen_dd_mm256_add_pd(s3936, s3942);
  t3145 = _igen_dd_mm256_add_pd(s3937, s3943);
  t3146 = _igen_dd_mm256_sub_pd(s3936, s3942);
  t3147 = _igen_dd_mm256_sub_pd(s3937, s3943);
  s3944 = *((a1282 + 40));
  s3945 = *((a1282 + 41));
  s3946 = _igen_dd_mm256_permute2f128_pd(s3944, s3945, (0) | ((2) << 4));
  s3947 = _igen_dd_mm256_permute2f128_pd(s3944, s3945, (1) | ((3) << 4));
  s3948 = _igen_dd_mm256_unpacklo_pd(s3946, s3947);
  s3949 = _igen_dd_mm256_unpackhi_pd(s3946, s3947);
  s3950 = *((a1282 + 104));
  s3951 = *((a1282 + 105));
  s3952 = _igen_dd_mm256_permute2f128_pd(s3950, s3951, (0) | ((2) << 4));
  s3953 = _igen_dd_mm256_permute2f128_pd(s3950, s3951, (1) | ((3) << 4));
  s3954 = _igen_dd_mm256_unpacklo_pd(s3952, s3953);
  s3955 = _igen_dd_mm256_unpackhi_pd(s3952, s3953);
  t3148 = _igen_dd_mm256_add_pd(s3948, s3954);
  t3149 = _igen_dd_mm256_add_pd(s3949, s3955);
  t3150 = _igen_dd_mm256_sub_pd(s3948, s3954);
  t3151 = _igen_dd_mm256_sub_pd(s3949, s3955);
  t3152 = _igen_dd_mm256_add_pd(t3144, t3148);
  t3153 = _igen_dd_mm256_add_pd(t3145, t3149);
  t3154 = _igen_dd_mm256_sub_pd(t3144, t3148);
  t3155 = _igen_dd_mm256_sub_pd(t3145, t3149);
  dd_I _t37 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t38 = _igen_dd_mm256_set1_pd(_t37);
  ddi_4 _t39 = _igen_dd_mm256_sub_pd(t3154, t3155);
  s3956 = _igen_dd_mm256_mul_pd(_t38, _t39);
  dd_I _t40 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t41 = _igen_dd_mm256_set1_pd(_t40);
  ddi_4 _t42 = _igen_dd_mm256_add_pd(t3154, t3155);
  s3957 = _igen_dd_mm256_mul_pd(_t41, _t42);
  t3156 = _igen_dd_mm256_sub_pd(t3146, t3151);
  t3157 = _igen_dd_mm256_add_pd(t3147, t3150);
  t3158 = _igen_dd_mm256_add_pd(t3146, t3151);
  t3159 = _igen_dd_mm256_sub_pd(t3147, t3150);
  dd_I _t43 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t44 = _igen_dd_mm256_set1_pd(_t43);
  dd_I _t45 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t46 = _igen_dd_mm256_set1_pd(_t45);
  ddi_4 _t47 = _igen_dd_mm256_mul_pd(_t44, t3156);
  ddi_4 _t48 = _igen_dd_mm256_mul_pd(_t46, t3157);
  s3958 = _igen_dd_mm256_sub_pd(_t47, _t48);
  dd_I _t49 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t50 = _igen_dd_mm256_set1_pd(_t49);
  dd_I _t51 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t52 = _igen_dd_mm256_set1_pd(_t51);
  ddi_4 _t53 = _igen_dd_mm256_mul_pd(_t50, t3156);
  ddi_4 _t54 = _igen_dd_mm256_mul_pd(_t52, t3157);
  s3959 = _igen_dd_mm256_add_pd(_t53, _t54);
  dd_I _t55 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t56 = _igen_dd_mm256_set1_pd(_t55);
  dd_I _t57 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t58 = _igen_dd_mm256_set1_pd(_t57);
  ddi_4 _t59 = _igen_dd_mm256_mul_pd(_t56, t3158);
  ddi_4 _t60 = _igen_dd_mm256_mul_pd(_t58, t3159);
  s3960 = _igen_dd_mm256_sub_pd(_t59, _t60);
  dd_I _t61 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t62 = _igen_dd_mm256_set1_pd(_t61);
  dd_I _t63 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t64 = _igen_dd_mm256_set1_pd(_t63);
  ddi_4 _t65 = _igen_dd_mm256_mul_pd(_t62, t3158);
  ddi_4 _t66 = _igen_dd_mm256_mul_pd(_t64, t3159);
  s3961 = _igen_dd_mm256_add_pd(_t65, _t66);
  s3962 = *((a1282 + 12));
  s3963 = *((a1282 + 13));
  s3964 = _igen_dd_mm256_permute2f128_pd(s3962, s3963, (0) | ((2) << 4));
  s3965 = _igen_dd_mm256_permute2f128_pd(s3962, s3963, (1) | ((3) << 4));
  s3966 = _igen_dd_mm256_unpacklo_pd(s3964, s3965);
  s3967 = _igen_dd_mm256_unpackhi_pd(s3964, s3965);
  s3968 = *((a1282 + 76));
  s3969 = *((a1282 + 77));
  s3970 = _igen_dd_mm256_permute2f128_pd(s3968, s3969, (0) | ((2) << 4));
  s3971 = _igen_dd_mm256_permute2f128_pd(s3968, s3969, (1) | ((3) << 4));
  s3972 = _igen_dd_mm256_unpacklo_pd(s3970, s3971);
  s3973 = _igen_dd_mm256_unpackhi_pd(s3970, s3971);
  t3160 = _igen_dd_mm256_add_pd(s3966, s3972);
  t3161 = _igen_dd_mm256_add_pd(s3967, s3973);
  t3162 = _igen_dd_mm256_sub_pd(s3966, s3972);
  t3163 = _igen_dd_mm256_sub_pd(s3967, s3973);
  s3974 = *((a1282 + 44));
  s3975 = *((a1282 + 45));
  s3976 = _igen_dd_mm256_permute2f128_pd(s3974, s3975, (0) | ((2) << 4));
  s3977 = _igen_dd_mm256_permute2f128_pd(s3974, s3975, (1) | ((3) << 4));
  s3978 = _igen_dd_mm256_unpacklo_pd(s3976, s3977);
  s3979 = _igen_dd_mm256_unpackhi_pd(s3976, s3977);
  s3980 = *((a1282 + 108));
  s3981 = *((a1282 + 109));
  s3982 = _igen_dd_mm256_permute2f128_pd(s3980, s3981, (0) | ((2) << 4));
  s3983 = _igen_dd_mm256_permute2f128_pd(s3980, s3981, (1) | ((3) << 4));
  s3984 = _igen_dd_mm256_unpacklo_pd(s3982, s3983);
  s3985 = _igen_dd_mm256_unpackhi_pd(s3982, s3983);
  t3164 = _igen_dd_mm256_add_pd(s3978, s3984);
  t3165 = _igen_dd_mm256_add_pd(s3979, s3985);
  t3166 = _igen_dd_mm256_sub_pd(s3978, s3984);
  t3167 = _igen_dd_mm256_sub_pd(s3979, s3985);
  t3168 = _igen_dd_mm256_add_pd(t3160, t3164);
  t3169 = _igen_dd_mm256_add_pd(t3161, t3165);
  t3170 = _igen_dd_mm256_sub_pd(t3160, t3164);
  t3171 = _igen_dd_mm256_sub_pd(t3161, t3165);
  dd_I _t67 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t68 = _igen_dd_mm256_set1_pd(_t67);
  dd_I _t69 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t70 = _igen_dd_mm256_set1_pd(_t69);
  ddi_4 _t71 = _igen_dd_mm256_mul_pd(_t68, t3170);
  ddi_4 _t72 = _igen_dd_mm256_mul_pd(_t70, t3171);
  s3986 = _igen_dd_mm256_sub_pd(_t71, _t72);
  dd_I _t73 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t74 = _igen_dd_mm256_set1_pd(_t73);
  dd_I _t75 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t76 = _igen_dd_mm256_set1_pd(_t75);
  ddi_4 _t77 = _igen_dd_mm256_mul_pd(_t74, t3170);
  ddi_4 _t78 = _igen_dd_mm256_mul_pd(_t76, t3171);
  s3987 = _igen_dd_mm256_add_pd(_t77, _t78);
  t3172 = _igen_dd_mm256_sub_pd(t3162, t3167);
  t3173 = _igen_dd_mm256_add_pd(t3163, t3166);
  t3174 = _igen_dd_mm256_add_pd(t3162, t3167);
  t3175 = _igen_dd_mm256_sub_pd(t3163, t3166);
  dd_I _t79 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                         0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t80 = _igen_dd_mm256_set1_pd(_t79);
  dd_I _t81 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                         0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t82 = _igen_dd_mm256_set1_pd(_t81);
  ddi_4 _t83 = _igen_dd_mm256_mul_pd(_t80, t3172);
  ddi_4 _t84 = _igen_dd_mm256_mul_pd(_t82, t3173);
  s3988 = _igen_dd_mm256_sub_pd(_t83, _t84);
  dd_I _t85 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                         0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t86 = _igen_dd_mm256_set1_pd(_t85);
  dd_I _t87 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                         0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t88 = _igen_dd_mm256_set1_pd(_t87);
  ddi_4 _t89 = _igen_dd_mm256_mul_pd(_t86, t3172);
  ddi_4 _t90 = _igen_dd_mm256_mul_pd(_t88, t3173);
  s3989 = _igen_dd_mm256_add_pd(_t89, _t90);
  dd_I _t91 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                         0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t92 = _ia_neg_dd(_t91);
  ddi_4 _t93 = _igen_dd_mm256_set1_pd(_t92);
  dd_I _t94 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                         0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t95 = _igen_dd_mm256_set1_pd(_t94);
  ddi_4 _t96 = _igen_dd_mm256_mul_pd(_t93, t3174);
  ddi_4 _t97 = _igen_dd_mm256_mul_pd(_t95, t3175);
  s3990 = _igen_dd_mm256_sub_pd(_t96, _t97);
  dd_I _t98 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                         0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t99 = _igen_dd_mm256_set1_pd(_t98);
  dd_I _t100 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t101 = _ia_neg_dd(_t100);
  ddi_4 _t102 = _igen_dd_mm256_set1_pd(_t101);
  ddi_4 _t103 = _igen_dd_mm256_mul_pd(_t99, t3174);
  ddi_4 _t104 = _igen_dd_mm256_mul_pd(_t102, t3175);
  s3991 = _igen_dd_mm256_add_pd(_t103, _t104);
  s3992 = *((a1282 + 16));
  s3993 = *((a1282 + 17));
  s3994 = _igen_dd_mm256_permute2f128_pd(s3992, s3993, (0) | ((2) << 4));
  s3995 = _igen_dd_mm256_permute2f128_pd(s3992, s3993, (1) | ((3) << 4));
  s3996 = _igen_dd_mm256_unpacklo_pd(s3994, s3995);
  s3997 = _igen_dd_mm256_unpackhi_pd(s3994, s3995);
  s3998 = *((a1282 + 80));
  s3999 = *((a1282 + 81));
  s4000 = _igen_dd_mm256_permute2f128_pd(s3998, s3999, (0) | ((2) << 4));
  s4001 = _igen_dd_mm256_permute2f128_pd(s3998, s3999, (1) | ((3) << 4));
  s4002 = _igen_dd_mm256_unpacklo_pd(s4000, s4001);
  s4003 = _igen_dd_mm256_unpackhi_pd(s4000, s4001);
  t3176 = _igen_dd_mm256_add_pd(s3996, s4002);
  t3177 = _igen_dd_mm256_add_pd(s3997, s4003);
  t3178 = _igen_dd_mm256_sub_pd(s3996, s4002);
  t3179 = _igen_dd_mm256_sub_pd(s3997, s4003);
  s4004 = *((a1282 + 48));
  s4005 = *((a1282 + 49));
  s4006 = _igen_dd_mm256_permute2f128_pd(s4004, s4005, (0) | ((2) << 4));
  s4007 = _igen_dd_mm256_permute2f128_pd(s4004, s4005, (1) | ((3) << 4));
  s4008 = _igen_dd_mm256_unpacklo_pd(s4006, s4007);
  s4009 = _igen_dd_mm256_unpackhi_pd(s4006, s4007);
  s4010 = *((a1282 + 112));
  s4011 = *((a1282 + 113));
  s4012 = _igen_dd_mm256_permute2f128_pd(s4010, s4011, (0) | ((2) << 4));
  s4013 = _igen_dd_mm256_permute2f128_pd(s4010, s4011, (1) | ((3) << 4));
  s4014 = _igen_dd_mm256_unpacklo_pd(s4012, s4013);
  s4015 = _igen_dd_mm256_unpackhi_pd(s4012, s4013);
  t3180 = _igen_dd_mm256_add_pd(s4008, s4014);
  t3181 = _igen_dd_mm256_add_pd(s4009, s4015);
  t3182 = _igen_dd_mm256_sub_pd(s4008, s4014);
  t3183 = _igen_dd_mm256_sub_pd(s4009, s4015);
  t3184 = _igen_dd_mm256_add_pd(t3176, t3180);
  t3185 = _igen_dd_mm256_add_pd(t3177, t3181);
  t3186 = _igen_dd_mm256_sub_pd(t3176, t3180);
  t3187 = _igen_dd_mm256_sub_pd(t3177, t3181);
  t3188 = _igen_dd_mm256_sub_pd(t3178, t3183);
  t3189 = _igen_dd_mm256_add_pd(t3179, t3182);
  dd_I _t105 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t106 = _igen_dd_mm256_set1_pd(_t105);
  ddi_4 _t107 = _igen_dd_mm256_sub_pd(t3188, t3189);
  s4016 = _igen_dd_mm256_mul_pd(_t106, _t107);
  dd_I _t108 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t109 = _igen_dd_mm256_set1_pd(_t108);
  ddi_4 _t110 = _igen_dd_mm256_add_pd(t3188, t3189);
  s4017 = _igen_dd_mm256_mul_pd(_t109, _t110);
  dd_I _t111 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t112 = _ia_neg_dd(_t111);
  ddi_4 _t113 = _igen_dd_mm256_set1_pd(_t112);
  ddi_4 _t114 = _igen_dd_mm256_add_pd(t3178, t3183);
  a1283 = _igen_dd_mm256_mul_pd(_t113, _t114);
  dd_I _t115 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t116 = _igen_dd_mm256_set1_pd(_t115);
  ddi_4 _t117 = _igen_dd_mm256_sub_pd(t3179, t3182);
  a1284 = _igen_dd_mm256_mul_pd(_t116, _t117);
  s4018 = _igen_dd_mm256_sub_pd(a1283, a1284);
  s4019 = _igen_dd_mm256_add_pd(a1283, a1284);
  s4020 = *((a1282 + 20));
  s4021 = *((a1282 + 21));
  s4022 = _igen_dd_mm256_permute2f128_pd(s4020, s4021, (0) | ((2) << 4));
  s4023 = _igen_dd_mm256_permute2f128_pd(s4020, s4021, (1) | ((3) << 4));
  s4024 = _igen_dd_mm256_unpacklo_pd(s4022, s4023);
  s4025 = _igen_dd_mm256_unpackhi_pd(s4022, s4023);
  s4026 = *((a1282 + 84));
  s4027 = *((a1282 + 85));
  s4028 = _igen_dd_mm256_permute2f128_pd(s4026, s4027, (0) | ((2) << 4));
  s4029 = _igen_dd_mm256_permute2f128_pd(s4026, s4027, (1) | ((3) << 4));
  s4030 = _igen_dd_mm256_unpacklo_pd(s4028, s4029);
  s4031 = _igen_dd_mm256_unpackhi_pd(s4028, s4029);
  t3190 = _igen_dd_mm256_add_pd(s4024, s4030);
  t3191 = _igen_dd_mm256_add_pd(s4025, s4031);
  t3192 = _igen_dd_mm256_sub_pd(s4024, s4030);
  t3193 = _igen_dd_mm256_sub_pd(s4025, s4031);
  s4032 = *((a1282 + 52));
  s4033 = *((a1282 + 53));
  s4034 = _igen_dd_mm256_permute2f128_pd(s4032, s4033, (0) | ((2) << 4));
  s4035 = _igen_dd_mm256_permute2f128_pd(s4032, s4033, (1) | ((3) << 4));
  s4036 = _igen_dd_mm256_unpacklo_pd(s4034, s4035);
  s4037 = _igen_dd_mm256_unpackhi_pd(s4034, s4035);
  s4038 = *((a1282 + 116));
  s4039 = *((a1282 + 117));
  s4040 = _igen_dd_mm256_permute2f128_pd(s4038, s4039, (0) | ((2) << 4));
  s4041 = _igen_dd_mm256_permute2f128_pd(s4038, s4039, (1) | ((3) << 4));
  s4042 = _igen_dd_mm256_unpacklo_pd(s4040, s4041);
  s4043 = _igen_dd_mm256_unpackhi_pd(s4040, s4041);
  t3194 = _igen_dd_mm256_add_pd(s4036, s4042);
  t3195 = _igen_dd_mm256_add_pd(s4037, s4043);
  t3196 = _igen_dd_mm256_sub_pd(s4036, s4042);
  t3197 = _igen_dd_mm256_sub_pd(s4037, s4043);
  t3198 = _igen_dd_mm256_add_pd(t3190, t3194);
  t3199 = _igen_dd_mm256_add_pd(t3191, t3195);
  t3200 = _igen_dd_mm256_sub_pd(t3190, t3194);
  t3201 = _igen_dd_mm256_sub_pd(t3191, t3195);
  dd_I _t118 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t119 = _ia_neg_dd(_t118);
  ddi_4 _t120 = _igen_dd_mm256_set1_pd(_t119);
  dd_I _t121 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t122 = _igen_dd_mm256_set1_pd(_t121);
  ddi_4 _t123 = _igen_dd_mm256_mul_pd(_t120, t3200);
  ddi_4 _t124 = _igen_dd_mm256_mul_pd(_t122, t3201);
  s4044 = _igen_dd_mm256_sub_pd(_t123, _t124);
  dd_I _t125 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t126 = _igen_dd_mm256_set1_pd(_t125);
  dd_I _t127 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t128 = _ia_neg_dd(_t127);
  ddi_4 _t129 = _igen_dd_mm256_set1_pd(_t128);
  ddi_4 _t130 = _igen_dd_mm256_mul_pd(_t126, t3200);
  ddi_4 _t131 = _igen_dd_mm256_mul_pd(_t129, t3201);
  s4045 = _igen_dd_mm256_add_pd(_t130, _t131);
  t3202 = _igen_dd_mm256_sub_pd(t3192, t3197);
  t3203 = _igen_dd_mm256_add_pd(t3193, t3196);
  t3204 = _igen_dd_mm256_add_pd(t3192, t3197);
  t3205 = _igen_dd_mm256_sub_pd(t3193, t3196);
  dd_I _t132 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t133 = _igen_dd_mm256_set1_pd(_t132);
  dd_I _t134 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t135 = _igen_dd_mm256_set1_pd(_t134);
  ddi_4 _t136 = _igen_dd_mm256_mul_pd(_t133, t3202);
  ddi_4 _t137 = _igen_dd_mm256_mul_pd(_t135, t3203);
  s4046 = _igen_dd_mm256_sub_pd(_t136, _t137);
  dd_I _t138 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t139 = _igen_dd_mm256_set1_pd(_t138);
  dd_I _t140 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t141 = _igen_dd_mm256_set1_pd(_t140);
  ddi_4 _t142 = _igen_dd_mm256_mul_pd(_t139, t3202);
  ddi_4 _t143 = _igen_dd_mm256_mul_pd(_t141, t3203);
  s4047 = _igen_dd_mm256_add_pd(_t142, _t143);
  dd_I _t144 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t145 = _ia_neg_dd(_t144);
  ddi_4 _t146 = _igen_dd_mm256_set1_pd(_t145);
  dd_I _t147 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t148 = _igen_dd_mm256_set1_pd(_t147);
  ddi_4 _t149 = _igen_dd_mm256_mul_pd(_t146, t3204);
  ddi_4 _t150 = _igen_dd_mm256_mul_pd(_t148, t3205);
  s4048 = _igen_dd_mm256_sub_pd(_t149, _t150);
  dd_I _t151 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t152 = _igen_dd_mm256_set1_pd(_t151);
  dd_I _t153 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t154 = _ia_neg_dd(_t153);
  ddi_4 _t155 = _igen_dd_mm256_set1_pd(_t154);
  ddi_4 _t156 = _igen_dd_mm256_mul_pd(_t152, t3204);
  ddi_4 _t157 = _igen_dd_mm256_mul_pd(_t155, t3205);
  s4049 = _igen_dd_mm256_add_pd(_t156, _t157);
  s4050 = *((a1282 + 24));
  s4051 = *((a1282 + 25));
  s4052 = _igen_dd_mm256_permute2f128_pd(s4050, s4051, (0) | ((2) << 4));
  s4053 = _igen_dd_mm256_permute2f128_pd(s4050, s4051, (1) | ((3) << 4));
  s4054 = _igen_dd_mm256_unpacklo_pd(s4052, s4053);
  s4055 = _igen_dd_mm256_unpackhi_pd(s4052, s4053);
  s4056 = *((a1282 + 88));
  s4057 = *((a1282 + 89));
  s4058 = _igen_dd_mm256_permute2f128_pd(s4056, s4057, (0) | ((2) << 4));
  s4059 = _igen_dd_mm256_permute2f128_pd(s4056, s4057, (1) | ((3) << 4));
  s4060 = _igen_dd_mm256_unpacklo_pd(s4058, s4059);
  s4061 = _igen_dd_mm256_unpackhi_pd(s4058, s4059);
  t3206 = _igen_dd_mm256_add_pd(s4054, s4060);
  t3207 = _igen_dd_mm256_add_pd(s4055, s4061);
  t3208 = _igen_dd_mm256_sub_pd(s4054, s4060);
  t3209 = _igen_dd_mm256_sub_pd(s4055, s4061);
  s4062 = *((a1282 + 56));
  s4063 = *((a1282 + 57));
  s4064 = _igen_dd_mm256_permute2f128_pd(s4062, s4063, (0) | ((2) << 4));
  s4065 = _igen_dd_mm256_permute2f128_pd(s4062, s4063, (1) | ((3) << 4));
  s4066 = _igen_dd_mm256_unpacklo_pd(s4064, s4065);
  s4067 = _igen_dd_mm256_unpackhi_pd(s4064, s4065);
  s4068 = *((a1282 + 120));
  s4069 = *((a1282 + 121));
  s4070 = _igen_dd_mm256_permute2f128_pd(s4068, s4069, (0) | ((2) << 4));
  s4071 = _igen_dd_mm256_permute2f128_pd(s4068, s4069, (1) | ((3) << 4));
  s4072 = _igen_dd_mm256_unpacklo_pd(s4070, s4071);
  s4073 = _igen_dd_mm256_unpackhi_pd(s4070, s4071);
  t3210 = _igen_dd_mm256_add_pd(s4066, s4072);
  t3211 = _igen_dd_mm256_add_pd(s4067, s4073);
  t3212 = _igen_dd_mm256_sub_pd(s4066, s4072);
  t3213 = _igen_dd_mm256_sub_pd(s4067, s4073);
  t3214 = _igen_dd_mm256_add_pd(t3206, t3210);
  t3215 = _igen_dd_mm256_add_pd(t3207, t3211);
  dd_I _t158 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t159 = _ia_neg_dd(_t158);
  ddi_4 _t160 = _igen_dd_mm256_set1_pd(_t159);
  ddi_4 _t161 = _igen_dd_mm256_sub_pd(t3206, t3210);
  a1285 = _igen_dd_mm256_mul_pd(_t160, _t161);
  dd_I _t162 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t163 = _igen_dd_mm256_set1_pd(_t162);
  ddi_4 _t164 = _igen_dd_mm256_sub_pd(t3207, t3211);
  a1286 = _igen_dd_mm256_mul_pd(_t163, _t164);
  s4074 = _igen_dd_mm256_sub_pd(a1285, a1286);
  s4075 = _igen_dd_mm256_add_pd(a1285, a1286);
  t3216 = _igen_dd_mm256_sub_pd(t3208, t3213);
  t3217 = _igen_dd_mm256_add_pd(t3209, t3212);
  t3218 = _igen_dd_mm256_add_pd(t3208, t3213);
  t3219 = _igen_dd_mm256_sub_pd(t3209, t3212);
  dd_I _t165 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t166 = _igen_dd_mm256_set1_pd(_t165);
  dd_I _t167 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t168 = _igen_dd_mm256_set1_pd(_t167);
  ddi_4 _t169 = _igen_dd_mm256_mul_pd(_t166, t3216);
  ddi_4 _t170 = _igen_dd_mm256_mul_pd(_t168, t3217);
  s4076 = _igen_dd_mm256_sub_pd(_t169, _t170);
  dd_I _t171 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t172 = _igen_dd_mm256_set1_pd(_t171);
  dd_I _t173 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t174 = _igen_dd_mm256_set1_pd(_t173);
  ddi_4 _t175 = _igen_dd_mm256_mul_pd(_t172, t3216);
  ddi_4 _t176 = _igen_dd_mm256_mul_pd(_t174, t3217);
  s4077 = _igen_dd_mm256_add_pd(_t175, _t176);
  dd_I _t177 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t178 = _ia_neg_dd(_t177);
  ddi_4 _t179 = _igen_dd_mm256_set1_pd(_t178);
  dd_I _t180 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t181 = _ia_neg_dd(_t180);
  ddi_4 _t182 = _igen_dd_mm256_set1_pd(_t181);
  ddi_4 _t183 = _igen_dd_mm256_mul_pd(_t179, t3218);
  ddi_4 _t184 = _igen_dd_mm256_mul_pd(_t182, t3219);
  s4078 = _igen_dd_mm256_sub_pd(_t183, _t184);
  dd_I _t185 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t186 = _ia_neg_dd(_t185);
  ddi_4 _t187 = _igen_dd_mm256_set1_pd(_t186);
  dd_I _t188 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t189 = _ia_neg_dd(_t188);
  ddi_4 _t190 = _igen_dd_mm256_set1_pd(_t189);
  ddi_4 _t191 = _igen_dd_mm256_mul_pd(_t187, t3218);
  ddi_4 _t192 = _igen_dd_mm256_mul_pd(_t190, t3219);
  s4079 = _igen_dd_mm256_add_pd(_t191, _t192);
  s4080 = *((a1282 + 28));
  s4081 = *((a1282 + 29));
  s4082 = _igen_dd_mm256_permute2f128_pd(s4080, s4081, (0) | ((2) << 4));
  s4083 = _igen_dd_mm256_permute2f128_pd(s4080, s4081, (1) | ((3) << 4));
  s4084 = _igen_dd_mm256_unpacklo_pd(s4082, s4083);
  s4085 = _igen_dd_mm256_unpackhi_pd(s4082, s4083);
  s4086 = *((a1282 + 92));
  s4087 = *((a1282 + 93));
  s4088 = _igen_dd_mm256_permute2f128_pd(s4086, s4087, (0) | ((2) << 4));
  s4089 = _igen_dd_mm256_permute2f128_pd(s4086, s4087, (1) | ((3) << 4));
  s4090 = _igen_dd_mm256_unpacklo_pd(s4088, s4089);
  s4091 = _igen_dd_mm256_unpackhi_pd(s4088, s4089);
  t3220 = _igen_dd_mm256_add_pd(s4084, s4090);
  t3221 = _igen_dd_mm256_add_pd(s4085, s4091);
  t3222 = _igen_dd_mm256_sub_pd(s4084, s4090);
  t3223 = _igen_dd_mm256_sub_pd(s4085, s4091);
  s4092 = *((a1282 + 60));
  s4093 = *((a1282 + 61));
  s4094 = _igen_dd_mm256_permute2f128_pd(s4092, s4093, (0) | ((2) << 4));
  s4095 = _igen_dd_mm256_permute2f128_pd(s4092, s4093, (1) | ((3) << 4));
  s4096 = _igen_dd_mm256_unpacklo_pd(s4094, s4095);
  s4097 = _igen_dd_mm256_unpackhi_pd(s4094, s4095);
  s4098 = *((a1282 + 124));
  s4099 = *((a1282 + 125));
  s4100 = _igen_dd_mm256_permute2f128_pd(s4098, s4099, (0) | ((2) << 4));
  s4101 = _igen_dd_mm256_permute2f128_pd(s4098, s4099, (1) | ((3) << 4));
  s4102 = _igen_dd_mm256_unpacklo_pd(s4100, s4101);
  s4103 = _igen_dd_mm256_unpackhi_pd(s4100, s4101);
  t3224 = _igen_dd_mm256_add_pd(s4096, s4102);
  t3225 = _igen_dd_mm256_add_pd(s4097, s4103);
  t3226 = _igen_dd_mm256_sub_pd(s4096, s4102);
  t3227 = _igen_dd_mm256_sub_pd(s4097, s4103);
  t3228 = _igen_dd_mm256_add_pd(t3220, t3224);
  t3229 = _igen_dd_mm256_add_pd(t3221, t3225);
  t3230 = _igen_dd_mm256_sub_pd(t3220, t3224);
  t3231 = _igen_dd_mm256_sub_pd(t3221, t3225);
  dd_I _t193 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t194 = _ia_neg_dd(_t193);
  ddi_4 _t195 = _igen_dd_mm256_set1_pd(_t194);
  dd_I _t196 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t197 = _igen_dd_mm256_set1_pd(_t196);
  ddi_4 _t198 = _igen_dd_mm256_mul_pd(_t195, t3230);
  ddi_4 _t199 = _igen_dd_mm256_mul_pd(_t197, t3231);
  s4104 = _igen_dd_mm256_sub_pd(_t198, _t199);
  dd_I _t200 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t201 = _igen_dd_mm256_set1_pd(_t200);
  dd_I _t202 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t203 = _ia_neg_dd(_t202);
  ddi_4 _t204 = _igen_dd_mm256_set1_pd(_t203);
  ddi_4 _t205 = _igen_dd_mm256_mul_pd(_t201, t3230);
  ddi_4 _t206 = _igen_dd_mm256_mul_pd(_t204, t3231);
  s4105 = _igen_dd_mm256_add_pd(_t205, _t206);
  t3232 = _igen_dd_mm256_sub_pd(t3222, t3227);
  t3233 = _igen_dd_mm256_add_pd(t3223, t3226);
  t3234 = _igen_dd_mm256_add_pd(t3222, t3227);
  t3235 = _igen_dd_mm256_sub_pd(t3223, t3226);
  dd_I _t207 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t208 = _igen_dd_mm256_set1_pd(_t207);
  dd_I _t209 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t210 = _igen_dd_mm256_set1_pd(_t209);
  ddi_4 _t211 = _igen_dd_mm256_mul_pd(_t208, t3232);
  ddi_4 _t212 = _igen_dd_mm256_mul_pd(_t210, t3233);
  s4106 = _igen_dd_mm256_sub_pd(_t211, _t212);
  dd_I _t213 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t214 = _igen_dd_mm256_set1_pd(_t213);
  dd_I _t215 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t216 = _igen_dd_mm256_set1_pd(_t215);
  ddi_4 _t217 = _igen_dd_mm256_mul_pd(_t214, t3232);
  ddi_4 _t218 = _igen_dd_mm256_mul_pd(_t216, t3233);
  s4107 = _igen_dd_mm256_add_pd(_t217, _t218);
  dd_I _t219 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t220 = _ia_neg_dd(_t219);
  ddi_4 _t221 = _igen_dd_mm256_set1_pd(_t220);
  dd_I _t222 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t223 = _ia_neg_dd(_t222);
  ddi_4 _t224 = _igen_dd_mm256_set1_pd(_t223);
  ddi_4 _t225 = _igen_dd_mm256_mul_pd(_t221, t3234);
  ddi_4 _t226 = _igen_dd_mm256_mul_pd(_t224, t3235);
  s4108 = _igen_dd_mm256_sub_pd(_t225, _t226);
  dd_I _t227 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t228 = _ia_neg_dd(_t227);
  ddi_4 _t229 = _igen_dd_mm256_set1_pd(_t228);
  dd_I _t230 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t231 = _ia_neg_dd(_t230);
  ddi_4 _t232 = _igen_dd_mm256_set1_pd(_t231);
  ddi_4 _t233 = _igen_dd_mm256_mul_pd(_t229, t3234);
  ddi_4 _t234 = _igen_dd_mm256_mul_pd(_t232, t3235);
  s4109 = _igen_dd_mm256_add_pd(_t233, _t234);
  t3236 = _igen_dd_mm256_add_pd(t3120, t3184);
  t3237 = _igen_dd_mm256_add_pd(t3121, t3185);
  t3238 = _igen_dd_mm256_sub_pd(t3120, t3184);
  t3239 = _igen_dd_mm256_sub_pd(t3121, t3185);
  t3240 = _igen_dd_mm256_add_pd(t3152, t3214);
  t3241 = _igen_dd_mm256_add_pd(t3153, t3215);
  t3242 = _igen_dd_mm256_sub_pd(t3152, t3214);
  t3243 = _igen_dd_mm256_sub_pd(t3153, t3215);
  t3244 = _igen_dd_mm256_add_pd(t3236, t3240);
  t3245 = _igen_dd_mm256_add_pd(t3237, t3241);
  t3246 = _igen_dd_mm256_sub_pd(t3236, t3240);
  t3247 = _igen_dd_mm256_sub_pd(t3237, t3241);
  t3248 = _igen_dd_mm256_sub_pd(t3238, t3243);
  t3249 = _igen_dd_mm256_add_pd(t3239, t3242);
  t3250 = _igen_dd_mm256_add_pd(t3238, t3243);
  t3251 = _igen_dd_mm256_sub_pd(t3239, t3242);
  t3252 = _igen_dd_mm256_add_pd(t3136, t3198);
  t3253 = _igen_dd_mm256_add_pd(t3137, t3199);
  t3254 = _igen_dd_mm256_sub_pd(t3136, t3198);
  t3255 = _igen_dd_mm256_sub_pd(t3137, t3199);
  t3256 = _igen_dd_mm256_add_pd(t3168, t3228);
  t3257 = _igen_dd_mm256_add_pd(t3169, t3229);
  t3258 = _igen_dd_mm256_sub_pd(t3168, t3228);
  t3259 = _igen_dd_mm256_sub_pd(t3169, t3229);
  t3260 = _igen_dd_mm256_add_pd(t3252, t3256);
  t3261 = _igen_dd_mm256_add_pd(t3253, t3257);
  t3262 = _igen_dd_mm256_sub_pd(t3252, t3256);
  t3263 = _igen_dd_mm256_sub_pd(t3253, t3257);
  t3264 = _igen_dd_mm256_sub_pd(t3254, t3259);
  t3265 = _igen_dd_mm256_add_pd(t3255, t3258);
  dd_I _t235 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t236 = _igen_dd_mm256_set1_pd(_t235);
  ddi_4 _t237 = _igen_dd_mm256_sub_pd(t3264, t3265);
  s4110 = _igen_dd_mm256_mul_pd(_t236, _t237);
  dd_I _t238 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t239 = _igen_dd_mm256_set1_pd(_t238);
  ddi_4 _t240 = _igen_dd_mm256_add_pd(t3264, t3265);
  s4111 = _igen_dd_mm256_mul_pd(_t239, _t240);
  dd_I _t241 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t242 = _ia_neg_dd(_t241);
  ddi_4 _t243 = _igen_dd_mm256_set1_pd(_t242);
  ddi_4 _t244 = _igen_dd_mm256_add_pd(t3254, t3259);
  a1287 = _igen_dd_mm256_mul_pd(_t243, _t244);
  dd_I _t245 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t246 = _igen_dd_mm256_set1_pd(_t245);
  ddi_4 _t247 = _igen_dd_mm256_sub_pd(t3255, t3258);
  a1288 = _igen_dd_mm256_mul_pd(_t246, _t247);
  s4112 = _igen_dd_mm256_sub_pd(a1287, a1288);
  s4113 = _igen_dd_mm256_add_pd(a1287, a1288);
  t3266 = _igen_dd_mm256_add_pd(t3244, t3260);
  t3267 = _igen_dd_mm256_add_pd(t3245, t3261);
  t3268 = _igen_dd_mm256_sub_pd(t3244, t3260);
  t3269 = _igen_dd_mm256_sub_pd(t3245, t3261);
  t3270 = _igen_dd_mm256_add_pd(t3248, s4110);
  t3271 = _igen_dd_mm256_add_pd(t3249, s4111);
  t3272 = _igen_dd_mm256_sub_pd(t3248, s4110);
  t3273 = _igen_dd_mm256_sub_pd(t3249, s4111);
  t3274 = _igen_dd_mm256_sub_pd(t3246, t3263);
  t3275 = _igen_dd_mm256_add_pd(t3247, t3262);
  t3276 = _igen_dd_mm256_add_pd(t3246, t3263);
  t3277 = _igen_dd_mm256_sub_pd(t3247, t3262);
  t3278 = _igen_dd_mm256_add_pd(t3250, s4112);
  t3279 = _igen_dd_mm256_sub_pd(t3251, s4113);
  t3280 = _igen_dd_mm256_sub_pd(t3250, s4112);
  t3281 = _igen_dd_mm256_add_pd(t3251, s4113);
  t3282 = _igen_dd_mm256_add_pd(t3124, s4016);
  t3283 = _igen_dd_mm256_add_pd(t3125, s4017);
  t3284 = _igen_dd_mm256_sub_pd(t3124, s4016);
  t3285 = _igen_dd_mm256_sub_pd(t3125, s4017);
  t3286 = _igen_dd_mm256_add_pd(s3958, s4076);
  t3287 = _igen_dd_mm256_add_pd(s3959, s4077);
  t3288 = _igen_dd_mm256_sub_pd(s3958, s4076);
  t3289 = _igen_dd_mm256_sub_pd(s3959, s4077);
  t3290 = _igen_dd_mm256_add_pd(t3282, t3286);
  t3291 = _igen_dd_mm256_add_pd(t3283, t3287);
  t3292 = _igen_dd_mm256_sub_pd(t3282, t3286);
  t3293 = _igen_dd_mm256_sub_pd(t3283, t3287);
  t3294 = _igen_dd_mm256_sub_pd(t3284, t3289);
  t3295 = _igen_dd_mm256_add_pd(t3285, t3288);
  t3296 = _igen_dd_mm256_add_pd(t3284, t3289);
  t3297 = _igen_dd_mm256_sub_pd(t3285, t3288);
  t3298 = _igen_dd_mm256_add_pd(s3928, s4046);
  t3299 = _igen_dd_mm256_add_pd(s3929, s4047);
  t3300 = _igen_dd_mm256_sub_pd(s3928, s4046);
  t3301 = _igen_dd_mm256_sub_pd(s3929, s4047);
  t3302 = _igen_dd_mm256_add_pd(s3988, s4106);
  t3303 = _igen_dd_mm256_add_pd(s3989, s4107);
  t3304 = _igen_dd_mm256_sub_pd(s3988, s4106);
  t3305 = _igen_dd_mm256_sub_pd(s3989, s4107);
  t3306 = _igen_dd_mm256_add_pd(t3298, t3302);
  t3307 = _igen_dd_mm256_add_pd(t3299, t3303);
  t3308 = _igen_dd_mm256_sub_pd(t3298, t3302);
  t3309 = _igen_dd_mm256_sub_pd(t3299, t3303);
  t3310 = _igen_dd_mm256_sub_pd(t3300, t3305);
  t3311 = _igen_dd_mm256_add_pd(t3301, t3304);
  dd_I _t248 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t249 = _igen_dd_mm256_set1_pd(_t248);
  ddi_4 _t250 = _igen_dd_mm256_sub_pd(t3310, t3311);
  s4114 = _igen_dd_mm256_mul_pd(_t249, _t250);
  dd_I _t251 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t252 = _igen_dd_mm256_set1_pd(_t251);
  ddi_4 _t253 = _igen_dd_mm256_add_pd(t3310, t3311);
  s4115 = _igen_dd_mm256_mul_pd(_t252, _t253);
  dd_I _t254 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t255 = _ia_neg_dd(_t254);
  ddi_4 _t256 = _igen_dd_mm256_set1_pd(_t255);
  ddi_4 _t257 = _igen_dd_mm256_add_pd(t3300, t3305);
  a1289 = _igen_dd_mm256_mul_pd(_t256, _t257);
  dd_I _t258 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t259 = _igen_dd_mm256_set1_pd(_t258);
  ddi_4 _t260 = _igen_dd_mm256_sub_pd(t3301, t3304);
  a1290 = _igen_dd_mm256_mul_pd(_t259, _t260);
  s4116 = _igen_dd_mm256_sub_pd(a1289, a1290);
  s4117 = _igen_dd_mm256_add_pd(a1289, a1290);
  t3312 = _igen_dd_mm256_add_pd(t3290, t3306);
  t3313 = _igen_dd_mm256_add_pd(t3291, t3307);
  t3314 = _igen_dd_mm256_sub_pd(t3290, t3306);
  t3315 = _igen_dd_mm256_sub_pd(t3291, t3307);
  t3316 = _igen_dd_mm256_add_pd(t3294, s4114);
  t3317 = _igen_dd_mm256_add_pd(t3295, s4115);
  t3318 = _igen_dd_mm256_sub_pd(t3294, s4114);
  t3319 = _igen_dd_mm256_sub_pd(t3295, s4115);
  t3320 = _igen_dd_mm256_sub_pd(t3292, t3309);
  t3321 = _igen_dd_mm256_add_pd(t3293, t3308);
  t3322 = _igen_dd_mm256_add_pd(t3292, t3309);
  t3323 = _igen_dd_mm256_sub_pd(t3293, t3308);
  t3324 = _igen_dd_mm256_add_pd(t3296, s4116);
  t3325 = _igen_dd_mm256_sub_pd(t3297, s4117);
  t3326 = _igen_dd_mm256_sub_pd(t3296, s4116);
  t3327 = _igen_dd_mm256_add_pd(t3297, s4117);
  t3328 = _igen_dd_mm256_sub_pd(t3122, t3187);
  t3329 = _igen_dd_mm256_add_pd(t3123, t3186);
  t3330 = _igen_dd_mm256_add_pd(t3122, t3187);
  t3331 = _igen_dd_mm256_sub_pd(t3123, t3186);
  t3332 = _igen_dd_mm256_add_pd(s3956, s4074);
  t3333 = _igen_dd_mm256_sub_pd(s3957, s4075);
  t3334 = _igen_dd_mm256_sub_pd(s3956, s4074);
  t3335 = _igen_dd_mm256_add_pd(s3957, s4075);
  t3336 = _igen_dd_mm256_add_pd(t3328, t3332);
  t3337 = _igen_dd_mm256_add_pd(t3329, t3333);
  t3338 = _igen_dd_mm256_sub_pd(t3328, t3332);
  t3339 = _igen_dd_mm256_sub_pd(t3329, t3333);
  t3340 = _igen_dd_mm256_sub_pd(t3330, t3335);
  t3341 = _igen_dd_mm256_add_pd(t3331, t3334);
  t3342 = _igen_dd_mm256_add_pd(t3330, t3335);
  t3343 = _igen_dd_mm256_sub_pd(t3331, t3334);
  t3344 = _igen_dd_mm256_add_pd(s3926, s4044);
  t3345 = _igen_dd_mm256_add_pd(s3927, s4045);
  t3346 = _igen_dd_mm256_sub_pd(s3926, s4044);
  t3347 = _igen_dd_mm256_sub_pd(s3927, s4045);
  t3348 = _igen_dd_mm256_add_pd(s3986, s4104);
  t3349 = _igen_dd_mm256_add_pd(s3987, s4105);
  t3350 = _igen_dd_mm256_sub_pd(s3986, s4104);
  t3351 = _igen_dd_mm256_sub_pd(s3987, s4105);
  t3352 = _igen_dd_mm256_add_pd(t3344, t3348);
  t3353 = _igen_dd_mm256_add_pd(t3345, t3349);
  t3354 = _igen_dd_mm256_sub_pd(t3344, t3348);
  t3355 = _igen_dd_mm256_sub_pd(t3345, t3349);
  t3356 = _igen_dd_mm256_sub_pd(t3346, t3351);
  t3357 = _igen_dd_mm256_add_pd(t3347, t3350);
  dd_I _t261 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t262 = _igen_dd_mm256_set1_pd(_t261);
  ddi_4 _t263 = _igen_dd_mm256_sub_pd(t3356, t3357);
  s4118 = _igen_dd_mm256_mul_pd(_t262, _t263);
  dd_I _t264 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t265 = _igen_dd_mm256_set1_pd(_t264);
  ddi_4 _t266 = _igen_dd_mm256_add_pd(t3356, t3357);
  s4119 = _igen_dd_mm256_mul_pd(_t265, _t266);
  dd_I _t267 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t268 = _ia_neg_dd(_t267);
  ddi_4 _t269 = _igen_dd_mm256_set1_pd(_t268);
  ddi_4 _t270 = _igen_dd_mm256_add_pd(t3346, t3351);
  a1291 = _igen_dd_mm256_mul_pd(_t269, _t270);
  dd_I _t271 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t272 = _igen_dd_mm256_set1_pd(_t271);
  ddi_4 _t273 = _igen_dd_mm256_sub_pd(t3347, t3350);
  a1292 = _igen_dd_mm256_mul_pd(_t272, _t273);
  s4120 = _igen_dd_mm256_sub_pd(a1291, a1292);
  s4121 = _igen_dd_mm256_add_pd(a1291, a1292);
  t3358 = _igen_dd_mm256_add_pd(t3336, t3352);
  t3359 = _igen_dd_mm256_add_pd(t3337, t3353);
  t3360 = _igen_dd_mm256_sub_pd(t3336, t3352);
  t3361 = _igen_dd_mm256_sub_pd(t3337, t3353);
  t3362 = _igen_dd_mm256_add_pd(t3340, s4118);
  t3363 = _igen_dd_mm256_add_pd(t3341, s4119);
  t3364 = _igen_dd_mm256_sub_pd(t3340, s4118);
  t3365 = _igen_dd_mm256_sub_pd(t3341, s4119);
  t3366 = _igen_dd_mm256_sub_pd(t3338, t3355);
  t3367 = _igen_dd_mm256_add_pd(t3339, t3354);
  t3368 = _igen_dd_mm256_add_pd(t3338, t3355);
  t3369 = _igen_dd_mm256_sub_pd(t3339, t3354);
  t3370 = _igen_dd_mm256_add_pd(t3342, s4120);
  t3371 = _igen_dd_mm256_sub_pd(t3343, s4121);
  t3372 = _igen_dd_mm256_sub_pd(t3342, s4120);
  t3373 = _igen_dd_mm256_add_pd(t3343, s4121);
  t3374 = _igen_dd_mm256_add_pd(t3126, s4018);
  t3375 = _igen_dd_mm256_sub_pd(t3127, s4019);
  t3376 = _igen_dd_mm256_sub_pd(t3126, s4018);
  t3377 = _igen_dd_mm256_add_pd(t3127, s4019);
  t3378 = _igen_dd_mm256_add_pd(s3960, s4078);
  t3379 = _igen_dd_mm256_add_pd(s3961, s4079);
  t3380 = _igen_dd_mm256_sub_pd(s3960, s4078);
  t3381 = _igen_dd_mm256_sub_pd(s3961, s4079);
  t3382 = _igen_dd_mm256_add_pd(t3374, t3378);
  t3383 = _igen_dd_mm256_add_pd(t3375, t3379);
  t3384 = _igen_dd_mm256_sub_pd(t3374, t3378);
  t3385 = _igen_dd_mm256_sub_pd(t3375, t3379);
  t3386 = _igen_dd_mm256_sub_pd(t3376, t3381);
  t3387 = _igen_dd_mm256_add_pd(t3377, t3380);
  t3388 = _igen_dd_mm256_add_pd(t3376, t3381);
  t3389 = _igen_dd_mm256_sub_pd(t3377, t3380);
  t3390 = _igen_dd_mm256_add_pd(s3930, s4048);
  t3391 = _igen_dd_mm256_add_pd(s3931, s4049);
  t3392 = _igen_dd_mm256_sub_pd(s3930, s4048);
  t3393 = _igen_dd_mm256_sub_pd(s3931, s4049);
  t3394 = _igen_dd_mm256_add_pd(s3990, s4108);
  t3395 = _igen_dd_mm256_add_pd(s3991, s4109);
  t3396 = _igen_dd_mm256_sub_pd(s3990, s4108);
  t3397 = _igen_dd_mm256_sub_pd(s3991, s4109);
  t3398 = _igen_dd_mm256_add_pd(t3390, t3394);
  t3399 = _igen_dd_mm256_add_pd(t3391, t3395);
  t3400 = _igen_dd_mm256_sub_pd(t3390, t3394);
  t3401 = _igen_dd_mm256_sub_pd(t3391, t3395);
  t3402 = _igen_dd_mm256_sub_pd(t3392, t3397);
  t3403 = _igen_dd_mm256_add_pd(t3393, t3396);
  dd_I _t274 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t275 = _igen_dd_mm256_set1_pd(_t274);
  ddi_4 _t276 = _igen_dd_mm256_sub_pd(t3402, t3403);
  s4122 = _igen_dd_mm256_mul_pd(_t275, _t276);
  dd_I _t277 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t278 = _igen_dd_mm256_set1_pd(_t277);
  ddi_4 _t279 = _igen_dd_mm256_add_pd(t3402, t3403);
  s4123 = _igen_dd_mm256_mul_pd(_t278, _t279);
  dd_I _t280 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t281 = _ia_neg_dd(_t280);
  ddi_4 _t282 = _igen_dd_mm256_set1_pd(_t281);
  ddi_4 _t283 = _igen_dd_mm256_add_pd(t3392, t3397);
  a1293 = _igen_dd_mm256_mul_pd(_t282, _t283);
  dd_I _t284 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t285 = _igen_dd_mm256_set1_pd(_t284);
  ddi_4 _t286 = _igen_dd_mm256_sub_pd(t3393, t3396);
  a1294 = _igen_dd_mm256_mul_pd(_t285, _t286);
  s4124 = _igen_dd_mm256_sub_pd(a1293, a1294);
  s4125 = _igen_dd_mm256_add_pd(a1293, a1294);
  t3404 = _igen_dd_mm256_add_pd(t3382, t3398);
  t3405 = _igen_dd_mm256_add_pd(t3383, t3399);
  t3406 = _igen_dd_mm256_sub_pd(t3382, t3398);
  t3407 = _igen_dd_mm256_sub_pd(t3383, t3399);
  t3408 = _igen_dd_mm256_add_pd(t3386, s4122);
  t3409 = _igen_dd_mm256_add_pd(t3387, s4123);
  t3410 = _igen_dd_mm256_sub_pd(t3386, s4122);
  t3411 = _igen_dd_mm256_sub_pd(t3387, s4123);
  t3412 = _igen_dd_mm256_sub_pd(t3384, t3401);
  t3413 = _igen_dd_mm256_add_pd(t3385, t3400);
  t3414 = _igen_dd_mm256_add_pd(t3384, t3401);
  t3415 = _igen_dd_mm256_sub_pd(t3385, t3400);
  t3416 = _igen_dd_mm256_add_pd(t3388, s4124);
  t3417 = _igen_dd_mm256_sub_pd(t3389, s4125);
  t3418 = _igen_dd_mm256_sub_pd(t3388, s4124);
  t3419 = _igen_dd_mm256_add_pd(t3389, s4125);
  s4126 = *((a1282 + 2));
  s4127 = *((a1282 + 3));
  s4128 = _igen_dd_mm256_permute2f128_pd(s4126, s4127, (0) | ((2) << 4));
  s4129 = _igen_dd_mm256_permute2f128_pd(s4126, s4127, (1) | ((3) << 4));
  s4130 = _igen_dd_mm256_unpacklo_pd(s4128, s4129);
  s4131 = _igen_dd_mm256_unpackhi_pd(s4128, s4129);
  s4132 = *((a1282 + 66));
  s4133 = *((a1282 + 67));
  s4134 = _igen_dd_mm256_permute2f128_pd(s4132, s4133, (0) | ((2) << 4));
  s4135 = _igen_dd_mm256_permute2f128_pd(s4132, s4133, (1) | ((3) << 4));
  s4136 = _igen_dd_mm256_unpacklo_pd(s4134, s4135);
  s4137 = _igen_dd_mm256_unpackhi_pd(s4134, s4135);
  t3420 = _igen_dd_mm256_add_pd(s4130, s4136);
  t3421 = _igen_dd_mm256_add_pd(s4131, s4137);
  t3422 = _igen_dd_mm256_sub_pd(s4130, s4136);
  t3423 = _igen_dd_mm256_sub_pd(s4131, s4137);
  s4138 = *((a1282 + 34));
  s4139 = *((a1282 + 35));
  s4140 = _igen_dd_mm256_permute2f128_pd(s4138, s4139, (0) | ((2) << 4));
  s4141 = _igen_dd_mm256_permute2f128_pd(s4138, s4139, (1) | ((3) << 4));
  s4142 = _igen_dd_mm256_unpacklo_pd(s4140, s4141);
  s4143 = _igen_dd_mm256_unpackhi_pd(s4140, s4141);
  s4144 = *((a1282 + 98));
  s4145 = *((a1282 + 99));
  s4146 = _igen_dd_mm256_permute2f128_pd(s4144, s4145, (0) | ((2) << 4));
  s4147 = _igen_dd_mm256_permute2f128_pd(s4144, s4145, (1) | ((3) << 4));
  s4148 = _igen_dd_mm256_unpacklo_pd(s4146, s4147);
  s4149 = _igen_dd_mm256_unpackhi_pd(s4146, s4147);
  t3424 = _igen_dd_mm256_add_pd(s4142, s4148);
  t3425 = _igen_dd_mm256_add_pd(s4143, s4149);
  t3426 = _igen_dd_mm256_sub_pd(s4142, s4148);
  t3427 = _igen_dd_mm256_sub_pd(s4143, s4149);
  t3428 = _igen_dd_mm256_add_pd(t3420, t3424);
  t3429 = _igen_dd_mm256_add_pd(t3421, t3425);
  t3430 = _igen_dd_mm256_sub_pd(t3420, t3424);
  t3431 = _igen_dd_mm256_sub_pd(t3421, t3425);
  t3432 = _igen_dd_mm256_sub_pd(t3422, t3427);
  t3433 = _igen_dd_mm256_add_pd(t3423, t3426);
  t3434 = _igen_dd_mm256_add_pd(t3422, t3427);
  t3435 = _igen_dd_mm256_sub_pd(t3423, t3426);
  s4150 = *((a1282 + 6));
  s4151 = *((a1282 + 7));
  s4152 = _igen_dd_mm256_permute2f128_pd(s4150, s4151, (0) | ((2) << 4));
  s4153 = _igen_dd_mm256_permute2f128_pd(s4150, s4151, (1) | ((3) << 4));
  s4154 = _igen_dd_mm256_unpacklo_pd(s4152, s4153);
  s4155 = _igen_dd_mm256_unpackhi_pd(s4152, s4153);
  s4156 = *((a1282 + 70));
  s4157 = *((a1282 + 71));
  s4158 = _igen_dd_mm256_permute2f128_pd(s4156, s4157, (0) | ((2) << 4));
  s4159 = _igen_dd_mm256_permute2f128_pd(s4156, s4157, (1) | ((3) << 4));
  s4160 = _igen_dd_mm256_unpacklo_pd(s4158, s4159);
  s4161 = _igen_dd_mm256_unpackhi_pd(s4158, s4159);
  t3436 = _igen_dd_mm256_add_pd(s4154, s4160);
  t3437 = _igen_dd_mm256_add_pd(s4155, s4161);
  t3438 = _igen_dd_mm256_sub_pd(s4154, s4160);
  t3439 = _igen_dd_mm256_sub_pd(s4155, s4161);
  s4162 = *((a1282 + 38));
  s4163 = *((a1282 + 39));
  s4164 = _igen_dd_mm256_permute2f128_pd(s4162, s4163, (0) | ((2) << 4));
  s4165 = _igen_dd_mm256_permute2f128_pd(s4162, s4163, (1) | ((3) << 4));
  s4166 = _igen_dd_mm256_unpacklo_pd(s4164, s4165);
  s4167 = _igen_dd_mm256_unpackhi_pd(s4164, s4165);
  s4168 = *((a1282 + 102));
  s4169 = *((a1282 + 103));
  s4170 = _igen_dd_mm256_permute2f128_pd(s4168, s4169, (0) | ((2) << 4));
  s4171 = _igen_dd_mm256_permute2f128_pd(s4168, s4169, (1) | ((3) << 4));
  s4172 = _igen_dd_mm256_unpacklo_pd(s4170, s4171);
  s4173 = _igen_dd_mm256_unpackhi_pd(s4170, s4171);
  t3440 = _igen_dd_mm256_add_pd(s4166, s4172);
  t3441 = _igen_dd_mm256_add_pd(s4167, s4173);
  t3442 = _igen_dd_mm256_sub_pd(s4166, s4172);
  t3443 = _igen_dd_mm256_sub_pd(s4167, s4173);
  t3444 = _igen_dd_mm256_add_pd(t3436, t3440);
  t3445 = _igen_dd_mm256_add_pd(t3437, t3441);
  t3446 = _igen_dd_mm256_sub_pd(t3436, t3440);
  t3447 = _igen_dd_mm256_sub_pd(t3437, t3441);
  dd_I _t287 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t288 = _igen_dd_mm256_set1_pd(_t287);
  dd_I _t289 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t290 = _igen_dd_mm256_set1_pd(_t289);
  ddi_4 _t291 = _igen_dd_mm256_mul_pd(_t288, t3446);
  ddi_4 _t292 = _igen_dd_mm256_mul_pd(_t290, t3447);
  s4174 = _igen_dd_mm256_sub_pd(_t291, _t292);
  dd_I _t293 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t294 = _igen_dd_mm256_set1_pd(_t293);
  dd_I _t295 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t296 = _igen_dd_mm256_set1_pd(_t295);
  ddi_4 _t297 = _igen_dd_mm256_mul_pd(_t294, t3446);
  ddi_4 _t298 = _igen_dd_mm256_mul_pd(_t296, t3447);
  s4175 = _igen_dd_mm256_add_pd(_t297, _t298);
  t3448 = _igen_dd_mm256_sub_pd(t3438, t3443);
  t3449 = _igen_dd_mm256_add_pd(t3439, t3442);
  t3450 = _igen_dd_mm256_add_pd(t3438, t3443);
  t3451 = _igen_dd_mm256_sub_pd(t3439, t3442);
  dd_I _t299 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t300 = _igen_dd_mm256_set1_pd(_t299);
  dd_I _t301 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t302 = _igen_dd_mm256_set1_pd(_t301);
  ddi_4 _t303 = _igen_dd_mm256_mul_pd(_t300, t3448);
  ddi_4 _t304 = _igen_dd_mm256_mul_pd(_t302, t3449);
  s4176 = _igen_dd_mm256_sub_pd(_t303, _t304);
  dd_I _t305 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t306 = _igen_dd_mm256_set1_pd(_t305);
  dd_I _t307 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t308 = _igen_dd_mm256_set1_pd(_t307);
  ddi_4 _t309 = _igen_dd_mm256_mul_pd(_t306, t3448);
  ddi_4 _t310 = _igen_dd_mm256_mul_pd(_t308, t3449);
  s4177 = _igen_dd_mm256_add_pd(_t309, _t310);
  dd_I _t311 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t312 = _igen_dd_mm256_set1_pd(_t311);
  dd_I _t313 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t314 = _igen_dd_mm256_set1_pd(_t313);
  ddi_4 _t315 = _igen_dd_mm256_mul_pd(_t312, t3450);
  ddi_4 _t316 = _igen_dd_mm256_mul_pd(_t314, t3451);
  s4178 = _igen_dd_mm256_sub_pd(_t315, _t316);
  dd_I _t317 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t318 = _igen_dd_mm256_set1_pd(_t317);
  dd_I _t319 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t320 = _igen_dd_mm256_set1_pd(_t319);
  ddi_4 _t321 = _igen_dd_mm256_mul_pd(_t318, t3450);
  ddi_4 _t322 = _igen_dd_mm256_mul_pd(_t320, t3451);
  s4179 = _igen_dd_mm256_add_pd(_t321, _t322);
  s4180 = *((a1282 + 10));
  s4181 = *((a1282 + 11));
  s4182 = _igen_dd_mm256_permute2f128_pd(s4180, s4181, (0) | ((2) << 4));
  s4183 = _igen_dd_mm256_permute2f128_pd(s4180, s4181, (1) | ((3) << 4));
  s4184 = _igen_dd_mm256_unpacklo_pd(s4182, s4183);
  s4185 = _igen_dd_mm256_unpackhi_pd(s4182, s4183);
  s4186 = *((a1282 + 74));
  s4187 = *((a1282 + 75));
  s4188 = _igen_dd_mm256_permute2f128_pd(s4186, s4187, (0) | ((2) << 4));
  s4189 = _igen_dd_mm256_permute2f128_pd(s4186, s4187, (1) | ((3) << 4));
  s4190 = _igen_dd_mm256_unpacklo_pd(s4188, s4189);
  s4191 = _igen_dd_mm256_unpackhi_pd(s4188, s4189);
  t3452 = _igen_dd_mm256_add_pd(s4184, s4190);
  t3453 = _igen_dd_mm256_add_pd(s4185, s4191);
  t3454 = _igen_dd_mm256_sub_pd(s4184, s4190);
  t3455 = _igen_dd_mm256_sub_pd(s4185, s4191);
  s4192 = *((a1282 + 42));
  s4193 = *((a1282 + 43));
  s4194 = _igen_dd_mm256_permute2f128_pd(s4192, s4193, (0) | ((2) << 4));
  s4195 = _igen_dd_mm256_permute2f128_pd(s4192, s4193, (1) | ((3) << 4));
  s4196 = _igen_dd_mm256_unpacklo_pd(s4194, s4195);
  s4197 = _igen_dd_mm256_unpackhi_pd(s4194, s4195);
  s4198 = *((a1282 + 106));
  s4199 = *((a1282 + 107));
  s4200 = _igen_dd_mm256_permute2f128_pd(s4198, s4199, (0) | ((2) << 4));
  s4201 = _igen_dd_mm256_permute2f128_pd(s4198, s4199, (1) | ((3) << 4));
  s4202 = _igen_dd_mm256_unpacklo_pd(s4200, s4201);
  s4203 = _igen_dd_mm256_unpackhi_pd(s4200, s4201);
  t3456 = _igen_dd_mm256_add_pd(s4196, s4202);
  t3457 = _igen_dd_mm256_add_pd(s4197, s4203);
  t3458 = _igen_dd_mm256_sub_pd(s4196, s4202);
  t3459 = _igen_dd_mm256_sub_pd(s4197, s4203);
  t3460 = _igen_dd_mm256_add_pd(t3452, t3456);
  t3461 = _igen_dd_mm256_add_pd(t3453, t3457);
  t3462 = _igen_dd_mm256_sub_pd(t3452, t3456);
  t3463 = _igen_dd_mm256_sub_pd(t3453, t3457);
  dd_I _t323 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t324 = _igen_dd_mm256_set1_pd(_t323);
  ddi_4 _t325 = _igen_dd_mm256_sub_pd(t3462, t3463);
  s4204 = _igen_dd_mm256_mul_pd(_t324, _t325);
  dd_I _t326 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t327 = _igen_dd_mm256_set1_pd(_t326);
  ddi_4 _t328 = _igen_dd_mm256_add_pd(t3462, t3463);
  s4205 = _igen_dd_mm256_mul_pd(_t327, _t328);
  t3464 = _igen_dd_mm256_sub_pd(t3454, t3459);
  t3465 = _igen_dd_mm256_add_pd(t3455, t3458);
  t3466 = _igen_dd_mm256_add_pd(t3454, t3459);
  t3467 = _igen_dd_mm256_sub_pd(t3455, t3458);
  dd_I _t329 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t330 = _igen_dd_mm256_set1_pd(_t329);
  dd_I _t331 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t332 = _igen_dd_mm256_set1_pd(_t331);
  ddi_4 _t333 = _igen_dd_mm256_mul_pd(_t330, t3464);
  ddi_4 _t334 = _igen_dd_mm256_mul_pd(_t332, t3465);
  s4206 = _igen_dd_mm256_sub_pd(_t333, _t334);
  dd_I _t335 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t336 = _igen_dd_mm256_set1_pd(_t335);
  dd_I _t337 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t338 = _igen_dd_mm256_set1_pd(_t337);
  ddi_4 _t339 = _igen_dd_mm256_mul_pd(_t336, t3464);
  ddi_4 _t340 = _igen_dd_mm256_mul_pd(_t338, t3465);
  s4207 = _igen_dd_mm256_add_pd(_t339, _t340);
  dd_I _t341 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t342 = _igen_dd_mm256_set1_pd(_t341);
  dd_I _t343 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t344 = _igen_dd_mm256_set1_pd(_t343);
  ddi_4 _t345 = _igen_dd_mm256_mul_pd(_t342, t3466);
  ddi_4 _t346 = _igen_dd_mm256_mul_pd(_t344, t3467);
  s4208 = _igen_dd_mm256_sub_pd(_t345, _t346);
  dd_I _t347 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t348 = _igen_dd_mm256_set1_pd(_t347);
  dd_I _t349 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t350 = _igen_dd_mm256_set1_pd(_t349);
  ddi_4 _t351 = _igen_dd_mm256_mul_pd(_t348, t3466);
  ddi_4 _t352 = _igen_dd_mm256_mul_pd(_t350, t3467);
  s4209 = _igen_dd_mm256_add_pd(_t351, _t352);
  s4210 = *((a1282 + 14));
  s4211 = *((a1282 + 15));
  s4212 = _igen_dd_mm256_permute2f128_pd(s4210, s4211, (0) | ((2) << 4));
  s4213 = _igen_dd_mm256_permute2f128_pd(s4210, s4211, (1) | ((3) << 4));
  s4214 = _igen_dd_mm256_unpacklo_pd(s4212, s4213);
  s4215 = _igen_dd_mm256_unpackhi_pd(s4212, s4213);
  s4216 = *((a1282 + 78));
  s4217 = *((a1282 + 79));
  s4218 = _igen_dd_mm256_permute2f128_pd(s4216, s4217, (0) | ((2) << 4));
  s4219 = _igen_dd_mm256_permute2f128_pd(s4216, s4217, (1) | ((3) << 4));
  s4220 = _igen_dd_mm256_unpacklo_pd(s4218, s4219);
  s4221 = _igen_dd_mm256_unpackhi_pd(s4218, s4219);
  t3468 = _igen_dd_mm256_add_pd(s4214, s4220);
  t3469 = _igen_dd_mm256_add_pd(s4215, s4221);
  t3470 = _igen_dd_mm256_sub_pd(s4214, s4220);
  t3471 = _igen_dd_mm256_sub_pd(s4215, s4221);
  s4222 = *((a1282 + 46));
  s4223 = *((a1282 + 47));
  s4224 = _igen_dd_mm256_permute2f128_pd(s4222, s4223, (0) | ((2) << 4));
  s4225 = _igen_dd_mm256_permute2f128_pd(s4222, s4223, (1) | ((3) << 4));
  s4226 = _igen_dd_mm256_unpacklo_pd(s4224, s4225);
  s4227 = _igen_dd_mm256_unpackhi_pd(s4224, s4225);
  s4228 = *((a1282 + 110));
  s4229 = *((a1282 + 111));
  s4230 = _igen_dd_mm256_permute2f128_pd(s4228, s4229, (0) | ((2) << 4));
  s4231 = _igen_dd_mm256_permute2f128_pd(s4228, s4229, (1) | ((3) << 4));
  s4232 = _igen_dd_mm256_unpacklo_pd(s4230, s4231);
  s4233 = _igen_dd_mm256_unpackhi_pd(s4230, s4231);
  t3472 = _igen_dd_mm256_add_pd(s4226, s4232);
  t3473 = _igen_dd_mm256_add_pd(s4227, s4233);
  t3474 = _igen_dd_mm256_sub_pd(s4226, s4232);
  t3475 = _igen_dd_mm256_sub_pd(s4227, s4233);
  t3476 = _igen_dd_mm256_add_pd(t3468, t3472);
  t3477 = _igen_dd_mm256_add_pd(t3469, t3473);
  t3478 = _igen_dd_mm256_sub_pd(t3468, t3472);
  t3479 = _igen_dd_mm256_sub_pd(t3469, t3473);
  dd_I _t353 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t354 = _igen_dd_mm256_set1_pd(_t353);
  dd_I _t355 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t356 = _igen_dd_mm256_set1_pd(_t355);
  ddi_4 _t357 = _igen_dd_mm256_mul_pd(_t354, t3478);
  ddi_4 _t358 = _igen_dd_mm256_mul_pd(_t356, t3479);
  s4234 = _igen_dd_mm256_sub_pd(_t357, _t358);
  dd_I _t359 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t360 = _igen_dd_mm256_set1_pd(_t359);
  dd_I _t361 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t362 = _igen_dd_mm256_set1_pd(_t361);
  ddi_4 _t363 = _igen_dd_mm256_mul_pd(_t360, t3478);
  ddi_4 _t364 = _igen_dd_mm256_mul_pd(_t362, t3479);
  s4235 = _igen_dd_mm256_add_pd(_t363, _t364);
  t3480 = _igen_dd_mm256_sub_pd(t3470, t3475);
  t3481 = _igen_dd_mm256_add_pd(t3471, t3474);
  t3482 = _igen_dd_mm256_add_pd(t3470, t3475);
  t3483 = _igen_dd_mm256_sub_pd(t3471, t3474);
  dd_I _t365 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t366 = _igen_dd_mm256_set1_pd(_t365);
  dd_I _t367 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t368 = _igen_dd_mm256_set1_pd(_t367);
  ddi_4 _t369 = _igen_dd_mm256_mul_pd(_t366, t3480);
  ddi_4 _t370 = _igen_dd_mm256_mul_pd(_t368, t3481);
  s4236 = _igen_dd_mm256_sub_pd(_t369, _t370);
  dd_I _t371 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t372 = _igen_dd_mm256_set1_pd(_t371);
  dd_I _t373 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t374 = _igen_dd_mm256_set1_pd(_t373);
  ddi_4 _t375 = _igen_dd_mm256_mul_pd(_t372, t3480);
  ddi_4 _t376 = _igen_dd_mm256_mul_pd(_t374, t3481);
  s4237 = _igen_dd_mm256_add_pd(_t375, _t376);
  dd_I _t377 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t378 = _ia_neg_dd(_t377);
  ddi_4 _t379 = _igen_dd_mm256_set1_pd(_t378);
  dd_I _t380 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t381 = _igen_dd_mm256_set1_pd(_t380);
  ddi_4 _t382 = _igen_dd_mm256_mul_pd(_t379, t3482);
  ddi_4 _t383 = _igen_dd_mm256_mul_pd(_t381, t3483);
  s4238 = _igen_dd_mm256_sub_pd(_t382, _t383);
  dd_I _t384 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t385 = _igen_dd_mm256_set1_pd(_t384);
  dd_I _t386 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t387 = _ia_neg_dd(_t386);
  ddi_4 _t388 = _igen_dd_mm256_set1_pd(_t387);
  ddi_4 _t389 = _igen_dd_mm256_mul_pd(_t385, t3482);
  ddi_4 _t390 = _igen_dd_mm256_mul_pd(_t388, t3483);
  s4239 = _igen_dd_mm256_add_pd(_t389, _t390);
  s4240 = *((a1282 + 18));
  s4241 = *((a1282 + 19));
  s4242 = _igen_dd_mm256_permute2f128_pd(s4240, s4241, (0) | ((2) << 4));
  s4243 = _igen_dd_mm256_permute2f128_pd(s4240, s4241, (1) | ((3) << 4));
  s4244 = _igen_dd_mm256_unpacklo_pd(s4242, s4243);
  s4245 = _igen_dd_mm256_unpackhi_pd(s4242, s4243);
  s4246 = *((a1282 + 82));
  s4247 = *((a1282 + 83));
  s4248 = _igen_dd_mm256_permute2f128_pd(s4246, s4247, (0) | ((2) << 4));
  s4249 = _igen_dd_mm256_permute2f128_pd(s4246, s4247, (1) | ((3) << 4));
  s4250 = _igen_dd_mm256_unpacklo_pd(s4248, s4249);
  s4251 = _igen_dd_mm256_unpackhi_pd(s4248, s4249);
  t3484 = _igen_dd_mm256_add_pd(s4244, s4250);
  t3485 = _igen_dd_mm256_add_pd(s4245, s4251);
  t3486 = _igen_dd_mm256_sub_pd(s4244, s4250);
  t3487 = _igen_dd_mm256_sub_pd(s4245, s4251);
  s4252 = *((a1282 + 50));
  s4253 = *((a1282 + 51));
  s4254 = _igen_dd_mm256_permute2f128_pd(s4252, s4253, (0) | ((2) << 4));
  s4255 = _igen_dd_mm256_permute2f128_pd(s4252, s4253, (1) | ((3) << 4));
  s4256 = _igen_dd_mm256_unpacklo_pd(s4254, s4255);
  s4257 = _igen_dd_mm256_unpackhi_pd(s4254, s4255);
  s4258 = *((a1282 + 114));
  s4259 = *((a1282 + 115));
  s4260 = _igen_dd_mm256_permute2f128_pd(s4258, s4259, (0) | ((2) << 4));
  s4261 = _igen_dd_mm256_permute2f128_pd(s4258, s4259, (1) | ((3) << 4));
  s4262 = _igen_dd_mm256_unpacklo_pd(s4260, s4261);
  s4263 = _igen_dd_mm256_unpackhi_pd(s4260, s4261);
  t3488 = _igen_dd_mm256_add_pd(s4256, s4262);
  t3489 = _igen_dd_mm256_add_pd(s4257, s4263);
  t3490 = _igen_dd_mm256_sub_pd(s4256, s4262);
  t3491 = _igen_dd_mm256_sub_pd(s4257, s4263);
  t3492 = _igen_dd_mm256_add_pd(t3484, t3488);
  t3493 = _igen_dd_mm256_add_pd(t3485, t3489);
  t3494 = _igen_dd_mm256_sub_pd(t3484, t3488);
  t3495 = _igen_dd_mm256_sub_pd(t3485, t3489);
  t3496 = _igen_dd_mm256_sub_pd(t3486, t3491);
  t3497 = _igen_dd_mm256_add_pd(t3487, t3490);
  dd_I _t391 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t392 = _igen_dd_mm256_set1_pd(_t391);
  ddi_4 _t393 = _igen_dd_mm256_sub_pd(t3496, t3497);
  s4264 = _igen_dd_mm256_mul_pd(_t392, _t393);
  dd_I _t394 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t395 = _igen_dd_mm256_set1_pd(_t394);
  ddi_4 _t396 = _igen_dd_mm256_add_pd(t3496, t3497);
  s4265 = _igen_dd_mm256_mul_pd(_t395, _t396);
  dd_I _t397 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t398 = _ia_neg_dd(_t397);
  ddi_4 _t399 = _igen_dd_mm256_set1_pd(_t398);
  ddi_4 _t400 = _igen_dd_mm256_add_pd(t3486, t3491);
  a1295 = _igen_dd_mm256_mul_pd(_t399, _t400);
  dd_I _t401 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t402 = _igen_dd_mm256_set1_pd(_t401);
  ddi_4 _t403 = _igen_dd_mm256_sub_pd(t3487, t3490);
  a1296 = _igen_dd_mm256_mul_pd(_t402, _t403);
  s4266 = _igen_dd_mm256_sub_pd(a1295, a1296);
  s4267 = _igen_dd_mm256_add_pd(a1295, a1296);
  s4268 = *((a1282 + 22));
  s4269 = *((a1282 + 23));
  s4270 = _igen_dd_mm256_permute2f128_pd(s4268, s4269, (0) | ((2) << 4));
  s4271 = _igen_dd_mm256_permute2f128_pd(s4268, s4269, (1) | ((3) << 4));
  s4272 = _igen_dd_mm256_unpacklo_pd(s4270, s4271);
  s4273 = _igen_dd_mm256_unpackhi_pd(s4270, s4271);
  s4274 = *((a1282 + 86));
  s4275 = *((a1282 + 87));
  s4276 = _igen_dd_mm256_permute2f128_pd(s4274, s4275, (0) | ((2) << 4));
  s4277 = _igen_dd_mm256_permute2f128_pd(s4274, s4275, (1) | ((3) << 4));
  s4278 = _igen_dd_mm256_unpacklo_pd(s4276, s4277);
  s4279 = _igen_dd_mm256_unpackhi_pd(s4276, s4277);
  t3498 = _igen_dd_mm256_add_pd(s4272, s4278);
  t3499 = _igen_dd_mm256_add_pd(s4273, s4279);
  t3500 = _igen_dd_mm256_sub_pd(s4272, s4278);
  t3501 = _igen_dd_mm256_sub_pd(s4273, s4279);
  s4280 = *((a1282 + 54));
  s4281 = *((a1282 + 55));
  s4282 = _igen_dd_mm256_permute2f128_pd(s4280, s4281, (0) | ((2) << 4));
  s4283 = _igen_dd_mm256_permute2f128_pd(s4280, s4281, (1) | ((3) << 4));
  s4284 = _igen_dd_mm256_unpacklo_pd(s4282, s4283);
  s4285 = _igen_dd_mm256_unpackhi_pd(s4282, s4283);
  s4286 = *((a1282 + 118));
  s4287 = *((a1282 + 119));
  s4288 = _igen_dd_mm256_permute2f128_pd(s4286, s4287, (0) | ((2) << 4));
  s4289 = _igen_dd_mm256_permute2f128_pd(s4286, s4287, (1) | ((3) << 4));
  s4290 = _igen_dd_mm256_unpacklo_pd(s4288, s4289);
  s4291 = _igen_dd_mm256_unpackhi_pd(s4288, s4289);
  t3502 = _igen_dd_mm256_add_pd(s4284, s4290);
  t3503 = _igen_dd_mm256_add_pd(s4285, s4291);
  t3504 = _igen_dd_mm256_sub_pd(s4284, s4290);
  t3505 = _igen_dd_mm256_sub_pd(s4285, s4291);
  t3506 = _igen_dd_mm256_add_pd(t3498, t3502);
  t3507 = _igen_dd_mm256_add_pd(t3499, t3503);
  t3508 = _igen_dd_mm256_sub_pd(t3498, t3502);
  t3509 = _igen_dd_mm256_sub_pd(t3499, t3503);
  dd_I _t404 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t405 = _ia_neg_dd(_t404);
  ddi_4 _t406 = _igen_dd_mm256_set1_pd(_t405);
  dd_I _t407 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t408 = _igen_dd_mm256_set1_pd(_t407);
  ddi_4 _t409 = _igen_dd_mm256_mul_pd(_t406, t3508);
  ddi_4 _t410 = _igen_dd_mm256_mul_pd(_t408, t3509);
  s4292 = _igen_dd_mm256_sub_pd(_t409, _t410);
  dd_I _t411 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t412 = _igen_dd_mm256_set1_pd(_t411);
  dd_I _t413 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t414 = _ia_neg_dd(_t413);
  ddi_4 _t415 = _igen_dd_mm256_set1_pd(_t414);
  ddi_4 _t416 = _igen_dd_mm256_mul_pd(_t412, t3508);
  ddi_4 _t417 = _igen_dd_mm256_mul_pd(_t415, t3509);
  s4293 = _igen_dd_mm256_add_pd(_t416, _t417);
  t3510 = _igen_dd_mm256_sub_pd(t3500, t3505);
  t3511 = _igen_dd_mm256_add_pd(t3501, t3504);
  t3512 = _igen_dd_mm256_add_pd(t3500, t3505);
  t3513 = _igen_dd_mm256_sub_pd(t3501, t3504);
  dd_I _t418 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t419 = _igen_dd_mm256_set1_pd(_t418);
  dd_I _t420 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t421 = _igen_dd_mm256_set1_pd(_t420);
  ddi_4 _t422 = _igen_dd_mm256_mul_pd(_t419, t3510);
  ddi_4 _t423 = _igen_dd_mm256_mul_pd(_t421, t3511);
  s4294 = _igen_dd_mm256_sub_pd(_t422, _t423);
  dd_I _t424 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t425 = _igen_dd_mm256_set1_pd(_t424);
  dd_I _t426 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t427 = _igen_dd_mm256_set1_pd(_t426);
  ddi_4 _t428 = _igen_dd_mm256_mul_pd(_t425, t3510);
  ddi_4 _t429 = _igen_dd_mm256_mul_pd(_t427, t3511);
  s4295 = _igen_dd_mm256_add_pd(_t428, _t429);
  dd_I _t430 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t431 = _ia_neg_dd(_t430);
  ddi_4 _t432 = _igen_dd_mm256_set1_pd(_t431);
  dd_I _t433 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t434 = _igen_dd_mm256_set1_pd(_t433);
  ddi_4 _t435 = _igen_dd_mm256_mul_pd(_t432, t3512);
  ddi_4 _t436 = _igen_dd_mm256_mul_pd(_t434, t3513);
  s4296 = _igen_dd_mm256_sub_pd(_t435, _t436);
  dd_I _t437 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t438 = _igen_dd_mm256_set1_pd(_t437);
  dd_I _t439 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t440 = _ia_neg_dd(_t439);
  ddi_4 _t441 = _igen_dd_mm256_set1_pd(_t440);
  ddi_4 _t442 = _igen_dd_mm256_mul_pd(_t438, t3512);
  ddi_4 _t443 = _igen_dd_mm256_mul_pd(_t441, t3513);
  s4297 = _igen_dd_mm256_add_pd(_t442, _t443);
  s4298 = *((a1282 + 26));
  s4299 = *((a1282 + 27));
  s4300 = _igen_dd_mm256_permute2f128_pd(s4298, s4299, (0) | ((2) << 4));
  s4301 = _igen_dd_mm256_permute2f128_pd(s4298, s4299, (1) | ((3) << 4));
  s4302 = _igen_dd_mm256_unpacklo_pd(s4300, s4301);
  s4303 = _igen_dd_mm256_unpackhi_pd(s4300, s4301);
  s4304 = *((a1282 + 90));
  s4305 = *((a1282 + 91));
  s4306 = _igen_dd_mm256_permute2f128_pd(s4304, s4305, (0) | ((2) << 4));
  s4307 = _igen_dd_mm256_permute2f128_pd(s4304, s4305, (1) | ((3) << 4));
  s4308 = _igen_dd_mm256_unpacklo_pd(s4306, s4307);
  s4309 = _igen_dd_mm256_unpackhi_pd(s4306, s4307);
  t3514 = _igen_dd_mm256_add_pd(s4302, s4308);
  t3515 = _igen_dd_mm256_add_pd(s4303, s4309);
  t3516 = _igen_dd_mm256_sub_pd(s4302, s4308);
  t3517 = _igen_dd_mm256_sub_pd(s4303, s4309);
  s4310 = *((a1282 + 58));
  s4311 = *((a1282 + 59));
  s4312 = _igen_dd_mm256_permute2f128_pd(s4310, s4311, (0) | ((2) << 4));
  s4313 = _igen_dd_mm256_permute2f128_pd(s4310, s4311, (1) | ((3) << 4));
  s4314 = _igen_dd_mm256_unpacklo_pd(s4312, s4313);
  s4315 = _igen_dd_mm256_unpackhi_pd(s4312, s4313);
  s4316 = *((a1282 + 122));
  s4317 = *((a1282 + 123));
  s4318 = _igen_dd_mm256_permute2f128_pd(s4316, s4317, (0) | ((2) << 4));
  s4319 = _igen_dd_mm256_permute2f128_pd(s4316, s4317, (1) | ((3) << 4));
  s4320 = _igen_dd_mm256_unpacklo_pd(s4318, s4319);
  s4321 = _igen_dd_mm256_unpackhi_pd(s4318, s4319);
  t3518 = _igen_dd_mm256_add_pd(s4314, s4320);
  t3519 = _igen_dd_mm256_add_pd(s4315, s4321);
  t3520 = _igen_dd_mm256_sub_pd(s4314, s4320);
  t3521 = _igen_dd_mm256_sub_pd(s4315, s4321);
  t3522 = _igen_dd_mm256_add_pd(t3514, t3518);
  t3523 = _igen_dd_mm256_add_pd(t3515, t3519);
  dd_I _t444 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t445 = _ia_neg_dd(_t444);
  ddi_4 _t446 = _igen_dd_mm256_set1_pd(_t445);
  ddi_4 _t447 = _igen_dd_mm256_sub_pd(t3514, t3518);
  a1297 = _igen_dd_mm256_mul_pd(_t446, _t447);
  dd_I _t448 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t449 = _igen_dd_mm256_set1_pd(_t448);
  ddi_4 _t450 = _igen_dd_mm256_sub_pd(t3515, t3519);
  a1298 = _igen_dd_mm256_mul_pd(_t449, _t450);
  s4322 = _igen_dd_mm256_sub_pd(a1297, a1298);
  s4323 = _igen_dd_mm256_add_pd(a1297, a1298);
  t3524 = _igen_dd_mm256_sub_pd(t3516, t3521);
  t3525 = _igen_dd_mm256_add_pd(t3517, t3520);
  t3526 = _igen_dd_mm256_add_pd(t3516, t3521);
  t3527 = _igen_dd_mm256_sub_pd(t3517, t3520);
  dd_I _t451 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t452 = _igen_dd_mm256_set1_pd(_t451);
  dd_I _t453 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t454 = _igen_dd_mm256_set1_pd(_t453);
  ddi_4 _t455 = _igen_dd_mm256_mul_pd(_t452, t3524);
  ddi_4 _t456 = _igen_dd_mm256_mul_pd(_t454, t3525);
  s4324 = _igen_dd_mm256_sub_pd(_t455, _t456);
  dd_I _t457 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t458 = _igen_dd_mm256_set1_pd(_t457);
  dd_I _t459 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t460 = _igen_dd_mm256_set1_pd(_t459);
  ddi_4 _t461 = _igen_dd_mm256_mul_pd(_t458, t3524);
  ddi_4 _t462 = _igen_dd_mm256_mul_pd(_t460, t3525);
  s4325 = _igen_dd_mm256_add_pd(_t461, _t462);
  dd_I _t463 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t464 = _ia_neg_dd(_t463);
  ddi_4 _t465 = _igen_dd_mm256_set1_pd(_t464);
  dd_I _t466 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t467 = _ia_neg_dd(_t466);
  ddi_4 _t468 = _igen_dd_mm256_set1_pd(_t467);
  ddi_4 _t469 = _igen_dd_mm256_mul_pd(_t465, t3526);
  ddi_4 _t470 = _igen_dd_mm256_mul_pd(_t468, t3527);
  s4326 = _igen_dd_mm256_sub_pd(_t469, _t470);
  dd_I _t471 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t472 = _ia_neg_dd(_t471);
  ddi_4 _t473 = _igen_dd_mm256_set1_pd(_t472);
  dd_I _t474 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t475 = _ia_neg_dd(_t474);
  ddi_4 _t476 = _igen_dd_mm256_set1_pd(_t475);
  ddi_4 _t477 = _igen_dd_mm256_mul_pd(_t473, t3526);
  ddi_4 _t478 = _igen_dd_mm256_mul_pd(_t476, t3527);
  s4327 = _igen_dd_mm256_add_pd(_t477, _t478);
  s4328 = *((a1282 + 30));
  s4329 = *((a1282 + 31));
  s4330 = _igen_dd_mm256_permute2f128_pd(s4328, s4329, (0) | ((2) << 4));
  s4331 = _igen_dd_mm256_permute2f128_pd(s4328, s4329, (1) | ((3) << 4));
  s4332 = _igen_dd_mm256_unpacklo_pd(s4330, s4331);
  s4333 = _igen_dd_mm256_unpackhi_pd(s4330, s4331);
  s4334 = *((a1282 + 94));
  s4335 = *((a1282 + 95));
  s4336 = _igen_dd_mm256_permute2f128_pd(s4334, s4335, (0) | ((2) << 4));
  s4337 = _igen_dd_mm256_permute2f128_pd(s4334, s4335, (1) | ((3) << 4));
  s4338 = _igen_dd_mm256_unpacklo_pd(s4336, s4337);
  s4339 = _igen_dd_mm256_unpackhi_pd(s4336, s4337);
  t3528 = _igen_dd_mm256_add_pd(s4332, s4338);
  t3529 = _igen_dd_mm256_add_pd(s4333, s4339);
  t3530 = _igen_dd_mm256_sub_pd(s4332, s4338);
  t3531 = _igen_dd_mm256_sub_pd(s4333, s4339);
  s4340 = *((a1282 + 62));
  s4341 = *((a1282 + 63));
  s4342 = _igen_dd_mm256_permute2f128_pd(s4340, s4341, (0) | ((2) << 4));
  s4343 = _igen_dd_mm256_permute2f128_pd(s4340, s4341, (1) | ((3) << 4));
  s4344 = _igen_dd_mm256_unpacklo_pd(s4342, s4343);
  s4345 = _igen_dd_mm256_unpackhi_pd(s4342, s4343);
  s4346 = *((a1282 + 126));
  s4347 = *((a1282 + 127));
  s4348 = _igen_dd_mm256_permute2f128_pd(s4346, s4347, (0) | ((2) << 4));
  s4349 = _igen_dd_mm256_permute2f128_pd(s4346, s4347, (1) | ((3) << 4));
  s4350 = _igen_dd_mm256_unpacklo_pd(s4348, s4349);
  s4351 = _igen_dd_mm256_unpackhi_pd(s4348, s4349);
  t3532 = _igen_dd_mm256_add_pd(s4344, s4350);
  t3533 = _igen_dd_mm256_add_pd(s4345, s4351);
  t3534 = _igen_dd_mm256_sub_pd(s4344, s4350);
  t3535 = _igen_dd_mm256_sub_pd(s4345, s4351);
  t3536 = _igen_dd_mm256_add_pd(t3528, t3532);
  t3537 = _igen_dd_mm256_add_pd(t3529, t3533);
  t3538 = _igen_dd_mm256_sub_pd(t3528, t3532);
  t3539 = _igen_dd_mm256_sub_pd(t3529, t3533);
  dd_I _t479 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t480 = _ia_neg_dd(_t479);
  ddi_4 _t481 = _igen_dd_mm256_set1_pd(_t480);
  dd_I _t482 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t483 = _igen_dd_mm256_set1_pd(_t482);
  ddi_4 _t484 = _igen_dd_mm256_mul_pd(_t481, t3538);
  ddi_4 _t485 = _igen_dd_mm256_mul_pd(_t483, t3539);
  s4352 = _igen_dd_mm256_sub_pd(_t484, _t485);
  dd_I _t486 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t487 = _igen_dd_mm256_set1_pd(_t486);
  dd_I _t488 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t489 = _ia_neg_dd(_t488);
  ddi_4 _t490 = _igen_dd_mm256_set1_pd(_t489);
  ddi_4 _t491 = _igen_dd_mm256_mul_pd(_t487, t3538);
  ddi_4 _t492 = _igen_dd_mm256_mul_pd(_t490, t3539);
  s4353 = _igen_dd_mm256_add_pd(_t491, _t492);
  t3540 = _igen_dd_mm256_sub_pd(t3530, t3535);
  t3541 = _igen_dd_mm256_add_pd(t3531, t3534);
  t3542 = _igen_dd_mm256_add_pd(t3530, t3535);
  t3543 = _igen_dd_mm256_sub_pd(t3531, t3534);
  dd_I _t493 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t494 = _igen_dd_mm256_set1_pd(_t493);
  dd_I _t495 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t496 = _igen_dd_mm256_set1_pd(_t495);
  ddi_4 _t497 = _igen_dd_mm256_mul_pd(_t494, t3540);
  ddi_4 _t498 = _igen_dd_mm256_mul_pd(_t496, t3541);
  s4354 = _igen_dd_mm256_sub_pd(_t497, _t498);
  dd_I _t499 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t500 = _igen_dd_mm256_set1_pd(_t499);
  dd_I _t501 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t502 = _igen_dd_mm256_set1_pd(_t501);
  ddi_4 _t503 = _igen_dd_mm256_mul_pd(_t500, t3540);
  ddi_4 _t504 = _igen_dd_mm256_mul_pd(_t502, t3541);
  s4355 = _igen_dd_mm256_add_pd(_t503, _t504);
  dd_I _t505 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t506 = _ia_neg_dd(_t505);
  ddi_4 _t507 = _igen_dd_mm256_set1_pd(_t506);
  dd_I _t508 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t509 = _ia_neg_dd(_t508);
  ddi_4 _t510 = _igen_dd_mm256_set1_pd(_t509);
  ddi_4 _t511 = _igen_dd_mm256_mul_pd(_t507, t3542);
  ddi_4 _t512 = _igen_dd_mm256_mul_pd(_t510, t3543);
  s4356 = _igen_dd_mm256_sub_pd(_t511, _t512);
  dd_I _t513 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t514 = _ia_neg_dd(_t513);
  ddi_4 _t515 = _igen_dd_mm256_set1_pd(_t514);
  dd_I _t516 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t517 = _ia_neg_dd(_t516);
  ddi_4 _t518 = _igen_dd_mm256_set1_pd(_t517);
  ddi_4 _t519 = _igen_dd_mm256_mul_pd(_t515, t3542);
  ddi_4 _t520 = _igen_dd_mm256_mul_pd(_t518, t3543);
  s4357 = _igen_dd_mm256_add_pd(_t519, _t520);
  t3544 = _igen_dd_mm256_add_pd(t3428, t3492);
  t3545 = _igen_dd_mm256_add_pd(t3429, t3493);
  t3546 = _igen_dd_mm256_sub_pd(t3428, t3492);
  t3547 = _igen_dd_mm256_sub_pd(t3429, t3493);
  t3548 = _igen_dd_mm256_add_pd(t3460, t3522);
  t3549 = _igen_dd_mm256_add_pd(t3461, t3523);
  t3550 = _igen_dd_mm256_sub_pd(t3460, t3522);
  t3551 = _igen_dd_mm256_sub_pd(t3461, t3523);
  t3552 = _igen_dd_mm256_add_pd(t3544, t3548);
  t3553 = _igen_dd_mm256_add_pd(t3545, t3549);
  t3554 = _igen_dd_mm256_sub_pd(t3544, t3548);
  t3555 = _igen_dd_mm256_sub_pd(t3545, t3549);
  t3556 = _igen_dd_mm256_sub_pd(t3546, t3551);
  t3557 = _igen_dd_mm256_add_pd(t3547, t3550);
  t3558 = _igen_dd_mm256_add_pd(t3546, t3551);
  t3559 = _igen_dd_mm256_sub_pd(t3547, t3550);
  t3560 = _igen_dd_mm256_add_pd(t3444, t3506);
  t3561 = _igen_dd_mm256_add_pd(t3445, t3507);
  t3562 = _igen_dd_mm256_sub_pd(t3444, t3506);
  t3563 = _igen_dd_mm256_sub_pd(t3445, t3507);
  t3564 = _igen_dd_mm256_add_pd(t3476, t3536);
  t3565 = _igen_dd_mm256_add_pd(t3477, t3537);
  t3566 = _igen_dd_mm256_sub_pd(t3476, t3536);
  t3567 = _igen_dd_mm256_sub_pd(t3477, t3537);
  t3568 = _igen_dd_mm256_add_pd(t3560, t3564);
  t3569 = _igen_dd_mm256_add_pd(t3561, t3565);
  t3570 = _igen_dd_mm256_sub_pd(t3560, t3564);
  t3571 = _igen_dd_mm256_sub_pd(t3561, t3565);
  t3572 = _igen_dd_mm256_sub_pd(t3562, t3567);
  t3573 = _igen_dd_mm256_add_pd(t3563, t3566);
  dd_I _t521 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t522 = _igen_dd_mm256_set1_pd(_t521);
  ddi_4 _t523 = _igen_dd_mm256_sub_pd(t3572, t3573);
  s4358 = _igen_dd_mm256_mul_pd(_t522, _t523);
  dd_I _t524 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t525 = _igen_dd_mm256_set1_pd(_t524);
  ddi_4 _t526 = _igen_dd_mm256_add_pd(t3572, t3573);
  s4359 = _igen_dd_mm256_mul_pd(_t525, _t526);
  dd_I _t527 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t528 = _ia_neg_dd(_t527);
  ddi_4 _t529 = _igen_dd_mm256_set1_pd(_t528);
  ddi_4 _t530 = _igen_dd_mm256_add_pd(t3562, t3567);
  a1299 = _igen_dd_mm256_mul_pd(_t529, _t530);
  dd_I _t531 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t532 = _igen_dd_mm256_set1_pd(_t531);
  ddi_4 _t533 = _igen_dd_mm256_sub_pd(t3563, t3566);
  a1300 = _igen_dd_mm256_mul_pd(_t532, _t533);
  s4360 = _igen_dd_mm256_sub_pd(a1299, a1300);
  s4361 = _igen_dd_mm256_add_pd(a1299, a1300);
  t3574 = _igen_dd_mm256_add_pd(t3552, t3568);
  t3575 = _igen_dd_mm256_add_pd(t3553, t3569);
  t3576 = _igen_dd_mm256_sub_pd(t3552, t3568);
  t3577 = _igen_dd_mm256_sub_pd(t3553, t3569);
  t3578 = _igen_dd_mm256_add_pd(t3556, s4358);
  t3579 = _igen_dd_mm256_add_pd(t3557, s4359);
  t3580 = _igen_dd_mm256_sub_pd(t3556, s4358);
  t3581 = _igen_dd_mm256_sub_pd(t3557, s4359);
  dd_I _t534 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t535 = _igen_dd_mm256_set1_pd(_t534);
  dd_I _t536 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t537 = _igen_dd_mm256_set1_pd(_t536);
  ddi_4 _t538 = _igen_dd_mm256_mul_pd(_t535, t3578);
  ddi_4 _t539 = _igen_dd_mm256_mul_pd(_t537, t3579);
  s4362 = _igen_dd_mm256_sub_pd(_t538, _t539);
  dd_I _t540 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t541 = _igen_dd_mm256_set1_pd(_t540);
  dd_I _t542 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t543 = _igen_dd_mm256_set1_pd(_t542);
  ddi_4 _t544 = _igen_dd_mm256_mul_pd(_t541, t3578);
  ddi_4 _t545 = _igen_dd_mm256_mul_pd(_t543, t3579);
  s4363 = _igen_dd_mm256_add_pd(_t544, _t545);
  dd_I _t546 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t547 = _ia_neg_dd(_t546);
  ddi_4 _t548 = _igen_dd_mm256_set1_pd(_t547);
  dd_I _t549 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t550 = _igen_dd_mm256_set1_pd(_t549);
  ddi_4 _t551 = _igen_dd_mm256_mul_pd(_t548, t3580);
  ddi_4 _t552 = _igen_dd_mm256_mul_pd(_t550, t3581);
  s4364 = _igen_dd_mm256_sub_pd(_t551, _t552);
  dd_I _t553 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t554 = _igen_dd_mm256_set1_pd(_t553);
  dd_I _t555 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t556 = _ia_neg_dd(_t555);
  ddi_4 _t557 = _igen_dd_mm256_set1_pd(_t556);
  ddi_4 _t558 = _igen_dd_mm256_mul_pd(_t554, t3580);
  ddi_4 _t559 = _igen_dd_mm256_mul_pd(_t557, t3581);
  s4365 = _igen_dd_mm256_add_pd(_t558, _t559);
  t3582 = _igen_dd_mm256_sub_pd(t3554, t3571);
  t3583 = _igen_dd_mm256_add_pd(t3555, t3570);
  dd_I _t560 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t561 = _igen_dd_mm256_set1_pd(_t560);
  ddi_4 _t562 = _igen_dd_mm256_sub_pd(t3582, t3583);
  s4366 = _igen_dd_mm256_mul_pd(_t561, _t562);
  dd_I _t563 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t564 = _igen_dd_mm256_set1_pd(_t563);
  ddi_4 _t565 = _igen_dd_mm256_add_pd(t3582, t3583);
  s4367 = _igen_dd_mm256_mul_pd(_t564, _t565);
  dd_I _t566 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t567 = _ia_neg_dd(_t566);
  ddi_4 _t568 = _igen_dd_mm256_set1_pd(_t567);
  ddi_4 _t569 = _igen_dd_mm256_add_pd(t3554, t3571);
  a1301 = _igen_dd_mm256_mul_pd(_t568, _t569);
  dd_I _t570 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t571 = _igen_dd_mm256_set1_pd(_t570);
  ddi_4 _t572 = _igen_dd_mm256_sub_pd(t3555, t3570);
  a1302 = _igen_dd_mm256_mul_pd(_t571, _t572);
  s4368 = _igen_dd_mm256_sub_pd(a1301, a1302);
  s4369 = _igen_dd_mm256_add_pd(a1301, a1302);
  t3584 = _igen_dd_mm256_add_pd(t3558, s4360);
  t3585 = _igen_dd_mm256_sub_pd(t3559, s4361);
  t3586 = _igen_dd_mm256_sub_pd(t3558, s4360);
  t3587 = _igen_dd_mm256_add_pd(t3559, s4361);
  dd_I _t573 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t574 = _igen_dd_mm256_set1_pd(_t573);
  dd_I _t575 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t576 = _igen_dd_mm256_set1_pd(_t575);
  ddi_4 _t577 = _igen_dd_mm256_mul_pd(_t574, t3584);
  ddi_4 _t578 = _igen_dd_mm256_mul_pd(_t576, t3585);
  s4370 = _igen_dd_mm256_sub_pd(_t577, _t578);
  dd_I _t579 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t580 = _igen_dd_mm256_set1_pd(_t579);
  dd_I _t581 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t582 = _igen_dd_mm256_set1_pd(_t581);
  ddi_4 _t583 = _igen_dd_mm256_mul_pd(_t580, t3584);
  ddi_4 _t584 = _igen_dd_mm256_mul_pd(_t582, t3585);
  s4371 = _igen_dd_mm256_add_pd(_t583, _t584);
  dd_I _t585 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t586 = _ia_neg_dd(_t585);
  ddi_4 _t587 = _igen_dd_mm256_set1_pd(_t586);
  dd_I _t588 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t589 = _igen_dd_mm256_set1_pd(_t588);
  ddi_4 _t590 = _igen_dd_mm256_mul_pd(_t587, t3586);
  ddi_4 _t591 = _igen_dd_mm256_mul_pd(_t589, t3587);
  s4372 = _igen_dd_mm256_sub_pd(_t590, _t591);
  dd_I _t592 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t593 = _igen_dd_mm256_set1_pd(_t592);
  dd_I _t594 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t595 = _ia_neg_dd(_t594);
  ddi_4 _t596 = _igen_dd_mm256_set1_pd(_t595);
  ddi_4 _t597 = _igen_dd_mm256_mul_pd(_t593, t3586);
  ddi_4 _t598 = _igen_dd_mm256_mul_pd(_t596, t3587);
  s4373 = _igen_dd_mm256_add_pd(_t597, _t598);
  t3588 = _igen_dd_mm256_add_pd(t3432, s4264);
  t3589 = _igen_dd_mm256_add_pd(t3433, s4265);
  t3590 = _igen_dd_mm256_sub_pd(t3432, s4264);
  t3591 = _igen_dd_mm256_sub_pd(t3433, s4265);
  t3592 = _igen_dd_mm256_add_pd(s4206, s4324);
  t3593 = _igen_dd_mm256_add_pd(s4207, s4325);
  t3594 = _igen_dd_mm256_sub_pd(s4206, s4324);
  t3595 = _igen_dd_mm256_sub_pd(s4207, s4325);
  t3596 = _igen_dd_mm256_add_pd(t3588, t3592);
  t3597 = _igen_dd_mm256_add_pd(t3589, t3593);
  t3598 = _igen_dd_mm256_sub_pd(t3588, t3592);
  t3599 = _igen_dd_mm256_sub_pd(t3589, t3593);
  t3600 = _igen_dd_mm256_sub_pd(t3590, t3595);
  t3601 = _igen_dd_mm256_add_pd(t3591, t3594);
  t3602 = _igen_dd_mm256_add_pd(t3590, t3595);
  t3603 = _igen_dd_mm256_sub_pd(t3591, t3594);
  t3604 = _igen_dd_mm256_add_pd(s4176, s4294);
  t3605 = _igen_dd_mm256_add_pd(s4177, s4295);
  t3606 = _igen_dd_mm256_sub_pd(s4176, s4294);
  t3607 = _igen_dd_mm256_sub_pd(s4177, s4295);
  t3608 = _igen_dd_mm256_add_pd(s4236, s4354);
  t3609 = _igen_dd_mm256_add_pd(s4237, s4355);
  t3610 = _igen_dd_mm256_sub_pd(s4236, s4354);
  t3611 = _igen_dd_mm256_sub_pd(s4237, s4355);
  t3612 = _igen_dd_mm256_add_pd(t3604, t3608);
  t3613 = _igen_dd_mm256_add_pd(t3605, t3609);
  t3614 = _igen_dd_mm256_sub_pd(t3604, t3608);
  t3615 = _igen_dd_mm256_sub_pd(t3605, t3609);
  t3616 = _igen_dd_mm256_sub_pd(t3606, t3611);
  t3617 = _igen_dd_mm256_add_pd(t3607, t3610);
  dd_I _t599 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t600 = _igen_dd_mm256_set1_pd(_t599);
  ddi_4 _t601 = _igen_dd_mm256_sub_pd(t3616, t3617);
  s4374 = _igen_dd_mm256_mul_pd(_t600, _t601);
  dd_I _t602 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t603 = _igen_dd_mm256_set1_pd(_t602);
  ddi_4 _t604 = _igen_dd_mm256_add_pd(t3616, t3617);
  s4375 = _igen_dd_mm256_mul_pd(_t603, _t604);
  dd_I _t605 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t606 = _ia_neg_dd(_t605);
  ddi_4 _t607 = _igen_dd_mm256_set1_pd(_t606);
  ddi_4 _t608 = _igen_dd_mm256_add_pd(t3606, t3611);
  a1303 = _igen_dd_mm256_mul_pd(_t607, _t608);
  dd_I _t609 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t610 = _igen_dd_mm256_set1_pd(_t609);
  ddi_4 _t611 = _igen_dd_mm256_sub_pd(t3607, t3610);
  a1304 = _igen_dd_mm256_mul_pd(_t610, _t611);
  s4376 = _igen_dd_mm256_sub_pd(a1303, a1304);
  s4377 = _igen_dd_mm256_add_pd(a1303, a1304);
  t3618 = _igen_dd_mm256_add_pd(t3596, t3612);
  t3619 = _igen_dd_mm256_add_pd(t3597, t3613);
  t3620 = _igen_dd_mm256_sub_pd(t3596, t3612);
  t3621 = _igen_dd_mm256_sub_pd(t3597, t3613);
  dd_I _t612 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t613 = _igen_dd_mm256_set1_pd(_t612);
  dd_I _t614 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t615 = _igen_dd_mm256_set1_pd(_t614);
  ddi_4 _t616 = _igen_dd_mm256_mul_pd(_t613, t3618);
  ddi_4 _t617 = _igen_dd_mm256_mul_pd(_t615, t3619);
  s4378 = _igen_dd_mm256_sub_pd(_t616, _t617);
  dd_I _t618 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t619 = _igen_dd_mm256_set1_pd(_t618);
  dd_I _t620 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t621 = _igen_dd_mm256_set1_pd(_t620);
  ddi_4 _t622 = _igen_dd_mm256_mul_pd(_t619, t3618);
  ddi_4 _t623 = _igen_dd_mm256_mul_pd(_t621, t3619);
  s4379 = _igen_dd_mm256_add_pd(_t622, _t623);
  dd_I _t624 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t625 = _ia_neg_dd(_t624);
  ddi_4 _t626 = _igen_dd_mm256_set1_pd(_t625);
  dd_I _t627 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t628 = _igen_dd_mm256_set1_pd(_t627);
  ddi_4 _t629 = _igen_dd_mm256_mul_pd(_t626, t3620);
  ddi_4 _t630 = _igen_dd_mm256_mul_pd(_t628, t3621);
  s4380 = _igen_dd_mm256_sub_pd(_t629, _t630);
  dd_I _t631 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t632 = _igen_dd_mm256_set1_pd(_t631);
  dd_I _t633 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t634 = _ia_neg_dd(_t633);
  ddi_4 _t635 = _igen_dd_mm256_set1_pd(_t634);
  ddi_4 _t636 = _igen_dd_mm256_mul_pd(_t632, t3620);
  ddi_4 _t637 = _igen_dd_mm256_mul_pd(_t635, t3621);
  s4381 = _igen_dd_mm256_add_pd(_t636, _t637);
  t3622 = _igen_dd_mm256_add_pd(t3600, s4374);
  t3623 = _igen_dd_mm256_add_pd(t3601, s4375);
  t3624 = _igen_dd_mm256_sub_pd(t3600, s4374);
  t3625 = _igen_dd_mm256_sub_pd(t3601, s4375);
  dd_I _t638 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t639 = _igen_dd_mm256_set1_pd(_t638);
  dd_I _t640 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t641 = _igen_dd_mm256_set1_pd(_t640);
  ddi_4 _t642 = _igen_dd_mm256_mul_pd(_t639, t3622);
  ddi_4 _t643 = _igen_dd_mm256_mul_pd(_t641, t3623);
  s4382 = _igen_dd_mm256_sub_pd(_t642, _t643);
  dd_I _t644 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t645 = _igen_dd_mm256_set1_pd(_t644);
  dd_I _t646 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t647 = _igen_dd_mm256_set1_pd(_t646);
  ddi_4 _t648 = _igen_dd_mm256_mul_pd(_t645, t3622);
  ddi_4 _t649 = _igen_dd_mm256_mul_pd(_t647, t3623);
  s4383 = _igen_dd_mm256_add_pd(_t648, _t649);
  dd_I _t650 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t651 = _ia_neg_dd(_t650);
  ddi_4 _t652 = _igen_dd_mm256_set1_pd(_t651);
  dd_I _t653 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t654 = _igen_dd_mm256_set1_pd(_t653);
  ddi_4 _t655 = _igen_dd_mm256_mul_pd(_t652, t3624);
  ddi_4 _t656 = _igen_dd_mm256_mul_pd(_t654, t3625);
  s4384 = _igen_dd_mm256_sub_pd(_t655, _t656);
  dd_I _t657 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t658 = _igen_dd_mm256_set1_pd(_t657);
  dd_I _t659 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t660 = _ia_neg_dd(_t659);
  ddi_4 _t661 = _igen_dd_mm256_set1_pd(_t660);
  ddi_4 _t662 = _igen_dd_mm256_mul_pd(_t658, t3624);
  ddi_4 _t663 = _igen_dd_mm256_mul_pd(_t661, t3625);
  s4385 = _igen_dd_mm256_add_pd(_t662, _t663);
  t3626 = _igen_dd_mm256_sub_pd(t3598, t3615);
  t3627 = _igen_dd_mm256_add_pd(t3599, t3614);
  t3628 = _igen_dd_mm256_add_pd(t3598, t3615);
  t3629 = _igen_dd_mm256_sub_pd(t3599, t3614);
  dd_I _t664 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t665 = _igen_dd_mm256_set1_pd(_t664);
  dd_I _t666 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t667 = _igen_dd_mm256_set1_pd(_t666);
  ddi_4 _t668 = _igen_dd_mm256_mul_pd(_t665, t3626);
  ddi_4 _t669 = _igen_dd_mm256_mul_pd(_t667, t3627);
  s4386 = _igen_dd_mm256_sub_pd(_t668, _t669);
  dd_I _t670 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t671 = _igen_dd_mm256_set1_pd(_t670);
  dd_I _t672 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t673 = _igen_dd_mm256_set1_pd(_t672);
  ddi_4 _t674 = _igen_dd_mm256_mul_pd(_t671, t3626);
  ddi_4 _t675 = _igen_dd_mm256_mul_pd(_t673, t3627);
  s4387 = _igen_dd_mm256_add_pd(_t674, _t675);
  dd_I _t676 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t677 = _ia_neg_dd(_t676);
  ddi_4 _t678 = _igen_dd_mm256_set1_pd(_t677);
  dd_I _t679 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t680 = _igen_dd_mm256_set1_pd(_t679);
  ddi_4 _t681 = _igen_dd_mm256_mul_pd(_t678, t3628);
  ddi_4 _t682 = _igen_dd_mm256_mul_pd(_t680, t3629);
  s4388 = _igen_dd_mm256_sub_pd(_t681, _t682);
  dd_I _t683 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t684 = _igen_dd_mm256_set1_pd(_t683);
  dd_I _t685 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t686 = _ia_neg_dd(_t685);
  ddi_4 _t687 = _igen_dd_mm256_set1_pd(_t686);
  ddi_4 _t688 = _igen_dd_mm256_mul_pd(_t684, t3628);
  ddi_4 _t689 = _igen_dd_mm256_mul_pd(_t687, t3629);
  s4389 = _igen_dd_mm256_add_pd(_t688, _t689);
  t3630 = _igen_dd_mm256_add_pd(t3602, s4376);
  t3631 = _igen_dd_mm256_sub_pd(t3603, s4377);
  t3632 = _igen_dd_mm256_sub_pd(t3602, s4376);
  t3633 = _igen_dd_mm256_add_pd(t3603, s4377);
  dd_I _t690 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t691 = _igen_dd_mm256_set1_pd(_t690);
  dd_I _t692 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t693 = _igen_dd_mm256_set1_pd(_t692);
  ddi_4 _t694 = _igen_dd_mm256_mul_pd(_t691, t3630);
  ddi_4 _t695 = _igen_dd_mm256_mul_pd(_t693, t3631);
  s4390 = _igen_dd_mm256_sub_pd(_t694, _t695);
  dd_I _t696 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t697 = _igen_dd_mm256_set1_pd(_t696);
  dd_I _t698 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t699 = _igen_dd_mm256_set1_pd(_t698);
  ddi_4 _t700 = _igen_dd_mm256_mul_pd(_t697, t3630);
  ddi_4 _t701 = _igen_dd_mm256_mul_pd(_t699, t3631);
  s4391 = _igen_dd_mm256_add_pd(_t700, _t701);
  dd_I _t702 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t703 = _ia_neg_dd(_t702);
  ddi_4 _t704 = _igen_dd_mm256_set1_pd(_t703);
  dd_I _t705 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t706 = _igen_dd_mm256_set1_pd(_t705);
  ddi_4 _t707 = _igen_dd_mm256_mul_pd(_t704, t3632);
  ddi_4 _t708 = _igen_dd_mm256_mul_pd(_t706, t3633);
  s4392 = _igen_dd_mm256_sub_pd(_t707, _t708);
  dd_I _t709 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t710 = _igen_dd_mm256_set1_pd(_t709);
  dd_I _t711 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t712 = _ia_neg_dd(_t711);
  ddi_4 _t713 = _igen_dd_mm256_set1_pd(_t712);
  ddi_4 _t714 = _igen_dd_mm256_mul_pd(_t710, t3632);
  ddi_4 _t715 = _igen_dd_mm256_mul_pd(_t713, t3633);
  s4393 = _igen_dd_mm256_add_pd(_t714, _t715);
  t3634 = _igen_dd_mm256_sub_pd(t3430, t3495);
  t3635 = _igen_dd_mm256_add_pd(t3431, t3494);
  t3636 = _igen_dd_mm256_add_pd(t3430, t3495);
  t3637 = _igen_dd_mm256_sub_pd(t3431, t3494);
  t3638 = _igen_dd_mm256_add_pd(s4204, s4322);
  t3639 = _igen_dd_mm256_sub_pd(s4205, s4323);
  t3640 = _igen_dd_mm256_sub_pd(s4204, s4322);
  t3641 = _igen_dd_mm256_add_pd(s4205, s4323);
  t3642 = _igen_dd_mm256_add_pd(t3634, t3638);
  t3643 = _igen_dd_mm256_add_pd(t3635, t3639);
  t3644 = _igen_dd_mm256_sub_pd(t3634, t3638);
  t3645 = _igen_dd_mm256_sub_pd(t3635, t3639);
  t3646 = _igen_dd_mm256_sub_pd(t3636, t3641);
  t3647 = _igen_dd_mm256_add_pd(t3637, t3640);
  t3648 = _igen_dd_mm256_add_pd(t3636, t3641);
  t3649 = _igen_dd_mm256_sub_pd(t3637, t3640);
  t3650 = _igen_dd_mm256_add_pd(s4174, s4292);
  t3651 = _igen_dd_mm256_add_pd(s4175, s4293);
  t3652 = _igen_dd_mm256_sub_pd(s4174, s4292);
  t3653 = _igen_dd_mm256_sub_pd(s4175, s4293);
  t3654 = _igen_dd_mm256_add_pd(s4234, s4352);
  t3655 = _igen_dd_mm256_add_pd(s4235, s4353);
  t3656 = _igen_dd_mm256_sub_pd(s4234, s4352);
  t3657 = _igen_dd_mm256_sub_pd(s4235, s4353);
  t3658 = _igen_dd_mm256_add_pd(t3650, t3654);
  t3659 = _igen_dd_mm256_add_pd(t3651, t3655);
  t3660 = _igen_dd_mm256_sub_pd(t3650, t3654);
  t3661 = _igen_dd_mm256_sub_pd(t3651, t3655);
  t3662 = _igen_dd_mm256_sub_pd(t3652, t3657);
  t3663 = _igen_dd_mm256_add_pd(t3653, t3656);
  dd_I _t716 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t717 = _igen_dd_mm256_set1_pd(_t716);
  ddi_4 _t718 = _igen_dd_mm256_sub_pd(t3662, t3663);
  s4394 = _igen_dd_mm256_mul_pd(_t717, _t718);
  dd_I _t719 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t720 = _igen_dd_mm256_set1_pd(_t719);
  ddi_4 _t721 = _igen_dd_mm256_add_pd(t3662, t3663);
  s4395 = _igen_dd_mm256_mul_pd(_t720, _t721);
  dd_I _t722 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t723 = _ia_neg_dd(_t722);
  ddi_4 _t724 = _igen_dd_mm256_set1_pd(_t723);
  ddi_4 _t725 = _igen_dd_mm256_add_pd(t3652, t3657);
  a1305 = _igen_dd_mm256_mul_pd(_t724, _t725);
  dd_I _t726 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t727 = _igen_dd_mm256_set1_pd(_t726);
  ddi_4 _t728 = _igen_dd_mm256_sub_pd(t3653, t3656);
  a1306 = _igen_dd_mm256_mul_pd(_t727, _t728);
  s4396 = _igen_dd_mm256_sub_pd(a1305, a1306);
  s4397 = _igen_dd_mm256_add_pd(a1305, a1306);
  t3664 = _igen_dd_mm256_add_pd(t3642, t3658);
  t3665 = _igen_dd_mm256_add_pd(t3643, t3659);
  t3666 = _igen_dd_mm256_sub_pd(t3642, t3658);
  t3667 = _igen_dd_mm256_sub_pd(t3643, t3659);
  dd_I _t729 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t730 = _igen_dd_mm256_set1_pd(_t729);
  dd_I _t731 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t732 = _igen_dd_mm256_set1_pd(_t731);
  ddi_4 _t733 = _igen_dd_mm256_mul_pd(_t730, t3664);
  ddi_4 _t734 = _igen_dd_mm256_mul_pd(_t732, t3665);
  s4398 = _igen_dd_mm256_sub_pd(_t733, _t734);
  dd_I _t735 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t736 = _igen_dd_mm256_set1_pd(_t735);
  dd_I _t737 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t738 = _igen_dd_mm256_set1_pd(_t737);
  ddi_4 _t739 = _igen_dd_mm256_mul_pd(_t736, t3664);
  ddi_4 _t740 = _igen_dd_mm256_mul_pd(_t738, t3665);
  s4399 = _igen_dd_mm256_add_pd(_t739, _t740);
  dd_I _t741 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t742 = _ia_neg_dd(_t741);
  ddi_4 _t743 = _igen_dd_mm256_set1_pd(_t742);
  dd_I _t744 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t745 = _igen_dd_mm256_set1_pd(_t744);
  ddi_4 _t746 = _igen_dd_mm256_mul_pd(_t743, t3666);
  ddi_4 _t747 = _igen_dd_mm256_mul_pd(_t745, t3667);
  s4400 = _igen_dd_mm256_sub_pd(_t746, _t747);
  dd_I _t748 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t749 = _igen_dd_mm256_set1_pd(_t748);
  dd_I _t750 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t751 = _ia_neg_dd(_t750);
  ddi_4 _t752 = _igen_dd_mm256_set1_pd(_t751);
  ddi_4 _t753 = _igen_dd_mm256_mul_pd(_t749, t3666);
  ddi_4 _t754 = _igen_dd_mm256_mul_pd(_t752, t3667);
  s4401 = _igen_dd_mm256_add_pd(_t753, _t754);
  t3668 = _igen_dd_mm256_add_pd(t3646, s4394);
  t3669 = _igen_dd_mm256_add_pd(t3647, s4395);
  t3670 = _igen_dd_mm256_sub_pd(t3646, s4394);
  t3671 = _igen_dd_mm256_sub_pd(t3647, s4395);
  dd_I _t755 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t756 = _igen_dd_mm256_set1_pd(_t755);
  dd_I _t757 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t758 = _igen_dd_mm256_set1_pd(_t757);
  ddi_4 _t759 = _igen_dd_mm256_mul_pd(_t756, t3668);
  ddi_4 _t760 = _igen_dd_mm256_mul_pd(_t758, t3669);
  s4402 = _igen_dd_mm256_sub_pd(_t759, _t760);
  dd_I _t761 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t762 = _igen_dd_mm256_set1_pd(_t761);
  dd_I _t763 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t764 = _igen_dd_mm256_set1_pd(_t763);
  ddi_4 _t765 = _igen_dd_mm256_mul_pd(_t762, t3668);
  ddi_4 _t766 = _igen_dd_mm256_mul_pd(_t764, t3669);
  s4403 = _igen_dd_mm256_add_pd(_t765, _t766);
  dd_I _t767 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t768 = _ia_neg_dd(_t767);
  ddi_4 _t769 = _igen_dd_mm256_set1_pd(_t768);
  dd_I _t770 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t771 = _igen_dd_mm256_set1_pd(_t770);
  ddi_4 _t772 = _igen_dd_mm256_mul_pd(_t769, t3670);
  ddi_4 _t773 = _igen_dd_mm256_mul_pd(_t771, t3671);
  s4404 = _igen_dd_mm256_sub_pd(_t772, _t773);
  dd_I _t774 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t775 = _igen_dd_mm256_set1_pd(_t774);
  dd_I _t776 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t777 = _ia_neg_dd(_t776);
  ddi_4 _t778 = _igen_dd_mm256_set1_pd(_t777);
  ddi_4 _t779 = _igen_dd_mm256_mul_pd(_t775, t3670);
  ddi_4 _t780 = _igen_dd_mm256_mul_pd(_t778, t3671);
  s4405 = _igen_dd_mm256_add_pd(_t779, _t780);
  t3672 = _igen_dd_mm256_sub_pd(t3644, t3661);
  t3673 = _igen_dd_mm256_add_pd(t3645, t3660);
  t3674 = _igen_dd_mm256_add_pd(t3644, t3661);
  t3675 = _igen_dd_mm256_sub_pd(t3645, t3660);
  dd_I _t781 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t782 = _igen_dd_mm256_set1_pd(_t781);
  dd_I _t783 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t784 = _igen_dd_mm256_set1_pd(_t783);
  ddi_4 _t785 = _igen_dd_mm256_mul_pd(_t782, t3672);
  ddi_4 _t786 = _igen_dd_mm256_mul_pd(_t784, t3673);
  s4406 = _igen_dd_mm256_sub_pd(_t785, _t786);
  dd_I _t787 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t788 = _igen_dd_mm256_set1_pd(_t787);
  dd_I _t789 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t790 = _igen_dd_mm256_set1_pd(_t789);
  ddi_4 _t791 = _igen_dd_mm256_mul_pd(_t788, t3672);
  ddi_4 _t792 = _igen_dd_mm256_mul_pd(_t790, t3673);
  s4407 = _igen_dd_mm256_add_pd(_t791, _t792);
  dd_I _t793 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t794 = _ia_neg_dd(_t793);
  ddi_4 _t795 = _igen_dd_mm256_set1_pd(_t794);
  dd_I _t796 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t797 = _igen_dd_mm256_set1_pd(_t796);
  ddi_4 _t798 = _igen_dd_mm256_mul_pd(_t795, t3674);
  ddi_4 _t799 = _igen_dd_mm256_mul_pd(_t797, t3675);
  s4408 = _igen_dd_mm256_sub_pd(_t798, _t799);
  dd_I _t800 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t801 = _igen_dd_mm256_set1_pd(_t800);
  dd_I _t802 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t803 = _ia_neg_dd(_t802);
  ddi_4 _t804 = _igen_dd_mm256_set1_pd(_t803);
  ddi_4 _t805 = _igen_dd_mm256_mul_pd(_t801, t3674);
  ddi_4 _t806 = _igen_dd_mm256_mul_pd(_t804, t3675);
  s4409 = _igen_dd_mm256_add_pd(_t805, _t806);
  t3676 = _igen_dd_mm256_add_pd(t3648, s4396);
  t3677 = _igen_dd_mm256_sub_pd(t3649, s4397);
  t3678 = _igen_dd_mm256_sub_pd(t3648, s4396);
  t3679 = _igen_dd_mm256_add_pd(t3649, s4397);
  dd_I _t807 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t808 = _igen_dd_mm256_set1_pd(_t807);
  dd_I _t809 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t810 = _igen_dd_mm256_set1_pd(_t809);
  ddi_4 _t811 = _igen_dd_mm256_mul_pd(_t808, t3676);
  ddi_4 _t812 = _igen_dd_mm256_mul_pd(_t810, t3677);
  s4410 = _igen_dd_mm256_sub_pd(_t811, _t812);
  dd_I _t813 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t814 = _igen_dd_mm256_set1_pd(_t813);
  dd_I _t815 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t816 = _igen_dd_mm256_set1_pd(_t815);
  ddi_4 _t817 = _igen_dd_mm256_mul_pd(_t814, t3676);
  ddi_4 _t818 = _igen_dd_mm256_mul_pd(_t816, t3677);
  s4411 = _igen_dd_mm256_add_pd(_t817, _t818);
  dd_I _t819 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t820 = _ia_neg_dd(_t819);
  ddi_4 _t821 = _igen_dd_mm256_set1_pd(_t820);
  dd_I _t822 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t823 = _igen_dd_mm256_set1_pd(_t822);
  ddi_4 _t824 = _igen_dd_mm256_mul_pd(_t821, t3678);
  ddi_4 _t825 = _igen_dd_mm256_mul_pd(_t823, t3679);
  s4412 = _igen_dd_mm256_sub_pd(_t824, _t825);
  dd_I _t826 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t827 = _igen_dd_mm256_set1_pd(_t826);
  dd_I _t828 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t829 = _ia_neg_dd(_t828);
  ddi_4 _t830 = _igen_dd_mm256_set1_pd(_t829);
  ddi_4 _t831 = _igen_dd_mm256_mul_pd(_t827, t3678);
  ddi_4 _t832 = _igen_dd_mm256_mul_pd(_t830, t3679);
  s4413 = _igen_dd_mm256_add_pd(_t831, _t832);
  t3680 = _igen_dd_mm256_add_pd(t3434, s4266);
  t3681 = _igen_dd_mm256_sub_pd(t3435, s4267);
  t3682 = _igen_dd_mm256_sub_pd(t3434, s4266);
  t3683 = _igen_dd_mm256_add_pd(t3435, s4267);
  t3684 = _igen_dd_mm256_add_pd(s4208, s4326);
  t3685 = _igen_dd_mm256_add_pd(s4209, s4327);
  t3686 = _igen_dd_mm256_sub_pd(s4208, s4326);
  t3687 = _igen_dd_mm256_sub_pd(s4209, s4327);
  t3688 = _igen_dd_mm256_add_pd(t3680, t3684);
  t3689 = _igen_dd_mm256_add_pd(t3681, t3685);
  t3690 = _igen_dd_mm256_sub_pd(t3680, t3684);
  t3691 = _igen_dd_mm256_sub_pd(t3681, t3685);
  t3692 = _igen_dd_mm256_sub_pd(t3682, t3687);
  t3693 = _igen_dd_mm256_add_pd(t3683, t3686);
  t3694 = _igen_dd_mm256_add_pd(t3682, t3687);
  t3695 = _igen_dd_mm256_sub_pd(t3683, t3686);
  t3696 = _igen_dd_mm256_add_pd(s4178, s4296);
  t3697 = _igen_dd_mm256_add_pd(s4179, s4297);
  t3698 = _igen_dd_mm256_sub_pd(s4178, s4296);
  t3699 = _igen_dd_mm256_sub_pd(s4179, s4297);
  t3700 = _igen_dd_mm256_add_pd(s4238, s4356);
  t3701 = _igen_dd_mm256_add_pd(s4239, s4357);
  t3702 = _igen_dd_mm256_sub_pd(s4238, s4356);
  t3703 = _igen_dd_mm256_sub_pd(s4239, s4357);
  t3704 = _igen_dd_mm256_add_pd(t3696, t3700);
  t3705 = _igen_dd_mm256_add_pd(t3697, t3701);
  t3706 = _igen_dd_mm256_sub_pd(t3696, t3700);
  t3707 = _igen_dd_mm256_sub_pd(t3697, t3701);
  t3708 = _igen_dd_mm256_sub_pd(t3698, t3703);
  t3709 = _igen_dd_mm256_add_pd(t3699, t3702);
  dd_I _t833 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t834 = _igen_dd_mm256_set1_pd(_t833);
  ddi_4 _t835 = _igen_dd_mm256_sub_pd(t3708, t3709);
  s4414 = _igen_dd_mm256_mul_pd(_t834, _t835);
  dd_I _t836 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t837 = _igen_dd_mm256_set1_pd(_t836);
  ddi_4 _t838 = _igen_dd_mm256_add_pd(t3708, t3709);
  s4415 = _igen_dd_mm256_mul_pd(_t837, _t838);
  dd_I _t839 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t840 = _ia_neg_dd(_t839);
  ddi_4 _t841 = _igen_dd_mm256_set1_pd(_t840);
  ddi_4 _t842 = _igen_dd_mm256_add_pd(t3698, t3703);
  a1307 = _igen_dd_mm256_mul_pd(_t841, _t842);
  dd_I _t843 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t844 = _igen_dd_mm256_set1_pd(_t843);
  ddi_4 _t845 = _igen_dd_mm256_sub_pd(t3699, t3702);
  a1308 = _igen_dd_mm256_mul_pd(_t844, _t845);
  s4416 = _igen_dd_mm256_sub_pd(a1307, a1308);
  s4417 = _igen_dd_mm256_add_pd(a1307, a1308);
  t3710 = _igen_dd_mm256_add_pd(t3688, t3704);
  t3711 = _igen_dd_mm256_add_pd(t3689, t3705);
  t3712 = _igen_dd_mm256_sub_pd(t3688, t3704);
  t3713 = _igen_dd_mm256_sub_pd(t3689, t3705);
  dd_I _t846 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t847 = _igen_dd_mm256_set1_pd(_t846);
  dd_I _t848 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t849 = _igen_dd_mm256_set1_pd(_t848);
  ddi_4 _t850 = _igen_dd_mm256_mul_pd(_t847, t3710);
  ddi_4 _t851 = _igen_dd_mm256_mul_pd(_t849, t3711);
  s4418 = _igen_dd_mm256_sub_pd(_t850, _t851);
  dd_I _t852 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t853 = _igen_dd_mm256_set1_pd(_t852);
  dd_I _t854 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t855 = _igen_dd_mm256_set1_pd(_t854);
  ddi_4 _t856 = _igen_dd_mm256_mul_pd(_t853, t3710);
  ddi_4 _t857 = _igen_dd_mm256_mul_pd(_t855, t3711);
  s4419 = _igen_dd_mm256_add_pd(_t856, _t857);
  dd_I _t858 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t859 = _ia_neg_dd(_t858);
  ddi_4 _t860 = _igen_dd_mm256_set1_pd(_t859);
  dd_I _t861 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t862 = _igen_dd_mm256_set1_pd(_t861);
  ddi_4 _t863 = _igen_dd_mm256_mul_pd(_t860, t3712);
  ddi_4 _t864 = _igen_dd_mm256_mul_pd(_t862, t3713);
  s4420 = _igen_dd_mm256_sub_pd(_t863, _t864);
  dd_I _t865 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t866 = _igen_dd_mm256_set1_pd(_t865);
  dd_I _t867 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t868 = _ia_neg_dd(_t867);
  ddi_4 _t869 = _igen_dd_mm256_set1_pd(_t868);
  ddi_4 _t870 = _igen_dd_mm256_mul_pd(_t866, t3712);
  ddi_4 _t871 = _igen_dd_mm256_mul_pd(_t869, t3713);
  s4421 = _igen_dd_mm256_add_pd(_t870, _t871);
  t3714 = _igen_dd_mm256_add_pd(t3692, s4414);
  t3715 = _igen_dd_mm256_add_pd(t3693, s4415);
  t3716 = _igen_dd_mm256_sub_pd(t3692, s4414);
  t3717 = _igen_dd_mm256_sub_pd(t3693, s4415);
  dd_I _t872 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t873 = _igen_dd_mm256_set1_pd(_t872);
  dd_I _t874 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t875 = _igen_dd_mm256_set1_pd(_t874);
  ddi_4 _t876 = _igen_dd_mm256_mul_pd(_t873, t3714);
  ddi_4 _t877 = _igen_dd_mm256_mul_pd(_t875, t3715);
  s4422 = _igen_dd_mm256_sub_pd(_t876, _t877);
  dd_I _t878 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t879 = _igen_dd_mm256_set1_pd(_t878);
  dd_I _t880 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t881 = _igen_dd_mm256_set1_pd(_t880);
  ddi_4 _t882 = _igen_dd_mm256_mul_pd(_t879, t3714);
  ddi_4 _t883 = _igen_dd_mm256_mul_pd(_t881, t3715);
  s4423 = _igen_dd_mm256_add_pd(_t882, _t883);
  dd_I _t884 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t885 = _ia_neg_dd(_t884);
  ddi_4 _t886 = _igen_dd_mm256_set1_pd(_t885);
  dd_I _t887 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t888 = _igen_dd_mm256_set1_pd(_t887);
  ddi_4 _t889 = _igen_dd_mm256_mul_pd(_t886, t3716);
  ddi_4 _t890 = _igen_dd_mm256_mul_pd(_t888, t3717);
  s4424 = _igen_dd_mm256_sub_pd(_t889, _t890);
  dd_I _t891 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t892 = _igen_dd_mm256_set1_pd(_t891);
  dd_I _t893 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t894 = _ia_neg_dd(_t893);
  ddi_4 _t895 = _igen_dd_mm256_set1_pd(_t894);
  ddi_4 _t896 = _igen_dd_mm256_mul_pd(_t892, t3716);
  ddi_4 _t897 = _igen_dd_mm256_mul_pd(_t895, t3717);
  s4425 = _igen_dd_mm256_add_pd(_t896, _t897);
  t3718 = _igen_dd_mm256_sub_pd(t3690, t3707);
  t3719 = _igen_dd_mm256_add_pd(t3691, t3706);
  t3720 = _igen_dd_mm256_add_pd(t3690, t3707);
  t3721 = _igen_dd_mm256_sub_pd(t3691, t3706);
  dd_I _t898 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t899 = _igen_dd_mm256_set1_pd(_t898);
  dd_I _t900 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t901 = _igen_dd_mm256_set1_pd(_t900);
  ddi_4 _t902 = _igen_dd_mm256_mul_pd(_t899, t3718);
  ddi_4 _t903 = _igen_dd_mm256_mul_pd(_t901, t3719);
  s4426 = _igen_dd_mm256_sub_pd(_t902, _t903);
  dd_I _t904 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t905 = _igen_dd_mm256_set1_pd(_t904);
  dd_I _t906 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t907 = _igen_dd_mm256_set1_pd(_t906);
  ddi_4 _t908 = _igen_dd_mm256_mul_pd(_t905, t3718);
  ddi_4 _t909 = _igen_dd_mm256_mul_pd(_t907, t3719);
  s4427 = _igen_dd_mm256_add_pd(_t908, _t909);
  dd_I _t910 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t911 = _ia_neg_dd(_t910);
  ddi_4 _t912 = _igen_dd_mm256_set1_pd(_t911);
  dd_I _t913 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t914 = _igen_dd_mm256_set1_pd(_t913);
  ddi_4 _t915 = _igen_dd_mm256_mul_pd(_t912, t3720);
  ddi_4 _t916 = _igen_dd_mm256_mul_pd(_t914, t3721);
  s4428 = _igen_dd_mm256_sub_pd(_t915, _t916);
  dd_I _t917 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t918 = _igen_dd_mm256_set1_pd(_t917);
  dd_I _t919 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t920 = _ia_neg_dd(_t919);
  ddi_4 _t921 = _igen_dd_mm256_set1_pd(_t920);
  ddi_4 _t922 = _igen_dd_mm256_mul_pd(_t918, t3720);
  ddi_4 _t923 = _igen_dd_mm256_mul_pd(_t921, t3721);
  s4429 = _igen_dd_mm256_add_pd(_t922, _t923);
  t3722 = _igen_dd_mm256_add_pd(t3694, s4416);
  t3723 = _igen_dd_mm256_sub_pd(t3695, s4417);
  t3724 = _igen_dd_mm256_sub_pd(t3694, s4416);
  t3725 = _igen_dd_mm256_add_pd(t3695, s4417);
  dd_I _t924 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t925 = _igen_dd_mm256_set1_pd(_t924);
  dd_I _t926 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t927 = _igen_dd_mm256_set1_pd(_t926);
  ddi_4 _t928 = _igen_dd_mm256_mul_pd(_t925, t3722);
  ddi_4 _t929 = _igen_dd_mm256_mul_pd(_t927, t3723);
  s4430 = _igen_dd_mm256_sub_pd(_t928, _t929);
  dd_I _t930 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t931 = _igen_dd_mm256_set1_pd(_t930);
  dd_I _t932 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t933 = _igen_dd_mm256_set1_pd(_t932);
  ddi_4 _t934 = _igen_dd_mm256_mul_pd(_t931, t3722);
  ddi_4 _t935 = _igen_dd_mm256_mul_pd(_t933, t3723);
  s4431 = _igen_dd_mm256_add_pd(_t934, _t935);
  dd_I _t936 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t937 = _ia_neg_dd(_t936);
  ddi_4 _t938 = _igen_dd_mm256_set1_pd(_t937);
  dd_I _t939 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t940 = _igen_dd_mm256_set1_pd(_t939);
  ddi_4 _t941 = _igen_dd_mm256_mul_pd(_t938, t3724);
  ddi_4 _t942 = _igen_dd_mm256_mul_pd(_t940, t3725);
  s4432 = _igen_dd_mm256_sub_pd(_t941, _t942);
  dd_I _t943 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t944 = _igen_dd_mm256_set1_pd(_t943);
  dd_I _t945 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t946 = _ia_neg_dd(_t945);
  ddi_4 _t947 = _igen_dd_mm256_set1_pd(_t946);
  ddi_4 _t948 = _igen_dd_mm256_mul_pd(_t944, t3724);
  ddi_4 _t949 = _igen_dd_mm256_mul_pd(_t947, t3725);
  s4433 = _igen_dd_mm256_add_pd(_t948, _t949);
  t3726 = _igen_dd_mm256_add_pd(t3266, t3574);
  t3727 = _igen_dd_mm256_add_pd(t3267, t3575);
  t3728 = _igen_dd_mm256_sub_pd(t3266, t3574);
  t3729 = _igen_dd_mm256_sub_pd(t3267, t3575);
  t3730 = _igen_dd_mm256_add_pd(t3312, s4378);
  t3731 = _igen_dd_mm256_add_pd(t3313, s4379);
  t3732 = _igen_dd_mm256_sub_pd(t3312, s4378);
  t3733 = _igen_dd_mm256_sub_pd(t3313, s4379);
  t3734 = _igen_dd_mm256_add_pd(t3358, s4398);
  t3735 = _igen_dd_mm256_add_pd(t3359, s4399);
  t3736 = _igen_dd_mm256_sub_pd(t3358, s4398);
  t3737 = _igen_dd_mm256_sub_pd(t3359, s4399);
  t3738 = _igen_dd_mm256_add_pd(t3404, s4418);
  t3739 = _igen_dd_mm256_add_pd(t3405, s4419);
  t3740 = _igen_dd_mm256_sub_pd(t3404, s4418);
  t3741 = _igen_dd_mm256_sub_pd(t3405, s4419);
  t3742 = _igen_dd_mm256_add_pd(t3270, s4362);
  t3743 = _igen_dd_mm256_add_pd(t3271, s4363);
  t3744 = _igen_dd_mm256_sub_pd(t3270, s4362);
  t3745 = _igen_dd_mm256_sub_pd(t3271, s4363);
  t3746 = _igen_dd_mm256_add_pd(t3316, s4382);
  t3747 = _igen_dd_mm256_add_pd(t3317, s4383);
  t3748 = _igen_dd_mm256_sub_pd(t3316, s4382);
  t3749 = _igen_dd_mm256_sub_pd(t3317, s4383);
  t3750 = _igen_dd_mm256_add_pd(t3362, s4402);
  t3751 = _igen_dd_mm256_add_pd(t3363, s4403);
  t3752 = _igen_dd_mm256_sub_pd(t3362, s4402);
  t3753 = _igen_dd_mm256_sub_pd(t3363, s4403);
  t3754 = _igen_dd_mm256_add_pd(t3408, s4422);
  t3755 = _igen_dd_mm256_add_pd(t3409, s4423);
  t3756 = _igen_dd_mm256_sub_pd(t3408, s4422);
  t3757 = _igen_dd_mm256_sub_pd(t3409, s4423);
  t3758 = _igen_dd_mm256_add_pd(t3274, s4366);
  t3759 = _igen_dd_mm256_add_pd(t3275, s4367);
  t3760 = _igen_dd_mm256_sub_pd(t3274, s4366);
  t3761 = _igen_dd_mm256_sub_pd(t3275, s4367);
  t3762 = _igen_dd_mm256_add_pd(t3320, s4386);
  t3763 = _igen_dd_mm256_add_pd(t3321, s4387);
  t3764 = _igen_dd_mm256_sub_pd(t3320, s4386);
  t3765 = _igen_dd_mm256_sub_pd(t3321, s4387);
  t3766 = _igen_dd_mm256_add_pd(t3366, s4406);
  t3767 = _igen_dd_mm256_add_pd(t3367, s4407);
  t3768 = _igen_dd_mm256_sub_pd(t3366, s4406);
  t3769 = _igen_dd_mm256_sub_pd(t3367, s4407);
  t3770 = _igen_dd_mm256_add_pd(t3412, s4426);
  t3771 = _igen_dd_mm256_add_pd(t3413, s4427);
  t3772 = _igen_dd_mm256_sub_pd(t3412, s4426);
  t3773 = _igen_dd_mm256_sub_pd(t3413, s4427);
  t3774 = _igen_dd_mm256_add_pd(t3278, s4370);
  t3775 = _igen_dd_mm256_add_pd(t3279, s4371);
  t3776 = _igen_dd_mm256_sub_pd(t3278, s4370);
  t3777 = _igen_dd_mm256_sub_pd(t3279, s4371);
  t3778 = _igen_dd_mm256_add_pd(t3324, s4390);
  t3779 = _igen_dd_mm256_add_pd(t3325, s4391);
  t3780 = _igen_dd_mm256_sub_pd(t3324, s4390);
  t3781 = _igen_dd_mm256_sub_pd(t3325, s4391);
  t3782 = _igen_dd_mm256_add_pd(t3370, s4410);
  t3783 = _igen_dd_mm256_add_pd(t3371, s4411);
  t3784 = _igen_dd_mm256_sub_pd(t3370, s4410);
  t3785 = _igen_dd_mm256_sub_pd(t3371, s4411);
  t3786 = _igen_dd_mm256_add_pd(t3416, s4430);
  t3787 = _igen_dd_mm256_add_pd(t3417, s4431);
  t3788 = _igen_dd_mm256_sub_pd(t3416, s4430);
  t3789 = _igen_dd_mm256_sub_pd(t3417, s4431);
  t3790 = _igen_dd_mm256_sub_pd(t3268, t3577);
  t3791 = _igen_dd_mm256_add_pd(t3269, t3576);
  t3792 = _igen_dd_mm256_add_pd(t3268, t3577);
  t3793 = _igen_dd_mm256_sub_pd(t3269, t3576);
  t3794 = _igen_dd_mm256_add_pd(t3314, s4380);
  t3795 = _igen_dd_mm256_add_pd(t3315, s4381);
  t3796 = _igen_dd_mm256_sub_pd(t3314, s4380);
  t3797 = _igen_dd_mm256_sub_pd(t3315, s4381);
  t3798 = _igen_dd_mm256_add_pd(t3360, s4400);
  t3799 = _igen_dd_mm256_add_pd(t3361, s4401);
  t3800 = _igen_dd_mm256_sub_pd(t3360, s4400);
  t3801 = _igen_dd_mm256_sub_pd(t3361, s4401);
  t3802 = _igen_dd_mm256_add_pd(t3406, s4420);
  t3803 = _igen_dd_mm256_add_pd(t3407, s4421);
  t3804 = _igen_dd_mm256_sub_pd(t3406, s4420);
  t3805 = _igen_dd_mm256_sub_pd(t3407, s4421);
  t3806 = _igen_dd_mm256_add_pd(t3272, s4364);
  t3807 = _igen_dd_mm256_add_pd(t3273, s4365);
  t3808 = _igen_dd_mm256_sub_pd(t3272, s4364);
  t3809 = _igen_dd_mm256_sub_pd(t3273, s4365);
  t3810 = _igen_dd_mm256_add_pd(t3318, s4384);
  t3811 = _igen_dd_mm256_add_pd(t3319, s4385);
  t3812 = _igen_dd_mm256_sub_pd(t3318, s4384);
  t3813 = _igen_dd_mm256_sub_pd(t3319, s4385);
  t3814 = _igen_dd_mm256_add_pd(t3364, s4404);
  t3815 = _igen_dd_mm256_add_pd(t3365, s4405);
  t3816 = _igen_dd_mm256_sub_pd(t3364, s4404);
  t3817 = _igen_dd_mm256_sub_pd(t3365, s4405);
  t3818 = _igen_dd_mm256_add_pd(t3410, s4424);
  t3819 = _igen_dd_mm256_add_pd(t3411, s4425);
  t3820 = _igen_dd_mm256_sub_pd(t3410, s4424);
  t3821 = _igen_dd_mm256_sub_pd(t3411, s4425);
  t3822 = _igen_dd_mm256_add_pd(t3276, s4368);
  t3823 = _igen_dd_mm256_sub_pd(t3277, s4369);
  t3824 = _igen_dd_mm256_sub_pd(t3276, s4368);
  t3825 = _igen_dd_mm256_add_pd(t3277, s4369);
  t3826 = _igen_dd_mm256_add_pd(t3322, s4388);
  t3827 = _igen_dd_mm256_add_pd(t3323, s4389);
  t3828 = _igen_dd_mm256_sub_pd(t3322, s4388);
  t3829 = _igen_dd_mm256_sub_pd(t3323, s4389);
  t3830 = _igen_dd_mm256_add_pd(t3368, s4408);
  t3831 = _igen_dd_mm256_add_pd(t3369, s4409);
  t3832 = _igen_dd_mm256_sub_pd(t3368, s4408);
  t3833 = _igen_dd_mm256_sub_pd(t3369, s4409);
  t3834 = _igen_dd_mm256_add_pd(t3414, s4428);
  t3835 = _igen_dd_mm256_add_pd(t3415, s4429);
  t3836 = _igen_dd_mm256_sub_pd(t3414, s4428);
  t3837 = _igen_dd_mm256_sub_pd(t3415, s4429);
  t3838 = _igen_dd_mm256_add_pd(t3280, s4372);
  t3839 = _igen_dd_mm256_add_pd(t3281, s4373);
  t3840 = _igen_dd_mm256_sub_pd(t3280, s4372);
  t3841 = _igen_dd_mm256_sub_pd(t3281, s4373);
  t3842 = _igen_dd_mm256_add_pd(t3326, s4392);
  t3843 = _igen_dd_mm256_add_pd(t3327, s4393);
  t3844 = _igen_dd_mm256_sub_pd(t3326, s4392);
  t3845 = _igen_dd_mm256_sub_pd(t3327, s4393);
  t3846 = _igen_dd_mm256_add_pd(t3372, s4412);
  t3847 = _igen_dd_mm256_add_pd(t3373, s4413);
  t3848 = _igen_dd_mm256_sub_pd(t3372, s4412);
  t3849 = _igen_dd_mm256_sub_pd(t3373, s4413);
  t3850 = _igen_dd_mm256_add_pd(t3418, s4432);
  t3851 = _igen_dd_mm256_add_pd(t3419, s4433);
  t3852 = _igen_dd_mm256_sub_pd(t3418, s4432);
  t3853 = _igen_dd_mm256_sub_pd(t3419, s4433);
  s4434 = _igen_dd_mm256_unpacklo_pd(t3726, t3730);
  s4435 = _igen_dd_mm256_unpackhi_pd(t3726, t3730);
  s4436 = _igen_dd_mm256_unpacklo_pd(t3727, t3731);
  s4437 = _igen_dd_mm256_unpackhi_pd(t3727, t3731);
  s4438 = _igen_dd_mm256_permute2f128_pd(s4434, s4435, (0) | ((2) << 4));
  s4439 = _igen_dd_mm256_permute2f128_pd(s4434, s4435, (1) | ((3) << 4));
  s4440 = _igen_dd_mm256_permute2f128_pd(s4436, s4437, (0) | ((2) << 4));
  s4441 = _igen_dd_mm256_permute2f128_pd(s4436, s4437, (1) | ((3) << 4));
  s4442 = _igen_dd_mm256_unpacklo_pd(t3734, t3738);
  s4443 = _igen_dd_mm256_unpackhi_pd(t3734, t3738);
  s4444 = _igen_dd_mm256_unpacklo_pd(t3735, t3739);
  s4445 = _igen_dd_mm256_unpackhi_pd(t3735, t3739);
  s4446 = _igen_dd_mm256_permute2f128_pd(s4442, s4443, (0) | ((2) << 4));
  s4447 = _igen_dd_mm256_permute2f128_pd(s4442, s4443, (1) | ((3) << 4));
  s4448 = _igen_dd_mm256_permute2f128_pd(s4444, s4445, (0) | ((2) << 4));
  s4449 = _igen_dd_mm256_permute2f128_pd(s4444, s4445, (1) | ((3) << 4));
  s4450 = _igen_dd_mm256_permute2f128_pd(s4438, s4446, (0) | ((2) << 4));
  s4451 = _igen_dd_mm256_permute2f128_pd(s4438, s4446, (1) | ((3) << 4));
  s4452 = _igen_dd_mm256_permute2f128_pd(s4439, s4447, (0) | ((2) << 4));
  s4453 = _igen_dd_mm256_permute2f128_pd(s4439, s4447, (1) | ((3) << 4));
  s4454 = _igen_dd_mm256_permute2f128_pd(s4440, s4448, (0) | ((2) << 4));
  s4455 = _igen_dd_mm256_permute2f128_pd(s4440, s4448, (1) | ((3) << 4));
  s4456 = _igen_dd_mm256_permute2f128_pd(s4441, s4449, (0) | ((2) << 4));
  s4457 = _igen_dd_mm256_permute2f128_pd(s4441, s4449, (1) | ((3) << 4));
  s4458 = _igen_dd_mm256_unpacklo_pd(t3742, t3746);
  s4459 = _igen_dd_mm256_unpackhi_pd(t3742, t3746);
  s4460 = _igen_dd_mm256_unpacklo_pd(t3743, t3747);
  s4461 = _igen_dd_mm256_unpackhi_pd(t3743, t3747);
  s4462 = _igen_dd_mm256_permute2f128_pd(s4458, s4459, (0) | ((2) << 4));
  s4463 = _igen_dd_mm256_permute2f128_pd(s4458, s4459, (1) | ((3) << 4));
  s4464 = _igen_dd_mm256_permute2f128_pd(s4460, s4461, (0) | ((2) << 4));
  s4465 = _igen_dd_mm256_permute2f128_pd(s4460, s4461, (1) | ((3) << 4));
  s4466 = _igen_dd_mm256_unpacklo_pd(t3750, t3754);
  s4467 = _igen_dd_mm256_unpackhi_pd(t3750, t3754);
  s4468 = _igen_dd_mm256_unpacklo_pd(t3751, t3755);
  s4469 = _igen_dd_mm256_unpackhi_pd(t3751, t3755);
  s4470 = _igen_dd_mm256_permute2f128_pd(s4466, s4467, (0) | ((2) << 4));
  s4471 = _igen_dd_mm256_permute2f128_pd(s4466, s4467, (1) | ((3) << 4));
  s4472 = _igen_dd_mm256_permute2f128_pd(s4468, s4469, (0) | ((2) << 4));
  s4473 = _igen_dd_mm256_permute2f128_pd(s4468, s4469, (1) | ((3) << 4));
  s4474 = _igen_dd_mm256_permute2f128_pd(s4462, s4470, (0) | ((2) << 4));
  s4475 = _igen_dd_mm256_permute2f128_pd(s4462, s4470, (1) | ((3) << 4));
  s4476 = _igen_dd_mm256_permute2f128_pd(s4463, s4471, (0) | ((2) << 4));
  s4477 = _igen_dd_mm256_permute2f128_pd(s4463, s4471, (1) | ((3) << 4));
  s4478 = _igen_dd_mm256_permute2f128_pd(s4464, s4472, (0) | ((2) << 4));
  s4479 = _igen_dd_mm256_permute2f128_pd(s4464, s4472, (1) | ((3) << 4));
  s4480 = _igen_dd_mm256_permute2f128_pd(s4465, s4473, (0) | ((2) << 4));
  s4481 = _igen_dd_mm256_permute2f128_pd(s4465, s4473, (1) | ((3) << 4));
  s4482 = _igen_dd_mm256_unpacklo_pd(t3758, t3762);
  s4483 = _igen_dd_mm256_unpackhi_pd(t3758, t3762);
  s4484 = _igen_dd_mm256_unpacklo_pd(t3759, t3763);
  s4485 = _igen_dd_mm256_unpackhi_pd(t3759, t3763);
  s4486 = _igen_dd_mm256_permute2f128_pd(s4482, s4483, (0) | ((2) << 4));
  s4487 = _igen_dd_mm256_permute2f128_pd(s4482, s4483, (1) | ((3) << 4));
  s4488 = _igen_dd_mm256_permute2f128_pd(s4484, s4485, (0) | ((2) << 4));
  s4489 = _igen_dd_mm256_permute2f128_pd(s4484, s4485, (1) | ((3) << 4));
  s4490 = _igen_dd_mm256_unpacklo_pd(t3766, t3770);
  s4491 = _igen_dd_mm256_unpackhi_pd(t3766, t3770);
  s4492 = _igen_dd_mm256_unpacklo_pd(t3767, t3771);
  s4493 = _igen_dd_mm256_unpackhi_pd(t3767, t3771);
  s4494 = _igen_dd_mm256_permute2f128_pd(s4490, s4491, (0) | ((2) << 4));
  s4495 = _igen_dd_mm256_permute2f128_pd(s4490, s4491, (1) | ((3) << 4));
  s4496 = _igen_dd_mm256_permute2f128_pd(s4492, s4493, (0) | ((2) << 4));
  s4497 = _igen_dd_mm256_permute2f128_pd(s4492, s4493, (1) | ((3) << 4));
  s4498 = _igen_dd_mm256_permute2f128_pd(s4486, s4494, (0) | ((2) << 4));
  s4499 = _igen_dd_mm256_permute2f128_pd(s4486, s4494, (1) | ((3) << 4));
  s4500 = _igen_dd_mm256_permute2f128_pd(s4487, s4495, (0) | ((2) << 4));
  s4501 = _igen_dd_mm256_permute2f128_pd(s4487, s4495, (1) | ((3) << 4));
  s4502 = _igen_dd_mm256_permute2f128_pd(s4488, s4496, (0) | ((2) << 4));
  s4503 = _igen_dd_mm256_permute2f128_pd(s4488, s4496, (1) | ((3) << 4));
  s4504 = _igen_dd_mm256_permute2f128_pd(s4489, s4497, (0) | ((2) << 4));
  s4505 = _igen_dd_mm256_permute2f128_pd(s4489, s4497, (1) | ((3) << 4));
  s4506 = _igen_dd_mm256_unpacklo_pd(t3774, t3778);
  s4507 = _igen_dd_mm256_unpackhi_pd(t3774, t3778);
  s4508 = _igen_dd_mm256_unpacklo_pd(t3775, t3779);
  s4509 = _igen_dd_mm256_unpackhi_pd(t3775, t3779);
  s4510 = _igen_dd_mm256_permute2f128_pd(s4506, s4507, (0) | ((2) << 4));
  s4511 = _igen_dd_mm256_permute2f128_pd(s4506, s4507, (1) | ((3) << 4));
  s4512 = _igen_dd_mm256_permute2f128_pd(s4508, s4509, (0) | ((2) << 4));
  s4513 = _igen_dd_mm256_permute2f128_pd(s4508, s4509, (1) | ((3) << 4));
  s4514 = _igen_dd_mm256_unpacklo_pd(t3782, t3786);
  s4515 = _igen_dd_mm256_unpackhi_pd(t3782, t3786);
  s4516 = _igen_dd_mm256_unpacklo_pd(t3783, t3787);
  s4517 = _igen_dd_mm256_unpackhi_pd(t3783, t3787);
  s4518 = _igen_dd_mm256_permute2f128_pd(s4514, s4515, (0) | ((2) << 4));
  s4519 = _igen_dd_mm256_permute2f128_pd(s4514, s4515, (1) | ((3) << 4));
  s4520 = _igen_dd_mm256_permute2f128_pd(s4516, s4517, (0) | ((2) << 4));
  s4521 = _igen_dd_mm256_permute2f128_pd(s4516, s4517, (1) | ((3) << 4));
  s4522 = _igen_dd_mm256_permute2f128_pd(s4510, s4518, (0) | ((2) << 4));
  s4523 = _igen_dd_mm256_permute2f128_pd(s4510, s4518, (1) | ((3) << 4));
  s4524 = _igen_dd_mm256_permute2f128_pd(s4511, s4519, (0) | ((2) << 4));
  s4525 = _igen_dd_mm256_permute2f128_pd(s4511, s4519, (1) | ((3) << 4));
  s4526 = _igen_dd_mm256_permute2f128_pd(s4512, s4520, (0) | ((2) << 4));
  s4527 = _igen_dd_mm256_permute2f128_pd(s4512, s4520, (1) | ((3) << 4));
  s4528 = _igen_dd_mm256_permute2f128_pd(s4513, s4521, (0) | ((2) << 4));
  s4529 = _igen_dd_mm256_permute2f128_pd(s4513, s4521, (1) | ((3) << 4));
  s4530 = _igen_dd_mm256_unpacklo_pd(t3790, t3794);
  s4531 = _igen_dd_mm256_unpackhi_pd(t3790, t3794);
  s4532 = _igen_dd_mm256_unpacklo_pd(t3791, t3795);
  s4533 = _igen_dd_mm256_unpackhi_pd(t3791, t3795);
  s4534 = _igen_dd_mm256_permute2f128_pd(s4530, s4531, (0) | ((2) << 4));
  s4535 = _igen_dd_mm256_permute2f128_pd(s4530, s4531, (1) | ((3) << 4));
  s4536 = _igen_dd_mm256_permute2f128_pd(s4532, s4533, (0) | ((2) << 4));
  s4537 = _igen_dd_mm256_permute2f128_pd(s4532, s4533, (1) | ((3) << 4));
  s4538 = _igen_dd_mm256_unpacklo_pd(t3798, t3802);
  s4539 = _igen_dd_mm256_unpackhi_pd(t3798, t3802);
  s4540 = _igen_dd_mm256_unpacklo_pd(t3799, t3803);
  s4541 = _igen_dd_mm256_unpackhi_pd(t3799, t3803);
  s4542 = _igen_dd_mm256_permute2f128_pd(s4538, s4539, (0) | ((2) << 4));
  s4543 = _igen_dd_mm256_permute2f128_pd(s4538, s4539, (1) | ((3) << 4));
  s4544 = _igen_dd_mm256_permute2f128_pd(s4540, s4541, (0) | ((2) << 4));
  s4545 = _igen_dd_mm256_permute2f128_pd(s4540, s4541, (1) | ((3) << 4));
  s4546 = _igen_dd_mm256_permute2f128_pd(s4534, s4542, (0) | ((2) << 4));
  s4547 = _igen_dd_mm256_permute2f128_pd(s4534, s4542, (1) | ((3) << 4));
  s4548 = _igen_dd_mm256_permute2f128_pd(s4535, s4543, (0) | ((2) << 4));
  s4549 = _igen_dd_mm256_permute2f128_pd(s4535, s4543, (1) | ((3) << 4));
  s4550 = _igen_dd_mm256_permute2f128_pd(s4536, s4544, (0) | ((2) << 4));
  s4551 = _igen_dd_mm256_permute2f128_pd(s4536, s4544, (1) | ((3) << 4));
  s4552 = _igen_dd_mm256_permute2f128_pd(s4537, s4545, (0) | ((2) << 4));
  s4553 = _igen_dd_mm256_permute2f128_pd(s4537, s4545, (1) | ((3) << 4));
  s4554 = _igen_dd_mm256_unpacklo_pd(t3806, t3810);
  s4555 = _igen_dd_mm256_unpackhi_pd(t3806, t3810);
  s4556 = _igen_dd_mm256_unpacklo_pd(t3807, t3811);
  s4557 = _igen_dd_mm256_unpackhi_pd(t3807, t3811);
  s4558 = _igen_dd_mm256_permute2f128_pd(s4554, s4555, (0) | ((2) << 4));
  s4559 = _igen_dd_mm256_permute2f128_pd(s4554, s4555, (1) | ((3) << 4));
  s4560 = _igen_dd_mm256_permute2f128_pd(s4556, s4557, (0) | ((2) << 4));
  s4561 = _igen_dd_mm256_permute2f128_pd(s4556, s4557, (1) | ((3) << 4));
  s4562 = _igen_dd_mm256_unpacklo_pd(t3814, t3818);
  s4563 = _igen_dd_mm256_unpackhi_pd(t3814, t3818);
  s4564 = _igen_dd_mm256_unpacklo_pd(t3815, t3819);
  s4565 = _igen_dd_mm256_unpackhi_pd(t3815, t3819);
  s4566 = _igen_dd_mm256_permute2f128_pd(s4562, s4563, (0) | ((2) << 4));
  s4567 = _igen_dd_mm256_permute2f128_pd(s4562, s4563, (1) | ((3) << 4));
  s4568 = _igen_dd_mm256_permute2f128_pd(s4564, s4565, (0) | ((2) << 4));
  s4569 = _igen_dd_mm256_permute2f128_pd(s4564, s4565, (1) | ((3) << 4));
  s4570 = _igen_dd_mm256_permute2f128_pd(s4558, s4566, (0) | ((2) << 4));
  s4571 = _igen_dd_mm256_permute2f128_pd(s4558, s4566, (1) | ((3) << 4));
  s4572 = _igen_dd_mm256_permute2f128_pd(s4559, s4567, (0) | ((2) << 4));
  s4573 = _igen_dd_mm256_permute2f128_pd(s4559, s4567, (1) | ((3) << 4));
  s4574 = _igen_dd_mm256_permute2f128_pd(s4560, s4568, (0) | ((2) << 4));
  s4575 = _igen_dd_mm256_permute2f128_pd(s4560, s4568, (1) | ((3) << 4));
  s4576 = _igen_dd_mm256_permute2f128_pd(s4561, s4569, (0) | ((2) << 4));
  s4577 = _igen_dd_mm256_permute2f128_pd(s4561, s4569, (1) | ((3) << 4));
  s4578 = _igen_dd_mm256_unpacklo_pd(t3822, t3826);
  s4579 = _igen_dd_mm256_unpackhi_pd(t3822, t3826);
  s4580 = _igen_dd_mm256_unpacklo_pd(t3823, t3827);
  s4581 = _igen_dd_mm256_unpackhi_pd(t3823, t3827);
  s4582 = _igen_dd_mm256_permute2f128_pd(s4578, s4579, (0) | ((2) << 4));
  s4583 = _igen_dd_mm256_permute2f128_pd(s4578, s4579, (1) | ((3) << 4));
  s4584 = _igen_dd_mm256_permute2f128_pd(s4580, s4581, (0) | ((2) << 4));
  s4585 = _igen_dd_mm256_permute2f128_pd(s4580, s4581, (1) | ((3) << 4));
  s4586 = _igen_dd_mm256_unpacklo_pd(t3830, t3834);
  s4587 = _igen_dd_mm256_unpackhi_pd(t3830, t3834);
  s4588 = _igen_dd_mm256_unpacklo_pd(t3831, t3835);
  s4589 = _igen_dd_mm256_unpackhi_pd(t3831, t3835);
  s4590 = _igen_dd_mm256_permute2f128_pd(s4586, s4587, (0) | ((2) << 4));
  s4591 = _igen_dd_mm256_permute2f128_pd(s4586, s4587, (1) | ((3) << 4));
  s4592 = _igen_dd_mm256_permute2f128_pd(s4588, s4589, (0) | ((2) << 4));
  s4593 = _igen_dd_mm256_permute2f128_pd(s4588, s4589, (1) | ((3) << 4));
  s4594 = _igen_dd_mm256_permute2f128_pd(s4582, s4590, (0) | ((2) << 4));
  s4595 = _igen_dd_mm256_permute2f128_pd(s4582, s4590, (1) | ((3) << 4));
  s4596 = _igen_dd_mm256_permute2f128_pd(s4583, s4591, (0) | ((2) << 4));
  s4597 = _igen_dd_mm256_permute2f128_pd(s4583, s4591, (1) | ((3) << 4));
  s4598 = _igen_dd_mm256_permute2f128_pd(s4584, s4592, (0) | ((2) << 4));
  s4599 = _igen_dd_mm256_permute2f128_pd(s4584, s4592, (1) | ((3) << 4));
  s4600 = _igen_dd_mm256_permute2f128_pd(s4585, s4593, (0) | ((2) << 4));
  s4601 = _igen_dd_mm256_permute2f128_pd(s4585, s4593, (1) | ((3) << 4));
  s4602 = _igen_dd_mm256_unpacklo_pd(t3838, t3842);
  s4603 = _igen_dd_mm256_unpackhi_pd(t3838, t3842);
  s4604 = _igen_dd_mm256_unpacklo_pd(t3839, t3843);
  s4605 = _igen_dd_mm256_unpackhi_pd(t3839, t3843);
  s4606 = _igen_dd_mm256_permute2f128_pd(s4602, s4603, (0) | ((2) << 4));
  s4607 = _igen_dd_mm256_permute2f128_pd(s4602, s4603, (1) | ((3) << 4));
  s4608 = _igen_dd_mm256_permute2f128_pd(s4604, s4605, (0) | ((2) << 4));
  s4609 = _igen_dd_mm256_permute2f128_pd(s4604, s4605, (1) | ((3) << 4));
  s4610 = _igen_dd_mm256_unpacklo_pd(t3846, t3850);
  s4611 = _igen_dd_mm256_unpackhi_pd(t3846, t3850);
  s4612 = _igen_dd_mm256_unpacklo_pd(t3847, t3851);
  s4613 = _igen_dd_mm256_unpackhi_pd(t3847, t3851);
  s4614 = _igen_dd_mm256_permute2f128_pd(s4610, s4611, (0) | ((2) << 4));
  s4615 = _igen_dd_mm256_permute2f128_pd(s4610, s4611, (1) | ((3) << 4));
  s4616 = _igen_dd_mm256_permute2f128_pd(s4612, s4613, (0) | ((2) << 4));
  s4617 = _igen_dd_mm256_permute2f128_pd(s4612, s4613, (1) | ((3) << 4));
  s4618 = _igen_dd_mm256_permute2f128_pd(s4606, s4614, (0) | ((2) << 4));
  s4619 = _igen_dd_mm256_permute2f128_pd(s4606, s4614, (1) | ((3) << 4));
  s4620 = _igen_dd_mm256_permute2f128_pd(s4607, s4615, (0) | ((2) << 4));
  s4621 = _igen_dd_mm256_permute2f128_pd(s4607, s4615, (1) | ((3) << 4));
  s4622 = _igen_dd_mm256_permute2f128_pd(s4608, s4616, (0) | ((2) << 4));
  s4623 = _igen_dd_mm256_permute2f128_pd(s4608, s4616, (1) | ((3) << 4));
  s4624 = _igen_dd_mm256_permute2f128_pd(s4609, s4617, (0) | ((2) << 4));
  s4625 = _igen_dd_mm256_permute2f128_pd(s4609, s4617, (1) | ((3) << 4));
  s4626 = _igen_dd_mm256_unpacklo_pd(t3728, t3732);
  s4627 = _igen_dd_mm256_unpackhi_pd(t3728, t3732);
  s4628 = _igen_dd_mm256_unpacklo_pd(t3729, t3733);
  s4629 = _igen_dd_mm256_unpackhi_pd(t3729, t3733);
  s4630 = _igen_dd_mm256_permute2f128_pd(s4626, s4627, (0) | ((2) << 4));
  s4631 = _igen_dd_mm256_permute2f128_pd(s4626, s4627, (1) | ((3) << 4));
  s4632 = _igen_dd_mm256_permute2f128_pd(s4628, s4629, (0) | ((2) << 4));
  s4633 = _igen_dd_mm256_permute2f128_pd(s4628, s4629, (1) | ((3) << 4));
  s4634 = _igen_dd_mm256_unpacklo_pd(t3736, t3740);
  s4635 = _igen_dd_mm256_unpackhi_pd(t3736, t3740);
  s4636 = _igen_dd_mm256_unpacklo_pd(t3737, t3741);
  s4637 = _igen_dd_mm256_unpackhi_pd(t3737, t3741);
  s4638 = _igen_dd_mm256_permute2f128_pd(s4634, s4635, (0) | ((2) << 4));
  s4639 = _igen_dd_mm256_permute2f128_pd(s4634, s4635, (1) | ((3) << 4));
  s4640 = _igen_dd_mm256_permute2f128_pd(s4636, s4637, (0) | ((2) << 4));
  s4641 = _igen_dd_mm256_permute2f128_pd(s4636, s4637, (1) | ((3) << 4));
  s4642 = _igen_dd_mm256_permute2f128_pd(s4630, s4638, (0) | ((2) << 4));
  s4643 = _igen_dd_mm256_permute2f128_pd(s4630, s4638, (1) | ((3) << 4));
  s4644 = _igen_dd_mm256_permute2f128_pd(s4631, s4639, (0) | ((2) << 4));
  s4645 = _igen_dd_mm256_permute2f128_pd(s4631, s4639, (1) | ((3) << 4));
  s4646 = _igen_dd_mm256_permute2f128_pd(s4632, s4640, (0) | ((2) << 4));
  s4647 = _igen_dd_mm256_permute2f128_pd(s4632, s4640, (1) | ((3) << 4));
  s4648 = _igen_dd_mm256_permute2f128_pd(s4633, s4641, (0) | ((2) << 4));
  s4649 = _igen_dd_mm256_permute2f128_pd(s4633, s4641, (1) | ((3) << 4));
  s4650 = _igen_dd_mm256_unpacklo_pd(t3744, t3748);
  s4651 = _igen_dd_mm256_unpackhi_pd(t3744, t3748);
  s4652 = _igen_dd_mm256_unpacklo_pd(t3745, t3749);
  s4653 = _igen_dd_mm256_unpackhi_pd(t3745, t3749);
  s4654 = _igen_dd_mm256_permute2f128_pd(s4650, s4651, (0) | ((2) << 4));
  s4655 = _igen_dd_mm256_permute2f128_pd(s4650, s4651, (1) | ((3) << 4));
  s4656 = _igen_dd_mm256_permute2f128_pd(s4652, s4653, (0) | ((2) << 4));
  s4657 = _igen_dd_mm256_permute2f128_pd(s4652, s4653, (1) | ((3) << 4));
  s4658 = _igen_dd_mm256_unpacklo_pd(t3752, t3756);
  s4659 = _igen_dd_mm256_unpackhi_pd(t3752, t3756);
  s4660 = _igen_dd_mm256_unpacklo_pd(t3753, t3757);
  s4661 = _igen_dd_mm256_unpackhi_pd(t3753, t3757);
  s4662 = _igen_dd_mm256_permute2f128_pd(s4658, s4659, (0) | ((2) << 4));
  s4663 = _igen_dd_mm256_permute2f128_pd(s4658, s4659, (1) | ((3) << 4));
  s4664 = _igen_dd_mm256_permute2f128_pd(s4660, s4661, (0) | ((2) << 4));
  s4665 = _igen_dd_mm256_permute2f128_pd(s4660, s4661, (1) | ((3) << 4));
  s4666 = _igen_dd_mm256_permute2f128_pd(s4654, s4662, (0) | ((2) << 4));
  s4667 = _igen_dd_mm256_permute2f128_pd(s4654, s4662, (1) | ((3) << 4));
  s4668 = _igen_dd_mm256_permute2f128_pd(s4655, s4663, (0) | ((2) << 4));
  s4669 = _igen_dd_mm256_permute2f128_pd(s4655, s4663, (1) | ((3) << 4));
  s4670 = _igen_dd_mm256_permute2f128_pd(s4656, s4664, (0) | ((2) << 4));
  s4671 = _igen_dd_mm256_permute2f128_pd(s4656, s4664, (1) | ((3) << 4));
  s4672 = _igen_dd_mm256_permute2f128_pd(s4657, s4665, (0) | ((2) << 4));
  s4673 = _igen_dd_mm256_permute2f128_pd(s4657, s4665, (1) | ((3) << 4));
  s4674 = _igen_dd_mm256_unpacklo_pd(t3760, t3764);
  s4675 = _igen_dd_mm256_unpackhi_pd(t3760, t3764);
  s4676 = _igen_dd_mm256_unpacklo_pd(t3761, t3765);
  s4677 = _igen_dd_mm256_unpackhi_pd(t3761, t3765);
  s4678 = _igen_dd_mm256_permute2f128_pd(s4674, s4675, (0) | ((2) << 4));
  s4679 = _igen_dd_mm256_permute2f128_pd(s4674, s4675, (1) | ((3) << 4));
  s4680 = _igen_dd_mm256_permute2f128_pd(s4676, s4677, (0) | ((2) << 4));
  s4681 = _igen_dd_mm256_permute2f128_pd(s4676, s4677, (1) | ((3) << 4));
  s4682 = _igen_dd_mm256_unpacklo_pd(t3768, t3772);
  s4683 = _igen_dd_mm256_unpackhi_pd(t3768, t3772);
  s4684 = _igen_dd_mm256_unpacklo_pd(t3769, t3773);
  s4685 = _igen_dd_mm256_unpackhi_pd(t3769, t3773);
  s4686 = _igen_dd_mm256_permute2f128_pd(s4682, s4683, (0) | ((2) << 4));
  s4687 = _igen_dd_mm256_permute2f128_pd(s4682, s4683, (1) | ((3) << 4));
  s4688 = _igen_dd_mm256_permute2f128_pd(s4684, s4685, (0) | ((2) << 4));
  s4689 = _igen_dd_mm256_permute2f128_pd(s4684, s4685, (1) | ((3) << 4));
  s4690 = _igen_dd_mm256_permute2f128_pd(s4678, s4686, (0) | ((2) << 4));
  s4691 = _igen_dd_mm256_permute2f128_pd(s4678, s4686, (1) | ((3) << 4));
  s4692 = _igen_dd_mm256_permute2f128_pd(s4679, s4687, (0) | ((2) << 4));
  s4693 = _igen_dd_mm256_permute2f128_pd(s4679, s4687, (1) | ((3) << 4));
  s4694 = _igen_dd_mm256_permute2f128_pd(s4680, s4688, (0) | ((2) << 4));
  s4695 = _igen_dd_mm256_permute2f128_pd(s4680, s4688, (1) | ((3) << 4));
  s4696 = _igen_dd_mm256_permute2f128_pd(s4681, s4689, (0) | ((2) << 4));
  s4697 = _igen_dd_mm256_permute2f128_pd(s4681, s4689, (1) | ((3) << 4));
  s4698 = _igen_dd_mm256_unpacklo_pd(t3776, t3780);
  s4699 = _igen_dd_mm256_unpackhi_pd(t3776, t3780);
  s4700 = _igen_dd_mm256_unpacklo_pd(t3777, t3781);
  s4701 = _igen_dd_mm256_unpackhi_pd(t3777, t3781);
  s4702 = _igen_dd_mm256_permute2f128_pd(s4698, s4699, (0) | ((2) << 4));
  s4703 = _igen_dd_mm256_permute2f128_pd(s4698, s4699, (1) | ((3) << 4));
  s4704 = _igen_dd_mm256_permute2f128_pd(s4700, s4701, (0) | ((2) << 4));
  s4705 = _igen_dd_mm256_permute2f128_pd(s4700, s4701, (1) | ((3) << 4));
  s4706 = _igen_dd_mm256_unpacklo_pd(t3784, t3788);
  s4707 = _igen_dd_mm256_unpackhi_pd(t3784, t3788);
  s4708 = _igen_dd_mm256_unpacklo_pd(t3785, t3789);
  s4709 = _igen_dd_mm256_unpackhi_pd(t3785, t3789);
  s4710 = _igen_dd_mm256_permute2f128_pd(s4706, s4707, (0) | ((2) << 4));
  s4711 = _igen_dd_mm256_permute2f128_pd(s4706, s4707, (1) | ((3) << 4));
  s4712 = _igen_dd_mm256_permute2f128_pd(s4708, s4709, (0) | ((2) << 4));
  s4713 = _igen_dd_mm256_permute2f128_pd(s4708, s4709, (1) | ((3) << 4));
  s4714 = _igen_dd_mm256_permute2f128_pd(s4702, s4710, (0) | ((2) << 4));
  s4715 = _igen_dd_mm256_permute2f128_pd(s4702, s4710, (1) | ((3) << 4));
  s4716 = _igen_dd_mm256_permute2f128_pd(s4703, s4711, (0) | ((2) << 4));
  s4717 = _igen_dd_mm256_permute2f128_pd(s4703, s4711, (1) | ((3) << 4));
  s4718 = _igen_dd_mm256_permute2f128_pd(s4704, s4712, (0) | ((2) << 4));
  s4719 = _igen_dd_mm256_permute2f128_pd(s4704, s4712, (1) | ((3) << 4));
  s4720 = _igen_dd_mm256_permute2f128_pd(s4705, s4713, (0) | ((2) << 4));
  s4721 = _igen_dd_mm256_permute2f128_pd(s4705, s4713, (1) | ((3) << 4));
  s4722 = _igen_dd_mm256_unpacklo_pd(t3792, t3796);
  s4723 = _igen_dd_mm256_unpackhi_pd(t3792, t3796);
  s4724 = _igen_dd_mm256_unpacklo_pd(t3793, t3797);
  s4725 = _igen_dd_mm256_unpackhi_pd(t3793, t3797);
  s4726 = _igen_dd_mm256_permute2f128_pd(s4722, s4723, (0) | ((2) << 4));
  s4727 = _igen_dd_mm256_permute2f128_pd(s4722, s4723, (1) | ((3) << 4));
  s4728 = _igen_dd_mm256_permute2f128_pd(s4724, s4725, (0) | ((2) << 4));
  s4729 = _igen_dd_mm256_permute2f128_pd(s4724, s4725, (1) | ((3) << 4));
  s4730 = _igen_dd_mm256_unpacklo_pd(t3800, t3804);
  s4731 = _igen_dd_mm256_unpackhi_pd(t3800, t3804);
  s4732 = _igen_dd_mm256_unpacklo_pd(t3801, t3805);
  s4733 = _igen_dd_mm256_unpackhi_pd(t3801, t3805);
  s4734 = _igen_dd_mm256_permute2f128_pd(s4730, s4731, (0) | ((2) << 4));
  s4735 = _igen_dd_mm256_permute2f128_pd(s4730, s4731, (1) | ((3) << 4));
  s4736 = _igen_dd_mm256_permute2f128_pd(s4732, s4733, (0) | ((2) << 4));
  s4737 = _igen_dd_mm256_permute2f128_pd(s4732, s4733, (1) | ((3) << 4));
  s4738 = _igen_dd_mm256_permute2f128_pd(s4726, s4734, (0) | ((2) << 4));
  s4739 = _igen_dd_mm256_permute2f128_pd(s4726, s4734, (1) | ((3) << 4));
  s4740 = _igen_dd_mm256_permute2f128_pd(s4727, s4735, (0) | ((2) << 4));
  s4741 = _igen_dd_mm256_permute2f128_pd(s4727, s4735, (1) | ((3) << 4));
  s4742 = _igen_dd_mm256_permute2f128_pd(s4728, s4736, (0) | ((2) << 4));
  s4743 = _igen_dd_mm256_permute2f128_pd(s4728, s4736, (1) | ((3) << 4));
  s4744 = _igen_dd_mm256_permute2f128_pd(s4729, s4737, (0) | ((2) << 4));
  s4745 = _igen_dd_mm256_permute2f128_pd(s4729, s4737, (1) | ((3) << 4));
  s4746 = _igen_dd_mm256_unpacklo_pd(t3808, t3812);
  s4747 = _igen_dd_mm256_unpackhi_pd(t3808, t3812);
  s4748 = _igen_dd_mm256_unpacklo_pd(t3809, t3813);
  s4749 = _igen_dd_mm256_unpackhi_pd(t3809, t3813);
  s4750 = _igen_dd_mm256_permute2f128_pd(s4746, s4747, (0) | ((2) << 4));
  s4751 = _igen_dd_mm256_permute2f128_pd(s4746, s4747, (1) | ((3) << 4));
  s4752 = _igen_dd_mm256_permute2f128_pd(s4748, s4749, (0) | ((2) << 4));
  s4753 = _igen_dd_mm256_permute2f128_pd(s4748, s4749, (1) | ((3) << 4));
  s4754 = _igen_dd_mm256_unpacklo_pd(t3816, t3820);
  s4755 = _igen_dd_mm256_unpackhi_pd(t3816, t3820);
  s4756 = _igen_dd_mm256_unpacklo_pd(t3817, t3821);
  s4757 = _igen_dd_mm256_unpackhi_pd(t3817, t3821);
  s4758 = _igen_dd_mm256_permute2f128_pd(s4754, s4755, (0) | ((2) << 4));
  s4759 = _igen_dd_mm256_permute2f128_pd(s4754, s4755, (1) | ((3) << 4));
  s4760 = _igen_dd_mm256_permute2f128_pd(s4756, s4757, (0) | ((2) << 4));
  s4761 = _igen_dd_mm256_permute2f128_pd(s4756, s4757, (1) | ((3) << 4));
  s4762 = _igen_dd_mm256_permute2f128_pd(s4750, s4758, (0) | ((2) << 4));
  s4763 = _igen_dd_mm256_permute2f128_pd(s4750, s4758, (1) | ((3) << 4));
  s4764 = _igen_dd_mm256_permute2f128_pd(s4751, s4759, (0) | ((2) << 4));
  s4765 = _igen_dd_mm256_permute2f128_pd(s4751, s4759, (1) | ((3) << 4));
  s4766 = _igen_dd_mm256_permute2f128_pd(s4752, s4760, (0) | ((2) << 4));
  s4767 = _igen_dd_mm256_permute2f128_pd(s4752, s4760, (1) | ((3) << 4));
  s4768 = _igen_dd_mm256_permute2f128_pd(s4753, s4761, (0) | ((2) << 4));
  s4769 = _igen_dd_mm256_permute2f128_pd(s4753, s4761, (1) | ((3) << 4));
  s4770 = _igen_dd_mm256_unpacklo_pd(t3824, t3828);
  s4771 = _igen_dd_mm256_unpackhi_pd(t3824, t3828);
  s4772 = _igen_dd_mm256_unpacklo_pd(t3825, t3829);
  s4773 = _igen_dd_mm256_unpackhi_pd(t3825, t3829);
  s4774 = _igen_dd_mm256_permute2f128_pd(s4770, s4771, (0) | ((2) << 4));
  s4775 = _igen_dd_mm256_permute2f128_pd(s4770, s4771, (1) | ((3) << 4));
  s4776 = _igen_dd_mm256_permute2f128_pd(s4772, s4773, (0) | ((2) << 4));
  s4777 = _igen_dd_mm256_permute2f128_pd(s4772, s4773, (1) | ((3) << 4));
  s4778 = _igen_dd_mm256_unpacklo_pd(t3832, t3836);
  s4779 = _igen_dd_mm256_unpackhi_pd(t3832, t3836);
  s4780 = _igen_dd_mm256_unpacklo_pd(t3833, t3837);
  s4781 = _igen_dd_mm256_unpackhi_pd(t3833, t3837);
  s4782 = _igen_dd_mm256_permute2f128_pd(s4778, s4779, (0) | ((2) << 4));
  s4783 = _igen_dd_mm256_permute2f128_pd(s4778, s4779, (1) | ((3) << 4));
  s4784 = _igen_dd_mm256_permute2f128_pd(s4780, s4781, (0) | ((2) << 4));
  s4785 = _igen_dd_mm256_permute2f128_pd(s4780, s4781, (1) | ((3) << 4));
  s4786 = _igen_dd_mm256_permute2f128_pd(s4774, s4782, (0) | ((2) << 4));
  s4787 = _igen_dd_mm256_permute2f128_pd(s4774, s4782, (1) | ((3) << 4));
  s4788 = _igen_dd_mm256_permute2f128_pd(s4775, s4783, (0) | ((2) << 4));
  s4789 = _igen_dd_mm256_permute2f128_pd(s4775, s4783, (1) | ((3) << 4));
  s4790 = _igen_dd_mm256_permute2f128_pd(s4776, s4784, (0) | ((2) << 4));
  s4791 = _igen_dd_mm256_permute2f128_pd(s4776, s4784, (1) | ((3) << 4));
  s4792 = _igen_dd_mm256_permute2f128_pd(s4777, s4785, (0) | ((2) << 4));
  s4793 = _igen_dd_mm256_permute2f128_pd(s4777, s4785, (1) | ((3) << 4));
  s4794 = _igen_dd_mm256_unpacklo_pd(t3840, t3844);
  s4795 = _igen_dd_mm256_unpackhi_pd(t3840, t3844);
  s4796 = _igen_dd_mm256_unpacklo_pd(t3841, t3845);
  s4797 = _igen_dd_mm256_unpackhi_pd(t3841, t3845);
  s4798 = _igen_dd_mm256_permute2f128_pd(s4794, s4795, (0) | ((2) << 4));
  s4799 = _igen_dd_mm256_permute2f128_pd(s4794, s4795, (1) | ((3) << 4));
  s4800 = _igen_dd_mm256_permute2f128_pd(s4796, s4797, (0) | ((2) << 4));
  s4801 = _igen_dd_mm256_permute2f128_pd(s4796, s4797, (1) | ((3) << 4));
  s4802 = _igen_dd_mm256_unpacklo_pd(t3848, t3852);
  s4803 = _igen_dd_mm256_unpackhi_pd(t3848, t3852);
  s4804 = _igen_dd_mm256_unpacklo_pd(t3849, t3853);
  s4805 = _igen_dd_mm256_unpackhi_pd(t3849, t3853);
  s4806 = _igen_dd_mm256_permute2f128_pd(s4802, s4803, (0) | ((2) << 4));
  s4807 = _igen_dd_mm256_permute2f128_pd(s4802, s4803, (1) | ((3) << 4));
  s4808 = _igen_dd_mm256_permute2f128_pd(s4804, s4805, (0) | ((2) << 4));
  s4809 = _igen_dd_mm256_permute2f128_pd(s4804, s4805, (1) | ((3) << 4));
  s4810 = _igen_dd_mm256_permute2f128_pd(s4798, s4806, (0) | ((2) << 4));
  s4811 = _igen_dd_mm256_permute2f128_pd(s4798, s4806, (1) | ((3) << 4));
  s4812 = _igen_dd_mm256_permute2f128_pd(s4799, s4807, (0) | ((2) << 4));
  s4813 = _igen_dd_mm256_permute2f128_pd(s4799, s4807, (1) | ((3) << 4));
  s4814 = _igen_dd_mm256_permute2f128_pd(s4800, s4808, (0) | ((2) << 4));
  s4815 = _igen_dd_mm256_permute2f128_pd(s4800, s4808, (1) | ((3) << 4));
  s4816 = _igen_dd_mm256_permute2f128_pd(s4801, s4809, (0) | ((2) << 4));
  s4817 = _igen_dd_mm256_permute2f128_pd(s4801, s4809, (1) | ((3) << 4));
  dd_I _t950 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t951 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t952 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t953 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t954 = _igen_dd_mm256_set_pd(_t950, _t951, _t952, _t953);
  dd_I _t955 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t956 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t957 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t958 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t959 = _igen_dd_mm256_set_pd(_t955, _t956, _t957, _t958);
  ddi_4 _t960 = _igen_dd_mm256_mul_pd(_t954, s4452);
  ddi_4 _t961 = _igen_dd_mm256_mul_pd(_t959, s4456);
  s4818 = _igen_dd_mm256_sub_pd(_t960, _t961);
  dd_I _t962 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t963 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t964 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t965 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t966 = _igen_dd_mm256_set_pd(_t962, _t963, _t964, _t965);
  dd_I _t967 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t968 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t969 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t970 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t971 = _igen_dd_mm256_set_pd(_t967, _t968, _t969, _t970);
  ddi_4 _t972 = _igen_dd_mm256_mul_pd(_t966, s4452);
  ddi_4 _t973 = _igen_dd_mm256_mul_pd(_t971, s4456);
  s4819 = _igen_dd_mm256_add_pd(_t972, _t973);
  t3854 = _igen_dd_mm256_add_pd(s4450, s4818);
  t3855 = _igen_dd_mm256_add_pd(s4454, s4819);
  t3856 = _igen_dd_mm256_sub_pd(s4450, s4818);
  t3857 = _igen_dd_mm256_sub_pd(s4454, s4819);
  dd_I _t974 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                          0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t975 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t976 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                          0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t977 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t978 = _igen_dd_mm256_set_pd(_t974, _t975, _t976, _t977);
  dd_I _t979 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                          0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t980 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t981 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                          0.024541228522912288, -1.236030195850617e-19);
  dd_I _t982 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t983 = _igen_dd_mm256_set_pd(_t979, _t980, _t981, _t982);
  ddi_4 _t984 = _igen_dd_mm256_mul_pd(_t978, s4451);
  ddi_4 _t985 = _igen_dd_mm256_mul_pd(_t983, s4455);
  s4820 = _igen_dd_mm256_sub_pd(_t984, _t985);
  dd_I _t986 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                          0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t987 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t988 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                          0.024541228522912288, -1.236030195850617e-19);
  dd_I _t989 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t990 = _igen_dd_mm256_set_pd(_t986, _t987, _t988, _t989);
  dd_I _t991 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                          0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t992 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t993 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                          0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t994 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t995 = _igen_dd_mm256_set_pd(_t991, _t992, _t993, _t994);
  ddi_4 _t996 = _igen_dd_mm256_mul_pd(_t990, s4451);
  ddi_4 _t997 = _igen_dd_mm256_mul_pd(_t995, s4455);
  s4821 = _igen_dd_mm256_add_pd(_t996, _t997);
  dd_I _t998 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                          0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t999 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1000 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                           0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t1001 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t1002 = _igen_dd_mm256_set_pd(_t998, _t999, _t1000, _t1001);
  dd_I _t1003 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t1004 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1005 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                           0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t1006 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t1007 = _igen_dd_mm256_set_pd(_t1003, _t1004, _t1005, _t1006);
  ddi_4 _t1008 = _igen_dd_mm256_mul_pd(_t1002, s4453);
  ddi_4 _t1009 = _igen_dd_mm256_mul_pd(_t1007, s4457);
  s4822 = _igen_dd_mm256_sub_pd(_t1008, _t1009);
  dd_I _t1010 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t1011 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1012 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                           0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t1013 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t1014 = _igen_dd_mm256_set_pd(_t1010, _t1011, _t1012, _t1013);
  dd_I _t1015 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                           0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t1016 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1017 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                           0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t1018 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t1019 = _igen_dd_mm256_set_pd(_t1015, _t1016, _t1017, _t1018);
  ddi_4 _t1020 = _igen_dd_mm256_mul_pd(_t1014, s4453);
  ddi_4 _t1021 = _igen_dd_mm256_mul_pd(_t1019, s4457);
  s4823 = _igen_dd_mm256_add_pd(_t1020, _t1021);
  t3858 = _igen_dd_mm256_add_pd(s4820, s4822);
  t3859 = _igen_dd_mm256_add_pd(s4821, s4823);
  t3860 = _igen_dd_mm256_sub_pd(s4820, s4822);
  t3861 = _igen_dd_mm256_sub_pd(s4821, s4823);
  t3862 = _igen_dd_mm256_add_pd(t3854, t3858);
  t3863 = _igen_dd_mm256_add_pd(t3855, t3859);
  t3864 = _igen_dd_mm256_sub_pd(t3854, t3858);
  t3865 = _igen_dd_mm256_sub_pd(t3855, t3859);
  s4824 = _igen_dd_mm256_unpacklo_pd(t3862, t3863);
  s4825 = _igen_dd_mm256_unpackhi_pd(t3862, t3863);
  a1309 = ((ddi_4 *)Y);
  s4826 = _igen_dd_mm256_permute2f128_pd(s4824, s4825, (0) | ((2) << 4));
  *(a1309) = s4826;
  s4827 = _igen_dd_mm256_permute2f128_pd(s4824, s4825, (1) | ((3) << 4));
  *((a1309 + 1)) = s4827;
  s4828 = _igen_dd_mm256_unpacklo_pd(t3864, t3865);
  s4829 = _igen_dd_mm256_unpackhi_pd(t3864, t3865);
  s4830 = _igen_dd_mm256_permute2f128_pd(s4828, s4829, (0) | ((2) << 4));
  *((a1309 + 64)) = s4830;
  s4831 = _igen_dd_mm256_permute2f128_pd(s4828, s4829, (1) | ((3) << 4));
  *((a1309 + 65)) = s4831;
  t3866 = _igen_dd_mm256_sub_pd(t3856, t3861);
  t3867 = _igen_dd_mm256_add_pd(t3857, t3860);
  t3868 = _igen_dd_mm256_add_pd(t3856, t3861);
  t3869 = _igen_dd_mm256_sub_pd(t3857, t3860);
  s4832 = _igen_dd_mm256_unpacklo_pd(t3866, t3867);
  s4833 = _igen_dd_mm256_unpackhi_pd(t3866, t3867);
  s4834 = _igen_dd_mm256_permute2f128_pd(s4832, s4833, (0) | ((2) << 4));
  *((a1309 + 32)) = s4834;
  s4835 = _igen_dd_mm256_permute2f128_pd(s4832, s4833, (1) | ((3) << 4));
  *((a1309 + 33)) = s4835;
  s4836 = _igen_dd_mm256_unpacklo_pd(t3868, t3869);
  s4837 = _igen_dd_mm256_unpackhi_pd(t3868, t3869);
  s4838 = _igen_dd_mm256_permute2f128_pd(s4836, s4837, (0) | ((2) << 4));
  *((a1309 + 96)) = s4838;
  s4839 = _igen_dd_mm256_permute2f128_pd(s4836, s4837, (1) | ((3) << 4));
  *((a1309 + 97)) = s4839;
  dd_I _t1022 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1023 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t1024 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1025 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1026 = _igen_dd_mm256_set_pd(_t1022, _t1023, _t1024, _t1025);
  dd_I _t1027 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1028 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t1029 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1030 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1031 = _igen_dd_mm256_set_pd(_t1027, _t1028, _t1029, _t1030);
  ddi_4 _t1032 = _igen_dd_mm256_mul_pd(_t1026, s4476);
  ddi_4 _t1033 = _igen_dd_mm256_mul_pd(_t1031, s4480);
  s4840 = _igen_dd_mm256_sub_pd(_t1032, _t1033);
  dd_I _t1034 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1035 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t1036 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1037 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1038 = _igen_dd_mm256_set_pd(_t1034, _t1035, _t1036, _t1037);
  dd_I _t1039 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1040 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t1041 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1042 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1043 = _igen_dd_mm256_set_pd(_t1039, _t1040, _t1041, _t1042);
  ddi_4 _t1044 = _igen_dd_mm256_mul_pd(_t1038, s4476);
  ddi_4 _t1045 = _igen_dd_mm256_mul_pd(_t1043, s4480);
  s4841 = _igen_dd_mm256_add_pd(_t1044, _t1045);
  t3870 = _igen_dd_mm256_add_pd(s4474, s4840);
  t3871 = _igen_dd_mm256_add_pd(s4478, s4841);
  t3872 = _igen_dd_mm256_sub_pd(s4474, s4840);
  t3873 = _igen_dd_mm256_sub_pd(s4478, s4841);
  dd_I _t1046 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t1047 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1048 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t1049 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t1050 = _igen_dd_mm256_set_pd(_t1046, _t1047, _t1048, _t1049);
  dd_I _t1051 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t1052 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1053 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t1054 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t1055 = _igen_dd_mm256_set_pd(_t1051, _t1052, _t1053, _t1054);
  ddi_4 _t1056 = _igen_dd_mm256_mul_pd(_t1050, s4475);
  ddi_4 _t1057 = _igen_dd_mm256_mul_pd(_t1055, s4479);
  s4842 = _igen_dd_mm256_sub_pd(_t1056, _t1057);
  dd_I _t1058 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t1059 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1060 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t1061 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t1062 = _igen_dd_mm256_set_pd(_t1058, _t1059, _t1060, _t1061);
  dd_I _t1063 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t1064 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1065 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t1066 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t1067 = _igen_dd_mm256_set_pd(_t1063, _t1064, _t1065, _t1066);
  ddi_4 _t1068 = _igen_dd_mm256_mul_pd(_t1062, s4475);
  ddi_4 _t1069 = _igen_dd_mm256_mul_pd(_t1067, s4479);
  s4843 = _igen_dd_mm256_add_pd(_t1068, _t1069);
  dd_I _t1070 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t1071 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1072 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t1073 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t1074 = _igen_dd_mm256_set_pd(_t1070, _t1071, _t1072, _t1073);
  dd_I _t1075 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t1076 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1077 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t1078 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t1079 = _igen_dd_mm256_set_pd(_t1075, _t1076, _t1077, _t1078);
  ddi_4 _t1080 = _igen_dd_mm256_mul_pd(_t1074, s4477);
  ddi_4 _t1081 = _igen_dd_mm256_mul_pd(_t1079, s4481);
  s4844 = _igen_dd_mm256_sub_pd(_t1080, _t1081);
  dd_I _t1082 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t1083 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1084 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t1085 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t1086 = _igen_dd_mm256_set_pd(_t1082, _t1083, _t1084, _t1085);
  dd_I _t1087 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t1088 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1089 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t1090 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t1091 = _igen_dd_mm256_set_pd(_t1087, _t1088, _t1089, _t1090);
  ddi_4 _t1092 = _igen_dd_mm256_mul_pd(_t1086, s4477);
  ddi_4 _t1093 = _igen_dd_mm256_mul_pd(_t1091, s4481);
  s4845 = _igen_dd_mm256_add_pd(_t1092, _t1093);
  t3874 = _igen_dd_mm256_add_pd(s4842, s4844);
  t3875 = _igen_dd_mm256_add_pd(s4843, s4845);
  t3876 = _igen_dd_mm256_sub_pd(s4842, s4844);
  t3877 = _igen_dd_mm256_sub_pd(s4843, s4845);
  t3878 = _igen_dd_mm256_add_pd(t3870, t3874);
  t3879 = _igen_dd_mm256_add_pd(t3871, t3875);
  t3880 = _igen_dd_mm256_sub_pd(t3870, t3874);
  t3881 = _igen_dd_mm256_sub_pd(t3871, t3875);
  s4846 = _igen_dd_mm256_unpacklo_pd(t3878, t3879);
  s4847 = _igen_dd_mm256_unpackhi_pd(t3878, t3879);
  s4848 = _igen_dd_mm256_permute2f128_pd(s4846, s4847, (0) | ((2) << 4));
  *((a1309 + 2)) = s4848;
  s4849 = _igen_dd_mm256_permute2f128_pd(s4846, s4847, (1) | ((3) << 4));
  *((a1309 + 3)) = s4849;
  s4850 = _igen_dd_mm256_unpacklo_pd(t3880, t3881);
  s4851 = _igen_dd_mm256_unpackhi_pd(t3880, t3881);
  s4852 = _igen_dd_mm256_permute2f128_pd(s4850, s4851, (0) | ((2) << 4));
  *((a1309 + 66)) = s4852;
  s4853 = _igen_dd_mm256_permute2f128_pd(s4850, s4851, (1) | ((3) << 4));
  *((a1309 + 67)) = s4853;
  t3882 = _igen_dd_mm256_sub_pd(t3872, t3877);
  t3883 = _igen_dd_mm256_add_pd(t3873, t3876);
  t3884 = _igen_dd_mm256_add_pd(t3872, t3877);
  t3885 = _igen_dd_mm256_sub_pd(t3873, t3876);
  s4854 = _igen_dd_mm256_unpacklo_pd(t3882, t3883);
  s4855 = _igen_dd_mm256_unpackhi_pd(t3882, t3883);
  s4856 = _igen_dd_mm256_permute2f128_pd(s4854, s4855, (0) | ((2) << 4));
  *((a1309 + 34)) = s4856;
  s4857 = _igen_dd_mm256_permute2f128_pd(s4854, s4855, (1) | ((3) << 4));
  *((a1309 + 35)) = s4857;
  s4858 = _igen_dd_mm256_unpacklo_pd(t3884, t3885);
  s4859 = _igen_dd_mm256_unpackhi_pd(t3884, t3885);
  s4860 = _igen_dd_mm256_permute2f128_pd(s4858, s4859, (0) | ((2) << 4));
  *((a1309 + 98)) = s4860;
  s4861 = _igen_dd_mm256_permute2f128_pd(s4858, s4859, (1) | ((3) << 4));
  *((a1309 + 99)) = s4861;
  dd_I _t1094 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1095 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1096 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1097 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1098 = _igen_dd_mm256_set_pd(_t1094, _t1095, _t1096, _t1097);
  dd_I _t1099 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1100 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1101 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1102 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1103 = _igen_dd_mm256_set_pd(_t1099, _t1100, _t1101, _t1102);
  ddi_4 _t1104 = _igen_dd_mm256_mul_pd(_t1098, s4500);
  ddi_4 _t1105 = _igen_dd_mm256_mul_pd(_t1103, s4504);
  s4862 = _igen_dd_mm256_sub_pd(_t1104, _t1105);
  dd_I _t1106 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1107 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1108 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1109 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1110 = _igen_dd_mm256_set_pd(_t1106, _t1107, _t1108, _t1109);
  dd_I _t1111 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1112 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1113 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1114 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1115 = _igen_dd_mm256_set_pd(_t1111, _t1112, _t1113, _t1114);
  ddi_4 _t1116 = _igen_dd_mm256_mul_pd(_t1110, s4500);
  ddi_4 _t1117 = _igen_dd_mm256_mul_pd(_t1115, s4504);
  s4863 = _igen_dd_mm256_add_pd(_t1116, _t1117);
  t3886 = _igen_dd_mm256_add_pd(s4498, s4862);
  t3887 = _igen_dd_mm256_add_pd(s4502, s4863);
  t3888 = _igen_dd_mm256_sub_pd(s4498, s4862);
  t3889 = _igen_dd_mm256_sub_pd(s4502, s4863);
  dd_I _t1118 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t1119 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1120 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                           0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t1121 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1122 = _igen_dd_mm256_set_pd(_t1118, _t1119, _t1120, _t1121);
  dd_I _t1123 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t1124 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1125 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t1126 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1127 = _igen_dd_mm256_set_pd(_t1123, _t1124, _t1125, _t1126);
  ddi_4 _t1128 = _igen_dd_mm256_mul_pd(_t1122, s4499);
  ddi_4 _t1129 = _igen_dd_mm256_mul_pd(_t1127, s4503);
  s4864 = _igen_dd_mm256_sub_pd(_t1128, _t1129);
  dd_I _t1130 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t1131 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1132 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t1133 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1134 = _igen_dd_mm256_set_pd(_t1130, _t1131, _t1132, _t1133);
  dd_I _t1135 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t1136 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1137 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                           0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t1138 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1139 = _igen_dd_mm256_set_pd(_t1135, _t1136, _t1137, _t1138);
  ddi_4 _t1140 = _igen_dd_mm256_mul_pd(_t1134, s4499);
  ddi_4 _t1141 = _igen_dd_mm256_mul_pd(_t1139, s4503);
  s4865 = _igen_dd_mm256_add_pd(_t1140, _t1141);
  dd_I _t1142 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t1143 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1144 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t1145 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1146 = _igen_dd_mm256_set_pd(_t1142, _t1143, _t1144, _t1145);
  dd_I _t1147 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t1148 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1149 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t1150 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1151 = _igen_dd_mm256_set_pd(_t1147, _t1148, _t1149, _t1150);
  ddi_4 _t1152 = _igen_dd_mm256_mul_pd(_t1146, s4501);
  ddi_4 _t1153 = _igen_dd_mm256_mul_pd(_t1151, s4505);
  s4866 = _igen_dd_mm256_sub_pd(_t1152, _t1153);
  dd_I _t1154 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t1155 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1156 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t1157 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1158 = _igen_dd_mm256_set_pd(_t1154, _t1155, _t1156, _t1157);
  dd_I _t1159 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t1160 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1161 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t1162 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1163 = _igen_dd_mm256_set_pd(_t1159, _t1160, _t1161, _t1162);
  ddi_4 _t1164 = _igen_dd_mm256_mul_pd(_t1158, s4501);
  ddi_4 _t1165 = _igen_dd_mm256_mul_pd(_t1163, s4505);
  s4867 = _igen_dd_mm256_add_pd(_t1164, _t1165);
  t3890 = _igen_dd_mm256_add_pd(s4864, s4866);
  t3891 = _igen_dd_mm256_add_pd(s4865, s4867);
  t3892 = _igen_dd_mm256_sub_pd(s4864, s4866);
  t3893 = _igen_dd_mm256_sub_pd(s4865, s4867);
  t3894 = _igen_dd_mm256_add_pd(t3886, t3890);
  t3895 = _igen_dd_mm256_add_pd(t3887, t3891);
  t3896 = _igen_dd_mm256_sub_pd(t3886, t3890);
  t3897 = _igen_dd_mm256_sub_pd(t3887, t3891);
  s4868 = _igen_dd_mm256_unpacklo_pd(t3894, t3895);
  s4869 = _igen_dd_mm256_unpackhi_pd(t3894, t3895);
  s4870 = _igen_dd_mm256_permute2f128_pd(s4868, s4869, (0) | ((2) << 4));
  *((a1309 + 4)) = s4870;
  s4871 = _igen_dd_mm256_permute2f128_pd(s4868, s4869, (1) | ((3) << 4));
  *((a1309 + 5)) = s4871;
  s4872 = _igen_dd_mm256_unpacklo_pd(t3896, t3897);
  s4873 = _igen_dd_mm256_unpackhi_pd(t3896, t3897);
  s4874 = _igen_dd_mm256_permute2f128_pd(s4872, s4873, (0) | ((2) << 4));
  *((a1309 + 68)) = s4874;
  s4875 = _igen_dd_mm256_permute2f128_pd(s4872, s4873, (1) | ((3) << 4));
  *((a1309 + 69)) = s4875;
  t3898 = _igen_dd_mm256_sub_pd(t3888, t3893);
  t3899 = _igen_dd_mm256_add_pd(t3889, t3892);
  t3900 = _igen_dd_mm256_add_pd(t3888, t3893);
  t3901 = _igen_dd_mm256_sub_pd(t3889, t3892);
  s4876 = _igen_dd_mm256_unpacklo_pd(t3898, t3899);
  s4877 = _igen_dd_mm256_unpackhi_pd(t3898, t3899);
  s4878 = _igen_dd_mm256_permute2f128_pd(s4876, s4877, (0) | ((2) << 4));
  *((a1309 + 36)) = s4878;
  s4879 = _igen_dd_mm256_permute2f128_pd(s4876, s4877, (1) | ((3) << 4));
  *((a1309 + 37)) = s4879;
  s4880 = _igen_dd_mm256_unpacklo_pd(t3900, t3901);
  s4881 = _igen_dd_mm256_unpackhi_pd(t3900, t3901);
  s4882 = _igen_dd_mm256_permute2f128_pd(s4880, s4881, (0) | ((2) << 4));
  *((a1309 + 100)) = s4882;
  s4883 = _igen_dd_mm256_permute2f128_pd(s4880, s4881, (1) | ((3) << 4));
  *((a1309 + 101)) = s4883;
  dd_I _t1166 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1167 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1168 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1169 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1170 = _igen_dd_mm256_set_pd(_t1166, _t1167, _t1168, _t1169);
  dd_I _t1171 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1172 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1173 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1174 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1175 = _igen_dd_mm256_set_pd(_t1171, _t1172, _t1173, _t1174);
  ddi_4 _t1176 = _igen_dd_mm256_mul_pd(_t1170, s4524);
  ddi_4 _t1177 = _igen_dd_mm256_mul_pd(_t1175, s4528);
  s4884 = _igen_dd_mm256_sub_pd(_t1176, _t1177);
  dd_I _t1178 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1179 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1180 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1181 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1182 = _igen_dd_mm256_set_pd(_t1178, _t1179, _t1180, _t1181);
  dd_I _t1183 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1184 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1185 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1186 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1187 = _igen_dd_mm256_set_pd(_t1183, _t1184, _t1185, _t1186);
  ddi_4 _t1188 = _igen_dd_mm256_mul_pd(_t1182, s4524);
  ddi_4 _t1189 = _igen_dd_mm256_mul_pd(_t1187, s4528);
  s4885 = _igen_dd_mm256_add_pd(_t1188, _t1189);
  t3902 = _igen_dd_mm256_add_pd(s4522, s4884);
  t3903 = _igen_dd_mm256_add_pd(s4526, s4885);
  t3904 = _igen_dd_mm256_sub_pd(s4522, s4884);
  t3905 = _igen_dd_mm256_sub_pd(s4526, s4885);
  dd_I _t1190 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t1191 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1192 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1193 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t1194 = _igen_dd_mm256_set_pd(_t1190, _t1191, _t1192, _t1193);
  dd_I _t1195 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t1196 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1197 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1198 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t1199 = _igen_dd_mm256_set_pd(_t1195, _t1196, _t1197, _t1198);
  ddi_4 _t1200 = _igen_dd_mm256_mul_pd(_t1194, s4523);
  ddi_4 _t1201 = _igen_dd_mm256_mul_pd(_t1199, s4527);
  s4886 = _igen_dd_mm256_sub_pd(_t1200, _t1201);
  dd_I _t1202 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t1203 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1204 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1205 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t1206 = _igen_dd_mm256_set_pd(_t1202, _t1203, _t1204, _t1205);
  dd_I _t1207 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t1208 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1209 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1210 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t1211 = _igen_dd_mm256_set_pd(_t1207, _t1208, _t1209, _t1210);
  ddi_4 _t1212 = _igen_dd_mm256_mul_pd(_t1206, s4523);
  ddi_4 _t1213 = _igen_dd_mm256_mul_pd(_t1211, s4527);
  s4887 = _igen_dd_mm256_add_pd(_t1212, _t1213);
  dd_I _t1214 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1215 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1216 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1217 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t1218 = _igen_dd_mm256_set_pd(_t1214, _t1215, _t1216, _t1217);
  dd_I _t1219 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1220 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1221 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1222 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t1223 = _igen_dd_mm256_set_pd(_t1219, _t1220, _t1221, _t1222);
  ddi_4 _t1224 = _igen_dd_mm256_mul_pd(_t1218, s4525);
  ddi_4 _t1225 = _igen_dd_mm256_mul_pd(_t1223, s4529);
  s4888 = _igen_dd_mm256_sub_pd(_t1224, _t1225);
  dd_I _t1226 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1227 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1228 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1229 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t1230 = _igen_dd_mm256_set_pd(_t1226, _t1227, _t1228, _t1229);
  dd_I _t1231 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1232 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1233 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1234 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t1235 = _igen_dd_mm256_set_pd(_t1231, _t1232, _t1233, _t1234);
  ddi_4 _t1236 = _igen_dd_mm256_mul_pd(_t1230, s4525);
  ddi_4 _t1237 = _igen_dd_mm256_mul_pd(_t1235, s4529);
  s4889 = _igen_dd_mm256_add_pd(_t1236, _t1237);
  t3906 = _igen_dd_mm256_add_pd(s4886, s4888);
  t3907 = _igen_dd_mm256_add_pd(s4887, s4889);
  t3908 = _igen_dd_mm256_sub_pd(s4886, s4888);
  t3909 = _igen_dd_mm256_sub_pd(s4887, s4889);
  t3910 = _igen_dd_mm256_add_pd(t3902, t3906);
  t3911 = _igen_dd_mm256_add_pd(t3903, t3907);
  t3912 = _igen_dd_mm256_sub_pd(t3902, t3906);
  t3913 = _igen_dd_mm256_sub_pd(t3903, t3907);
  s4890 = _igen_dd_mm256_unpacklo_pd(t3910, t3911);
  s4891 = _igen_dd_mm256_unpackhi_pd(t3910, t3911);
  s4892 = _igen_dd_mm256_permute2f128_pd(s4890, s4891, (0) | ((2) << 4));
  *((a1309 + 6)) = s4892;
  s4893 = _igen_dd_mm256_permute2f128_pd(s4890, s4891, (1) | ((3) << 4));
  *((a1309 + 7)) = s4893;
  s4894 = _igen_dd_mm256_unpacklo_pd(t3912, t3913);
  s4895 = _igen_dd_mm256_unpackhi_pd(t3912, t3913);
  s4896 = _igen_dd_mm256_permute2f128_pd(s4894, s4895, (0) | ((2) << 4));
  *((a1309 + 70)) = s4896;
  s4897 = _igen_dd_mm256_permute2f128_pd(s4894, s4895, (1) | ((3) << 4));
  *((a1309 + 71)) = s4897;
  t3914 = _igen_dd_mm256_sub_pd(t3904, t3909);
  t3915 = _igen_dd_mm256_add_pd(t3905, t3908);
  t3916 = _igen_dd_mm256_add_pd(t3904, t3909);
  t3917 = _igen_dd_mm256_sub_pd(t3905, t3908);
  s4898 = _igen_dd_mm256_unpacklo_pd(t3914, t3915);
  s4899 = _igen_dd_mm256_unpackhi_pd(t3914, t3915);
  s4900 = _igen_dd_mm256_permute2f128_pd(s4898, s4899, (0) | ((2) << 4));
  *((a1309 + 38)) = s4900;
  s4901 = _igen_dd_mm256_permute2f128_pd(s4898, s4899, (1) | ((3) << 4));
  *((a1309 + 39)) = s4901;
  s4902 = _igen_dd_mm256_unpacklo_pd(t3916, t3917);
  s4903 = _igen_dd_mm256_unpackhi_pd(t3916, t3917);
  s4904 = _igen_dd_mm256_permute2f128_pd(s4902, s4903, (0) | ((2) << 4));
  *((a1309 + 102)) = s4904;
  s4905 = _igen_dd_mm256_permute2f128_pd(s4902, s4903, (1) | ((3) << 4));
  *((a1309 + 103)) = s4905;
  dd_I _t1238 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1239 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1240 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1241 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1242 = _igen_dd_mm256_set_pd(_t1238, _t1239, _t1240, _t1241);
  dd_I _t1243 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1244 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1245 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1246 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1247 = _igen_dd_mm256_set_pd(_t1243, _t1244, _t1245, _t1246);
  ddi_4 _t1248 = _igen_dd_mm256_mul_pd(_t1242, s4548);
  ddi_4 _t1249 = _igen_dd_mm256_mul_pd(_t1247, s4552);
  s4906 = _igen_dd_mm256_sub_pd(_t1248, _t1249);
  dd_I _t1250 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1251 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1252 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1253 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1254 = _igen_dd_mm256_set_pd(_t1250, _t1251, _t1252, _t1253);
  dd_I _t1255 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1256 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1257 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1258 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1259 = _igen_dd_mm256_set_pd(_t1255, _t1256, _t1257, _t1258);
  ddi_4 _t1260 = _igen_dd_mm256_mul_pd(_t1254, s4548);
  ddi_4 _t1261 = _igen_dd_mm256_mul_pd(_t1259, s4552);
  s4907 = _igen_dd_mm256_add_pd(_t1260, _t1261);
  t3918 = _igen_dd_mm256_add_pd(s4546, s4906);
  t3919 = _igen_dd_mm256_add_pd(s4550, s4907);
  t3920 = _igen_dd_mm256_sub_pd(s4546, s4906);
  t3921 = _igen_dd_mm256_sub_pd(s4550, s4907);
  dd_I _t1262 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1263 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1264 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1265 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1266 = _igen_dd_mm256_set_pd(_t1262, _t1263, _t1264, _t1265);
  dd_I _t1267 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1268 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1269 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1270 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1271 = _igen_dd_mm256_set_pd(_t1267, _t1268, _t1269, _t1270);
  ddi_4 _t1272 = _igen_dd_mm256_mul_pd(_t1266, s4547);
  ddi_4 _t1273 = _igen_dd_mm256_mul_pd(_t1271, s4551);
  s4908 = _igen_dd_mm256_sub_pd(_t1272, _t1273);
  dd_I _t1274 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1275 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1276 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1277 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1278 = _igen_dd_mm256_set_pd(_t1274, _t1275, _t1276, _t1277);
  dd_I _t1279 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1280 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1281 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1282 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1283 = _igen_dd_mm256_set_pd(_t1279, _t1280, _t1281, _t1282);
  ddi_4 _t1284 = _igen_dd_mm256_mul_pd(_t1278, s4547);
  ddi_4 _t1285 = _igen_dd_mm256_mul_pd(_t1283, s4551);
  s4909 = _igen_dd_mm256_add_pd(_t1284, _t1285);
  dd_I _t1286 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t1287 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1288 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1289 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1290 = _igen_dd_mm256_set_pd(_t1286, _t1287, _t1288, _t1289);
  dd_I _t1291 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t1292 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1293 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1294 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1295 = _igen_dd_mm256_set_pd(_t1291, _t1292, _t1293, _t1294);
  ddi_4 _t1296 = _igen_dd_mm256_mul_pd(_t1290, s4549);
  ddi_4 _t1297 = _igen_dd_mm256_mul_pd(_t1295, s4553);
  s4910 = _igen_dd_mm256_sub_pd(_t1296, _t1297);
  dd_I _t1298 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t1299 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1300 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1301 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1302 = _igen_dd_mm256_set_pd(_t1298, _t1299, _t1300, _t1301);
  dd_I _t1303 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t1304 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1305 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1306 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1307 = _igen_dd_mm256_set_pd(_t1303, _t1304, _t1305, _t1306);
  ddi_4 _t1308 = _igen_dd_mm256_mul_pd(_t1302, s4549);
  ddi_4 _t1309 = _igen_dd_mm256_mul_pd(_t1307, s4553);
  s4911 = _igen_dd_mm256_add_pd(_t1308, _t1309);
  t3922 = _igen_dd_mm256_add_pd(s4908, s4910);
  t3923 = _igen_dd_mm256_add_pd(s4909, s4911);
  t3924 = _igen_dd_mm256_sub_pd(s4908, s4910);
  t3925 = _igen_dd_mm256_sub_pd(s4909, s4911);
  t3926 = _igen_dd_mm256_add_pd(t3918, t3922);
  t3927 = _igen_dd_mm256_add_pd(t3919, t3923);
  t3928 = _igen_dd_mm256_sub_pd(t3918, t3922);
  t3929 = _igen_dd_mm256_sub_pd(t3919, t3923);
  s4912 = _igen_dd_mm256_unpacklo_pd(t3926, t3927);
  s4913 = _igen_dd_mm256_unpackhi_pd(t3926, t3927);
  s4914 = _igen_dd_mm256_permute2f128_pd(s4912, s4913, (0) | ((2) << 4));
  *((a1309 + 8)) = s4914;
  s4915 = _igen_dd_mm256_permute2f128_pd(s4912, s4913, (1) | ((3) << 4));
  *((a1309 + 9)) = s4915;
  s4916 = _igen_dd_mm256_unpacklo_pd(t3928, t3929);
  s4917 = _igen_dd_mm256_unpackhi_pd(t3928, t3929);
  s4918 = _igen_dd_mm256_permute2f128_pd(s4916, s4917, (0) | ((2) << 4));
  *((a1309 + 72)) = s4918;
  s4919 = _igen_dd_mm256_permute2f128_pd(s4916, s4917, (1) | ((3) << 4));
  *((a1309 + 73)) = s4919;
  t3930 = _igen_dd_mm256_sub_pd(t3920, t3925);
  t3931 = _igen_dd_mm256_add_pd(t3921, t3924);
  t3932 = _igen_dd_mm256_add_pd(t3920, t3925);
  t3933 = _igen_dd_mm256_sub_pd(t3921, t3924);
  s4920 = _igen_dd_mm256_unpacklo_pd(t3930, t3931);
  s4921 = _igen_dd_mm256_unpackhi_pd(t3930, t3931);
  s4922 = _igen_dd_mm256_permute2f128_pd(s4920, s4921, (0) | ((2) << 4));
  *((a1309 + 40)) = s4922;
  s4923 = _igen_dd_mm256_permute2f128_pd(s4920, s4921, (1) | ((3) << 4));
  *((a1309 + 41)) = s4923;
  s4924 = _igen_dd_mm256_unpacklo_pd(t3932, t3933);
  s4925 = _igen_dd_mm256_unpackhi_pd(t3932, t3933);
  s4926 = _igen_dd_mm256_permute2f128_pd(s4924, s4925, (0) | ((2) << 4));
  *((a1309 + 104)) = s4926;
  s4927 = _igen_dd_mm256_permute2f128_pd(s4924, s4925, (1) | ((3) << 4));
  *((a1309 + 105)) = s4927;
  dd_I _t1310 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1311 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1312 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1313 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1314 = _igen_dd_mm256_set_pd(_t1310, _t1311, _t1312, _t1313);
  dd_I _t1315 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1316 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1317 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1318 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1319 = _igen_dd_mm256_set_pd(_t1315, _t1316, _t1317, _t1318);
  ddi_4 _t1320 = _igen_dd_mm256_mul_pd(_t1314, s4572);
  ddi_4 _t1321 = _igen_dd_mm256_mul_pd(_t1319, s4576);
  s4928 = _igen_dd_mm256_sub_pd(_t1320, _t1321);
  dd_I _t1322 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1323 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1324 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1325 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1326 = _igen_dd_mm256_set_pd(_t1322, _t1323, _t1324, _t1325);
  dd_I _t1327 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1328 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1329 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1330 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1331 = _igen_dd_mm256_set_pd(_t1327, _t1328, _t1329, _t1330);
  ddi_4 _t1332 = _igen_dd_mm256_mul_pd(_t1326, s4572);
  ddi_4 _t1333 = _igen_dd_mm256_mul_pd(_t1331, s4576);
  s4929 = _igen_dd_mm256_add_pd(_t1332, _t1333);
  t3934 = _igen_dd_mm256_add_pd(s4570, s4928);
  t3935 = _igen_dd_mm256_add_pd(s4574, s4929);
  t3936 = _igen_dd_mm256_sub_pd(s4570, s4928);
  t3937 = _igen_dd_mm256_sub_pd(s4574, s4929);
  dd_I _t1334 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1335 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1336 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t1337 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t1338 = _igen_dd_mm256_set_pd(_t1334, _t1335, _t1336, _t1337);
  dd_I _t1339 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1340 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1341 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t1342 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t1343 = _igen_dd_mm256_set_pd(_t1339, _t1340, _t1341, _t1342);
  ddi_4 _t1344 = _igen_dd_mm256_mul_pd(_t1338, s4571);
  ddi_4 _t1345 = _igen_dd_mm256_mul_pd(_t1343, s4575);
  s4930 = _igen_dd_mm256_sub_pd(_t1344, _t1345);
  dd_I _t1346 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1347 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1348 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t1349 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t1350 = _igen_dd_mm256_set_pd(_t1346, _t1347, _t1348, _t1349);
  dd_I _t1351 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1352 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1353 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t1354 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t1355 = _igen_dd_mm256_set_pd(_t1351, _t1352, _t1353, _t1354);
  ddi_4 _t1356 = _igen_dd_mm256_mul_pd(_t1350, s4571);
  ddi_4 _t1357 = _igen_dd_mm256_mul_pd(_t1355, s4575);
  s4931 = _igen_dd_mm256_add_pd(_t1356, _t1357);
  dd_I _t1358 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t1359 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1360 = _ia_neg_dd(_t1358);
  dd_I _t1361 = _ia_neg_dd(_t1359);
  dd_I _t1362 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                           0.024541228522912288, -1.236030195850617e-19);
  dd_I _t1363 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t1364 = _igen_dd_mm256_set_pd(_t1360, _t1361, _t1362, _t1363);
  dd_I _t1365 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t1366 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1367 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                           0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t1368 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t1369 = _igen_dd_mm256_set_pd(_t1365, _t1366, _t1367, _t1368);
  ddi_4 _t1370 = _igen_dd_mm256_mul_pd(_t1364, s4573);
  ddi_4 _t1371 = _igen_dd_mm256_mul_pd(_t1369, s4577);
  s4932 = _igen_dd_mm256_sub_pd(_t1370, _t1371);
  dd_I _t1372 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t1373 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1374 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                           0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t1375 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t1376 = _igen_dd_mm256_set_pd(_t1372, _t1373, _t1374, _t1375);
  dd_I _t1377 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t1378 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1379 = _ia_neg_dd(_t1377);
  dd_I _t1380 = _ia_neg_dd(_t1378);
  dd_I _t1381 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                           0.024541228522912288, -1.236030195850617e-19);
  dd_I _t1382 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t1383 = _igen_dd_mm256_set_pd(_t1379, _t1380, _t1381, _t1382);
  ddi_4 _t1384 = _igen_dd_mm256_mul_pd(_t1376, s4573);
  ddi_4 _t1385 = _igen_dd_mm256_mul_pd(_t1383, s4577);
  s4933 = _igen_dd_mm256_add_pd(_t1384, _t1385);
  t3938 = _igen_dd_mm256_add_pd(s4930, s4932);
  t3939 = _igen_dd_mm256_add_pd(s4931, s4933);
  t3940 = _igen_dd_mm256_sub_pd(s4930, s4932);
  t3941 = _igen_dd_mm256_sub_pd(s4931, s4933);
  t3942 = _igen_dd_mm256_add_pd(t3934, t3938);
  t3943 = _igen_dd_mm256_add_pd(t3935, t3939);
  t3944 = _igen_dd_mm256_sub_pd(t3934, t3938);
  t3945 = _igen_dd_mm256_sub_pd(t3935, t3939);
  s4934 = _igen_dd_mm256_unpacklo_pd(t3942, t3943);
  s4935 = _igen_dd_mm256_unpackhi_pd(t3942, t3943);
  s4936 = _igen_dd_mm256_permute2f128_pd(s4934, s4935, (0) | ((2) << 4));
  *((a1309 + 10)) = s4936;
  s4937 = _igen_dd_mm256_permute2f128_pd(s4934, s4935, (1) | ((3) << 4));
  *((a1309 + 11)) = s4937;
  s4938 = _igen_dd_mm256_unpacklo_pd(t3944, t3945);
  s4939 = _igen_dd_mm256_unpackhi_pd(t3944, t3945);
  s4940 = _igen_dd_mm256_permute2f128_pd(s4938, s4939, (0) | ((2) << 4));
  *((a1309 + 74)) = s4940;
  s4941 = _igen_dd_mm256_permute2f128_pd(s4938, s4939, (1) | ((3) << 4));
  *((a1309 + 75)) = s4941;
  t3946 = _igen_dd_mm256_sub_pd(t3936, t3941);
  t3947 = _igen_dd_mm256_add_pd(t3937, t3940);
  t3948 = _igen_dd_mm256_add_pd(t3936, t3941);
  t3949 = _igen_dd_mm256_sub_pd(t3937, t3940);
  s4942 = _igen_dd_mm256_unpacklo_pd(t3946, t3947);
  s4943 = _igen_dd_mm256_unpackhi_pd(t3946, t3947);
  s4944 = _igen_dd_mm256_permute2f128_pd(s4942, s4943, (0) | ((2) << 4));
  *((a1309 + 42)) = s4944;
  s4945 = _igen_dd_mm256_permute2f128_pd(s4942, s4943, (1) | ((3) << 4));
  *((a1309 + 43)) = s4945;
  s4946 = _igen_dd_mm256_unpacklo_pd(t3948, t3949);
  s4947 = _igen_dd_mm256_unpackhi_pd(t3948, t3949);
  s4948 = _igen_dd_mm256_permute2f128_pd(s4946, s4947, (0) | ((2) << 4));
  *((a1309 + 106)) = s4948;
  s4949 = _igen_dd_mm256_permute2f128_pd(s4946, s4947, (1) | ((3) << 4));
  *((a1309 + 107)) = s4949;
  dd_I _t1386 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1387 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t1388 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1389 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1390 = _igen_dd_mm256_set_pd(_t1386, _t1387, _t1388, _t1389);
  dd_I _t1391 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1392 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t1393 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1394 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1395 = _igen_dd_mm256_set_pd(_t1391, _t1392, _t1393, _t1394);
  ddi_4 _t1396 = _igen_dd_mm256_mul_pd(_t1390, s4596);
  ddi_4 _t1397 = _igen_dd_mm256_mul_pd(_t1395, s4600);
  s4950 = _igen_dd_mm256_sub_pd(_t1396, _t1397);
  dd_I _t1398 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1399 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t1400 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1401 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1402 = _igen_dd_mm256_set_pd(_t1398, _t1399, _t1400, _t1401);
  dd_I _t1403 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1404 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t1405 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1406 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1407 = _igen_dd_mm256_set_pd(_t1403, _t1404, _t1405, _t1406);
  ddi_4 _t1408 = _igen_dd_mm256_mul_pd(_t1402, s4596);
  ddi_4 _t1409 = _igen_dd_mm256_mul_pd(_t1407, s4600);
  s4951 = _igen_dd_mm256_add_pd(_t1408, _t1409);
  t3950 = _igen_dd_mm256_add_pd(s4594, s4950);
  t3951 = _igen_dd_mm256_add_pd(s4598, s4951);
  t3952 = _igen_dd_mm256_sub_pd(s4594, s4950);
  t3953 = _igen_dd_mm256_sub_pd(s4598, s4951);
  dd_I _t1410 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t1411 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1412 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1413 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1414 = _igen_dd_mm256_set_pd(_t1410, _t1411, _t1412, _t1413);
  dd_I _t1415 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t1416 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1417 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1418 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1419 = _igen_dd_mm256_set_pd(_t1415, _t1416, _t1417, _t1418);
  ddi_4 _t1420 = _igen_dd_mm256_mul_pd(_t1414, s4595);
  ddi_4 _t1421 = _igen_dd_mm256_mul_pd(_t1419, s4599);
  s4952 = _igen_dd_mm256_sub_pd(_t1420, _t1421);
  dd_I _t1422 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t1423 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1424 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1425 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1426 = _igen_dd_mm256_set_pd(_t1422, _t1423, _t1424, _t1425);
  dd_I _t1427 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t1428 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1429 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1430 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1431 = _igen_dd_mm256_set_pd(_t1427, _t1428, _t1429, _t1430);
  ddi_4 _t1432 = _igen_dd_mm256_mul_pd(_t1426, s4595);
  ddi_4 _t1433 = _igen_dd_mm256_mul_pd(_t1431, s4599);
  s4953 = _igen_dd_mm256_add_pd(_t1432, _t1433);
  dd_I _t1434 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1435 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1436 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t1437 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t1438 = _ia_neg_dd(_t1434);
  dd_I _t1439 = _ia_neg_dd(_t1435);
  dd_I _t1440 = _ia_neg_dd(_t1436);
  dd_I _t1441 = _ia_neg_dd(_t1437);
  ddi_4 _t1442 = _igen_dd_mm256_set_pd(_t1438, _t1439, _t1440, _t1441);
  dd_I _t1443 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1444 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1445 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t1446 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1447 = _igen_dd_mm256_set_pd(_t1443, _t1444, _t1445, _t1446);
  ddi_4 _t1448 = _igen_dd_mm256_mul_pd(_t1442, s4597);
  ddi_4 _t1449 = _igen_dd_mm256_mul_pd(_t1447, s4601);
  s4954 = _igen_dd_mm256_sub_pd(_t1448, _t1449);
  dd_I _t1450 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1451 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1452 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t1453 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1454 = _igen_dd_mm256_set_pd(_t1450, _t1451, _t1452, _t1453);
  dd_I _t1455 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1456 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1457 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t1458 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t1459 = _ia_neg_dd(_t1455);
  dd_I _t1460 = _ia_neg_dd(_t1456);
  dd_I _t1461 = _ia_neg_dd(_t1457);
  dd_I _t1462 = _ia_neg_dd(_t1458);
  ddi_4 _t1463 = _igen_dd_mm256_set_pd(_t1459, _t1460, _t1461, _t1462);
  ddi_4 _t1464 = _igen_dd_mm256_mul_pd(_t1454, s4597);
  ddi_4 _t1465 = _igen_dd_mm256_mul_pd(_t1463, s4601);
  s4955 = _igen_dd_mm256_add_pd(_t1464, _t1465);
  t3954 = _igen_dd_mm256_add_pd(s4952, s4954);
  t3955 = _igen_dd_mm256_add_pd(s4953, s4955);
  t3956 = _igen_dd_mm256_sub_pd(s4952, s4954);
  t3957 = _igen_dd_mm256_sub_pd(s4953, s4955);
  t3958 = _igen_dd_mm256_add_pd(t3950, t3954);
  t3959 = _igen_dd_mm256_add_pd(t3951, t3955);
  t3960 = _igen_dd_mm256_sub_pd(t3950, t3954);
  t3961 = _igen_dd_mm256_sub_pd(t3951, t3955);
  s4956 = _igen_dd_mm256_unpacklo_pd(t3958, t3959);
  s4957 = _igen_dd_mm256_unpackhi_pd(t3958, t3959);
  s4958 = _igen_dd_mm256_permute2f128_pd(s4956, s4957, (0) | ((2) << 4));
  *((a1309 + 12)) = s4958;
  s4959 = _igen_dd_mm256_permute2f128_pd(s4956, s4957, (1) | ((3) << 4));
  *((a1309 + 13)) = s4959;
  s4960 = _igen_dd_mm256_unpacklo_pd(t3960, t3961);
  s4961 = _igen_dd_mm256_unpackhi_pd(t3960, t3961);
  s4962 = _igen_dd_mm256_permute2f128_pd(s4960, s4961, (0) | ((2) << 4));
  *((a1309 + 76)) = s4962;
  s4963 = _igen_dd_mm256_permute2f128_pd(s4960, s4961, (1) | ((3) << 4));
  *((a1309 + 77)) = s4963;
  t3962 = _igen_dd_mm256_sub_pd(t3952, t3957);
  t3963 = _igen_dd_mm256_add_pd(t3953, t3956);
  t3964 = _igen_dd_mm256_add_pd(t3952, t3957);
  t3965 = _igen_dd_mm256_sub_pd(t3953, t3956);
  s4964 = _igen_dd_mm256_unpacklo_pd(t3962, t3963);
  s4965 = _igen_dd_mm256_unpackhi_pd(t3962, t3963);
  s4966 = _igen_dd_mm256_permute2f128_pd(s4964, s4965, (0) | ((2) << 4));
  *((a1309 + 44)) = s4966;
  s4967 = _igen_dd_mm256_permute2f128_pd(s4964, s4965, (1) | ((3) << 4));
  *((a1309 + 45)) = s4967;
  s4968 = _igen_dd_mm256_unpacklo_pd(t3964, t3965);
  s4969 = _igen_dd_mm256_unpackhi_pd(t3964, t3965);
  s4970 = _igen_dd_mm256_permute2f128_pd(s4968, s4969, (0) | ((2) << 4));
  *((a1309 + 108)) = s4970;
  s4971 = _igen_dd_mm256_permute2f128_pd(s4968, s4969, (1) | ((3) << 4));
  *((a1309 + 109)) = s4971;
  dd_I _t1466 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1467 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t1468 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1469 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1470 = _igen_dd_mm256_set_pd(_t1466, _t1467, _t1468, _t1469);
  dd_I _t1471 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1472 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t1473 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1474 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1475 = _igen_dd_mm256_set_pd(_t1471, _t1472, _t1473, _t1474);
  ddi_4 _t1476 = _igen_dd_mm256_mul_pd(_t1470, s4620);
  ddi_4 _t1477 = _igen_dd_mm256_mul_pd(_t1475, s4624);
  s4972 = _igen_dd_mm256_sub_pd(_t1476, _t1477);
  dd_I _t1478 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1479 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t1480 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1481 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1482 = _igen_dd_mm256_set_pd(_t1478, _t1479, _t1480, _t1481);
  dd_I _t1483 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1484 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t1485 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1486 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1487 = _igen_dd_mm256_set_pd(_t1483, _t1484, _t1485, _t1486);
  ddi_4 _t1488 = _igen_dd_mm256_mul_pd(_t1482, s4620);
  ddi_4 _t1489 = _igen_dd_mm256_mul_pd(_t1487, s4624);
  s4973 = _igen_dd_mm256_add_pd(_t1488, _t1489);
  t3966 = _igen_dd_mm256_add_pd(s4618, s4972);
  t3967 = _igen_dd_mm256_add_pd(s4622, s4973);
  t3968 = _igen_dd_mm256_sub_pd(s4618, s4972);
  t3969 = _igen_dd_mm256_sub_pd(s4622, s4973);
  dd_I _t1490 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t1491 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1492 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1493 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t1494 = _igen_dd_mm256_set_pd(_t1490, _t1491, _t1492, _t1493);
  dd_I _t1495 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t1496 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1497 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1498 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t1499 = _igen_dd_mm256_set_pd(_t1495, _t1496, _t1497, _t1498);
  ddi_4 _t1500 = _igen_dd_mm256_mul_pd(_t1494, s4619);
  ddi_4 _t1501 = _igen_dd_mm256_mul_pd(_t1499, s4623);
  s4974 = _igen_dd_mm256_sub_pd(_t1500, _t1501);
  dd_I _t1502 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t1503 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1504 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1505 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t1506 = _igen_dd_mm256_set_pd(_t1502, _t1503, _t1504, _t1505);
  dd_I _t1507 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t1508 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1509 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1510 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t1511 = _igen_dd_mm256_set_pd(_t1507, _t1508, _t1509, _t1510);
  ddi_4 _t1512 = _igen_dd_mm256_mul_pd(_t1506, s4619);
  ddi_4 _t1513 = _igen_dd_mm256_mul_pd(_t1511, s4623);
  s4975 = _igen_dd_mm256_add_pd(_t1512, _t1513);
  dd_I _t1514 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1515 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1516 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1517 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1518 = _ia_neg_dd(_t1514);
  dd_I _t1519 = _ia_neg_dd(_t1515);
  dd_I _t1520 = _ia_neg_dd(_t1516);
  dd_I _t1521 = _ia_neg_dd(_t1517);
  ddi_4 _t1522 = _igen_dd_mm256_set_pd(_t1518, _t1519, _t1520, _t1521);
  dd_I _t1523 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1524 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1525 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1526 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t1527 = _igen_dd_mm256_set_pd(_t1523, _t1524, _t1525, _t1526);
  ddi_4 _t1528 = _igen_dd_mm256_mul_pd(_t1522, s4621);
  ddi_4 _t1529 = _igen_dd_mm256_mul_pd(_t1527, s4625);
  s4976 = _igen_dd_mm256_sub_pd(_t1528, _t1529);
  dd_I _t1530 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1531 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1532 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1533 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t1534 = _igen_dd_mm256_set_pd(_t1530, _t1531, _t1532, _t1533);
  dd_I _t1535 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1536 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1537 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1538 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1539 = _ia_neg_dd(_t1535);
  dd_I _t1540 = _ia_neg_dd(_t1536);
  dd_I _t1541 = _ia_neg_dd(_t1537);
  dd_I _t1542 = _ia_neg_dd(_t1538);
  ddi_4 _t1543 = _igen_dd_mm256_set_pd(_t1539, _t1540, _t1541, _t1542);
  ddi_4 _t1544 = _igen_dd_mm256_mul_pd(_t1534, s4621);
  ddi_4 _t1545 = _igen_dd_mm256_mul_pd(_t1543, s4625);
  s4977 = _igen_dd_mm256_add_pd(_t1544, _t1545);
  t3970 = _igen_dd_mm256_add_pd(s4974, s4976);
  t3971 = _igen_dd_mm256_add_pd(s4975, s4977);
  t3972 = _igen_dd_mm256_sub_pd(s4974, s4976);
  t3973 = _igen_dd_mm256_sub_pd(s4975, s4977);
  t3974 = _igen_dd_mm256_add_pd(t3966, t3970);
  t3975 = _igen_dd_mm256_add_pd(t3967, t3971);
  t3976 = _igen_dd_mm256_sub_pd(t3966, t3970);
  t3977 = _igen_dd_mm256_sub_pd(t3967, t3971);
  s4978 = _igen_dd_mm256_unpacklo_pd(t3974, t3975);
  s4979 = _igen_dd_mm256_unpackhi_pd(t3974, t3975);
  s4980 = _igen_dd_mm256_permute2f128_pd(s4978, s4979, (0) | ((2) << 4));
  *((a1309 + 14)) = s4980;
  s4981 = _igen_dd_mm256_permute2f128_pd(s4978, s4979, (1) | ((3) << 4));
  *((a1309 + 15)) = s4981;
  s4982 = _igen_dd_mm256_unpacklo_pd(t3976, t3977);
  s4983 = _igen_dd_mm256_unpackhi_pd(t3976, t3977);
  s4984 = _igen_dd_mm256_permute2f128_pd(s4982, s4983, (0) | ((2) << 4));
  *((a1309 + 78)) = s4984;
  s4985 = _igen_dd_mm256_permute2f128_pd(s4982, s4983, (1) | ((3) << 4));
  *((a1309 + 79)) = s4985;
  t3978 = _igen_dd_mm256_sub_pd(t3968, t3973);
  t3979 = _igen_dd_mm256_add_pd(t3969, t3972);
  t3980 = _igen_dd_mm256_add_pd(t3968, t3973);
  t3981 = _igen_dd_mm256_sub_pd(t3969, t3972);
  s4986 = _igen_dd_mm256_unpacklo_pd(t3978, t3979);
  s4987 = _igen_dd_mm256_unpackhi_pd(t3978, t3979);
  s4988 = _igen_dd_mm256_permute2f128_pd(s4986, s4987, (0) | ((2) << 4));
  *((a1309 + 46)) = s4988;
  s4989 = _igen_dd_mm256_permute2f128_pd(s4986, s4987, (1) | ((3) << 4));
  *((a1309 + 47)) = s4989;
  s4990 = _igen_dd_mm256_unpacklo_pd(t3980, t3981);
  s4991 = _igen_dd_mm256_unpackhi_pd(t3980, t3981);
  s4992 = _igen_dd_mm256_permute2f128_pd(s4990, s4991, (0) | ((2) << 4));
  *((a1309 + 110)) = s4992;
  s4993 = _igen_dd_mm256_permute2f128_pd(s4990, s4991, (1) | ((3) << 4));
  *((a1309 + 111)) = s4993;
  dd_I _t1546 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1547 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t1548 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1549 = _ia_neg_dd(_t1546);
  dd_I _t1550 = _ia_neg_dd(_t1547);
  dd_I _t1551 = _ia_neg_dd(_t1548);
  dd_I _t1552 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t1553 = _igen_dd_mm256_set_pd(_t1549, _t1550, _t1551, _t1552);
  dd_I _t1554 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1555 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t1556 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1557 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t1558 = _igen_dd_mm256_set_pd(_t1554, _t1555, _t1556, _t1557);
  ddi_4 _t1559 = _igen_dd_mm256_mul_pd(_t1553, s4644);
  ddi_4 _t1560 = _igen_dd_mm256_mul_pd(_t1558, s4648);
  s4994 = _igen_dd_mm256_sub_pd(_t1559, _t1560);
  dd_I _t1561 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t1562 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t1563 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1564 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t1565 = _igen_dd_mm256_set_pd(_t1561, _t1562, _t1563, _t1564);
  dd_I _t1566 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t1567 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t1568 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1569 = _ia_neg_dd(_t1566);
  dd_I _t1570 = _ia_neg_dd(_t1567);
  dd_I _t1571 = _ia_neg_dd(_t1568);
  dd_I _t1572 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t1573 = _igen_dd_mm256_set_pd(_t1569, _t1570, _t1571, _t1572);
  ddi_4 _t1574 = _igen_dd_mm256_mul_pd(_t1565, s4644);
  ddi_4 _t1575 = _igen_dd_mm256_mul_pd(_t1573, s4648);
  s4995 = _igen_dd_mm256_add_pd(_t1574, _t1575);
  t3982 = _igen_dd_mm256_add_pd(s4642, s4994);
  t3983 = _igen_dd_mm256_add_pd(s4646, s4995);
  t3984 = _igen_dd_mm256_sub_pd(s4642, s4994);
  t3985 = _igen_dd_mm256_sub_pd(s4646, s4995);
  dd_I _t1576 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1577 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1578 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t1579 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1580 = _igen_dd_mm256_set_pd(_t1576, _t1577, _t1578, _t1579);
  dd_I _t1581 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1582 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1583 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t1584 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1585 = _igen_dd_mm256_set_pd(_t1581, _t1582, _t1583, _t1584);
  ddi_4 _t1586 = _igen_dd_mm256_mul_pd(_t1580, s4643);
  ddi_4 _t1587 = _igen_dd_mm256_mul_pd(_t1585, s4647);
  s4996 = _igen_dd_mm256_sub_pd(_t1586, _t1587);
  dd_I _t1588 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1589 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1590 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t1591 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1592 = _igen_dd_mm256_set_pd(_t1588, _t1589, _t1590, _t1591);
  dd_I _t1593 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1594 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1595 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t1596 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1597 = _igen_dd_mm256_set_pd(_t1593, _t1594, _t1595, _t1596);
  ddi_4 _t1598 = _igen_dd_mm256_mul_pd(_t1592, s4643);
  ddi_4 _t1599 = _igen_dd_mm256_mul_pd(_t1597, s4647);
  s4997 = _igen_dd_mm256_add_pd(_t1598, _t1599);
  dd_I _t1600 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1601 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1602 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1603 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  dd_I _t1604 = _ia_neg_dd(_t1600);
  dd_I _t1605 = _ia_neg_dd(_t1601);
  dd_I _t1606 = _ia_neg_dd(_t1602);
  dd_I _t1607 = _ia_neg_dd(_t1603);
  ddi_4 _t1608 = _igen_dd_mm256_set_pd(_t1604, _t1605, _t1606, _t1607);
  dd_I _t1609 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1610 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1611 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1612 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1613 = _igen_dd_mm256_set_pd(_t1609, _t1610, _t1611, _t1612);
  ddi_4 _t1614 = _igen_dd_mm256_mul_pd(_t1608, s4645);
  ddi_4 _t1615 = _igen_dd_mm256_mul_pd(_t1613, s4649);
  s4998 = _igen_dd_mm256_sub_pd(_t1614, _t1615);
  dd_I _t1616 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1617 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1618 = _ia_set_dd(-0.65317284295377676, -4.4853611923463173e-18,
                           0.65317284295377676, 4.4853611923463181e-18);
  dd_I _t1619 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1620 = _igen_dd_mm256_set_pd(_t1616, _t1617, _t1618, _t1619);
  dd_I _t1621 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1622 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1623 = _ia_set_dd(-0.75720884650648457, -2.5154371690587138e-18,
                           0.75720884650648457, 2.5154371690587142e-18);
  dd_I _t1624 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  dd_I _t1625 = _ia_neg_dd(_t1621);
  dd_I _t1626 = _ia_neg_dd(_t1622);
  dd_I _t1627 = _ia_neg_dd(_t1623);
  dd_I _t1628 = _ia_neg_dd(_t1624);
  ddi_4 _t1629 = _igen_dd_mm256_set_pd(_t1625, _t1626, _t1627, _t1628);
  ddi_4 _t1630 = _igen_dd_mm256_mul_pd(_t1620, s4645);
  ddi_4 _t1631 = _igen_dd_mm256_mul_pd(_t1629, s4649);
  s4999 = _igen_dd_mm256_add_pd(_t1630, _t1631);
  t3986 = _igen_dd_mm256_add_pd(s4996, s4998);
  t3987 = _igen_dd_mm256_add_pd(s4997, s4999);
  t3988 = _igen_dd_mm256_sub_pd(s4996, s4998);
  t3989 = _igen_dd_mm256_sub_pd(s4997, s4999);
  t3990 = _igen_dd_mm256_add_pd(t3982, t3986);
  t3991 = _igen_dd_mm256_add_pd(t3983, t3987);
  t3992 = _igen_dd_mm256_sub_pd(t3982, t3986);
  t3993 = _igen_dd_mm256_sub_pd(t3983, t3987);
  s5000 = _igen_dd_mm256_unpacklo_pd(t3990, t3991);
  s5001 = _igen_dd_mm256_unpackhi_pd(t3990, t3991);
  s5002 = _igen_dd_mm256_permute2f128_pd(s5000, s5001, (0) | ((2) << 4));
  *((a1309 + 16)) = s5002;
  s5003 = _igen_dd_mm256_permute2f128_pd(s5000, s5001, (1) | ((3) << 4));
  *((a1309 + 17)) = s5003;
  s5004 = _igen_dd_mm256_unpacklo_pd(t3992, t3993);
  s5005 = _igen_dd_mm256_unpackhi_pd(t3992, t3993);
  s5006 = _igen_dd_mm256_permute2f128_pd(s5004, s5005, (0) | ((2) << 4));
  *((a1309 + 80)) = s5006;
  s5007 = _igen_dd_mm256_permute2f128_pd(s5004, s5005, (1) | ((3) << 4));
  *((a1309 + 81)) = s5007;
  t3994 = _igen_dd_mm256_sub_pd(t3984, t3989);
  t3995 = _igen_dd_mm256_add_pd(t3985, t3988);
  t3996 = _igen_dd_mm256_add_pd(t3984, t3989);
  t3997 = _igen_dd_mm256_sub_pd(t3985, t3988);
  s5008 = _igen_dd_mm256_unpacklo_pd(t3994, t3995);
  s5009 = _igen_dd_mm256_unpackhi_pd(t3994, t3995);
  s5010 = _igen_dd_mm256_permute2f128_pd(s5008, s5009, (0) | ((2) << 4));
  *((a1309 + 48)) = s5010;
  s5011 = _igen_dd_mm256_permute2f128_pd(s5008, s5009, (1) | ((3) << 4));
  *((a1309 + 49)) = s5011;
  s5012 = _igen_dd_mm256_unpacklo_pd(t3996, t3997);
  s5013 = _igen_dd_mm256_unpackhi_pd(t3996, t3997);
  s5014 = _igen_dd_mm256_permute2f128_pd(s5012, s5013, (0) | ((2) << 4));
  *((a1309 + 112)) = s5014;
  s5015 = _igen_dd_mm256_permute2f128_pd(s5012, s5013, (1) | ((3) << 4));
  *((a1309 + 113)) = s5015;
  dd_I _t1632 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1633 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t1634 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1635 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t1636 = _ia_neg_dd(_t1632);
  dd_I _t1637 = _ia_neg_dd(_t1633);
  dd_I _t1638 = _ia_neg_dd(_t1634);
  dd_I _t1639 = _ia_neg_dd(_t1635);
  ddi_4 _t1640 = _igen_dd_mm256_set_pd(_t1636, _t1637, _t1638, _t1639);
  dd_I _t1641 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1642 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t1643 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1644 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1645 = _igen_dd_mm256_set_pd(_t1641, _t1642, _t1643, _t1644);
  ddi_4 _t1646 = _igen_dd_mm256_mul_pd(_t1640, s4668);
  ddi_4 _t1647 = _igen_dd_mm256_mul_pd(_t1645, s4672);
  s5016 = _igen_dd_mm256_sub_pd(_t1646, _t1647);
  dd_I _t1648 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1649 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t1650 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1651 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t1652 = _igen_dd_mm256_set_pd(_t1648, _t1649, _t1650, _t1651);
  dd_I _t1653 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1654 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t1655 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1656 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t1657 = _ia_neg_dd(_t1653);
  dd_I _t1658 = _ia_neg_dd(_t1654);
  dd_I _t1659 = _ia_neg_dd(_t1655);
  dd_I _t1660 = _ia_neg_dd(_t1656);
  ddi_4 _t1661 = _igen_dd_mm256_set_pd(_t1657, _t1658, _t1659, _t1660);
  ddi_4 _t1662 = _igen_dd_mm256_mul_pd(_t1652, s4668);
  ddi_4 _t1663 = _igen_dd_mm256_mul_pd(_t1661, s4672);
  s5017 = _igen_dd_mm256_add_pd(_t1662, _t1663);
  t3998 = _igen_dd_mm256_add_pd(s4666, s5016);
  t3999 = _igen_dd_mm256_add_pd(s4670, s5017);
  t4000 = _igen_dd_mm256_sub_pd(s4666, s5016);
  t4001 = _igen_dd_mm256_sub_pd(s4670, s5017);
  dd_I _t1664 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1665 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1666 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t1667 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t1668 = _igen_dd_mm256_set_pd(_t1664, _t1665, _t1666, _t1667);
  dd_I _t1669 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1670 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1671 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t1672 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t1673 = _igen_dd_mm256_set_pd(_t1669, _t1670, _t1671, _t1672);
  ddi_4 _t1674 = _igen_dd_mm256_mul_pd(_t1668, s4667);
  ddi_4 _t1675 = _igen_dd_mm256_mul_pd(_t1673, s4671);
  s5018 = _igen_dd_mm256_sub_pd(_t1674, _t1675);
  dd_I _t1676 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1677 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1678 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t1679 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  ddi_4 _t1680 = _igen_dd_mm256_set_pd(_t1676, _t1677, _t1678, _t1679);
  dd_I _t1681 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1682 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1683 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t1684 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  ddi_4 _t1685 = _igen_dd_mm256_set_pd(_t1681, _t1682, _t1683, _t1684);
  ddi_4 _t1686 = _igen_dd_mm256_mul_pd(_t1680, s4667);
  ddi_4 _t1687 = _igen_dd_mm256_mul_pd(_t1685, s4671);
  s5019 = _igen_dd_mm256_add_pd(_t1686, _t1687);
  dd_I _t1688 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t1689 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1690 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1691 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1692 = _ia_neg_dd(_t1688);
  dd_I _t1693 = _ia_neg_dd(_t1689);
  dd_I _t1694 = _ia_neg_dd(_t1690);
  dd_I _t1695 = _ia_neg_dd(_t1691);
  ddi_4 _t1696 = _igen_dd_mm256_set_pd(_t1692, _t1693, _t1694, _t1695);
  dd_I _t1697 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t1698 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1699 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1700 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t1701 = _igen_dd_mm256_set_pd(_t1697, _t1698, _t1699, _t1700);
  ddi_4 _t1702 = _igen_dd_mm256_mul_pd(_t1696, s4669);
  ddi_4 _t1703 = _igen_dd_mm256_mul_pd(_t1701, s4673);
  s5020 = _igen_dd_mm256_sub_pd(_t1702, _t1703);
  dd_I _t1704 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t1705 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1706 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1707 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t1708 = _igen_dd_mm256_set_pd(_t1704, _t1705, _t1706, _t1707);
  dd_I _t1709 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t1710 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1711 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1712 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1713 = _ia_neg_dd(_t1709);
  dd_I _t1714 = _ia_neg_dd(_t1710);
  dd_I _t1715 = _ia_neg_dd(_t1711);
  dd_I _t1716 = _ia_neg_dd(_t1712);
  ddi_4 _t1717 = _igen_dd_mm256_set_pd(_t1713, _t1714, _t1715, _t1716);
  ddi_4 _t1718 = _igen_dd_mm256_mul_pd(_t1708, s4669);
  ddi_4 _t1719 = _igen_dd_mm256_mul_pd(_t1717, s4673);
  s5021 = _igen_dd_mm256_add_pd(_t1718, _t1719);
  t4002 = _igen_dd_mm256_add_pd(s5018, s5020);
  t4003 = _igen_dd_mm256_add_pd(s5019, s5021);
  t4004 = _igen_dd_mm256_sub_pd(s5018, s5020);
  t4005 = _igen_dd_mm256_sub_pd(s5019, s5021);
  t4006 = _igen_dd_mm256_add_pd(t3998, t4002);
  t4007 = _igen_dd_mm256_add_pd(t3999, t4003);
  t4008 = _igen_dd_mm256_sub_pd(t3998, t4002);
  t4009 = _igen_dd_mm256_sub_pd(t3999, t4003);
  s5022 = _igen_dd_mm256_unpacklo_pd(t4006, t4007);
  s5023 = _igen_dd_mm256_unpackhi_pd(t4006, t4007);
  s5024 = _igen_dd_mm256_permute2f128_pd(s5022, s5023, (0) | ((2) << 4));
  *((a1309 + 18)) = s5024;
  s5025 = _igen_dd_mm256_permute2f128_pd(s5022, s5023, (1) | ((3) << 4));
  *((a1309 + 19)) = s5025;
  s5026 = _igen_dd_mm256_unpacklo_pd(t4008, t4009);
  s5027 = _igen_dd_mm256_unpackhi_pd(t4008, t4009);
  s5028 = _igen_dd_mm256_permute2f128_pd(s5026, s5027, (0) | ((2) << 4));
  *((a1309 + 82)) = s5028;
  s5029 = _igen_dd_mm256_permute2f128_pd(s5026, s5027, (1) | ((3) << 4));
  *((a1309 + 83)) = s5029;
  t4010 = _igen_dd_mm256_sub_pd(t4000, t4005);
  t4011 = _igen_dd_mm256_add_pd(t4001, t4004);
  t4012 = _igen_dd_mm256_add_pd(t4000, t4005);
  t4013 = _igen_dd_mm256_sub_pd(t4001, t4004);
  s5030 = _igen_dd_mm256_unpacklo_pd(t4010, t4011);
  s5031 = _igen_dd_mm256_unpackhi_pd(t4010, t4011);
  s5032 = _igen_dd_mm256_permute2f128_pd(s5030, s5031, (0) | ((2) << 4));
  *((a1309 + 50)) = s5032;
  s5033 = _igen_dd_mm256_permute2f128_pd(s5030, s5031, (1) | ((3) << 4));
  *((a1309 + 51)) = s5033;
  s5034 = _igen_dd_mm256_unpacklo_pd(t4012, t4013);
  s5035 = _igen_dd_mm256_unpackhi_pd(t4012, t4013);
  s5036 = _igen_dd_mm256_permute2f128_pd(s5034, s5035, (0) | ((2) << 4));
  *((a1309 + 114)) = s5036;
  s5037 = _igen_dd_mm256_permute2f128_pd(s5034, s5035, (1) | ((3) << 4));
  *((a1309 + 115)) = s5037;
  dd_I _t1720 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1721 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1722 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1723 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t1724 = _ia_neg_dd(_t1720);
  dd_I _t1725 = _ia_neg_dd(_t1721);
  dd_I _t1726 = _ia_neg_dd(_t1722);
  dd_I _t1727 = _ia_neg_dd(_t1723);
  ddi_4 _t1728 = _igen_dd_mm256_set_pd(_t1724, _t1725, _t1726, _t1727);
  dd_I _t1729 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1730 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1731 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1732 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1733 = _igen_dd_mm256_set_pd(_t1729, _t1730, _t1731, _t1732);
  ddi_4 _t1734 = _igen_dd_mm256_mul_pd(_t1728, s4692);
  ddi_4 _t1735 = _igen_dd_mm256_mul_pd(_t1733, s4696);
  s5038 = _igen_dd_mm256_sub_pd(_t1734, _t1735);
  dd_I _t1736 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1737 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t1738 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1739 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1740 = _igen_dd_mm256_set_pd(_t1736, _t1737, _t1738, _t1739);
  dd_I _t1741 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1742 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t1743 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1744 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t1745 = _ia_neg_dd(_t1741);
  dd_I _t1746 = _ia_neg_dd(_t1742);
  dd_I _t1747 = _ia_neg_dd(_t1743);
  dd_I _t1748 = _ia_neg_dd(_t1744);
  ddi_4 _t1749 = _igen_dd_mm256_set_pd(_t1745, _t1746, _t1747, _t1748);
  ddi_4 _t1750 = _igen_dd_mm256_mul_pd(_t1740, s4692);
  ddi_4 _t1751 = _igen_dd_mm256_mul_pd(_t1749, s4696);
  s5039 = _igen_dd_mm256_add_pd(_t1750, _t1751);
  t4014 = _igen_dd_mm256_add_pd(s4690, s5038);
  t4015 = _igen_dd_mm256_add_pd(s4694, s5039);
  t4016 = _igen_dd_mm256_sub_pd(s4690, s5038);
  t4017 = _igen_dd_mm256_sub_pd(s4694, s5039);
  dd_I _t1752 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t1753 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1754 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1755 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1756 = _igen_dd_mm256_set_pd(_t1752, _t1753, _t1754, _t1755);
  dd_I _t1757 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t1758 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1759 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1760 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1761 = _igen_dd_mm256_set_pd(_t1757, _t1758, _t1759, _t1760);
  ddi_4 _t1762 = _igen_dd_mm256_mul_pd(_t1756, s4691);
  ddi_4 _t1763 = _igen_dd_mm256_mul_pd(_t1761, s4695);
  s5040 = _igen_dd_mm256_sub_pd(_t1762, _t1763);
  dd_I _t1764 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t1765 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1766 = _ia_set_dd(-0.84485356524970712, -3.1090684980154034e-18,
                           0.84485356524970712, 3.1090684980154038e-18);
  dd_I _t1767 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1768 = _igen_dd_mm256_set_pd(_t1764, _t1765, _t1766, _t1767);
  dd_I _t1769 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t1770 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1771 = _ia_set_dd(-0.53499761988709715, 3.3239071504794995e-18,
                           0.53499761988709715, -3.3239071504794991e-18);
  dd_I _t1772 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t1773 = _igen_dd_mm256_set_pd(_t1769, _t1770, _t1771, _t1772);
  ddi_4 _t1774 = _igen_dd_mm256_mul_pd(_t1768, s4691);
  ddi_4 _t1775 = _igen_dd_mm256_mul_pd(_t1773, s4695);
  s5041 = _igen_dd_mm256_add_pd(_t1774, _t1775);
  dd_I _t1776 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                           0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t1777 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1778 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t1779 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t1780 = _ia_neg_dd(_t1776);
  dd_I _t1781 = _ia_neg_dd(_t1777);
  dd_I _t1782 = _ia_neg_dd(_t1778);
  dd_I _t1783 = _ia_neg_dd(_t1779);
  ddi_4 _t1784 = _igen_dd_mm256_set_pd(_t1780, _t1781, _t1782, _t1783);
  dd_I _t1785 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                           0.024541228522912288, -1.236030195850617e-19);
  dd_I _t1786 = _ia_neg_dd(_t1785);
  dd_I _t1787 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1788 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t1789 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1790 = _igen_dd_mm256_set_pd(_t1786, _t1787, _t1788, _t1789);
  ddi_4 _t1791 = _igen_dd_mm256_mul_pd(_t1784, s4693);
  ddi_4 _t1792 = _igen_dd_mm256_mul_pd(_t1790, s4697);
  s5042 = _igen_dd_mm256_sub_pd(_t1791, _t1792);
  dd_I _t1793 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                           0.024541228522912288, -1.236030195850617e-19);
  dd_I _t1794 = _ia_neg_dd(_t1793);
  dd_I _t1795 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t1796 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t1797 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t1798 = _igen_dd_mm256_set_pd(_t1794, _t1795, _t1796, _t1797);
  dd_I _t1799 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                           0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t1800 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t1801 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t1802 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t1803 = _ia_neg_dd(_t1799);
  dd_I _t1804 = _ia_neg_dd(_t1800);
  dd_I _t1805 = _ia_neg_dd(_t1801);
  dd_I _t1806 = _ia_neg_dd(_t1802);
  ddi_4 _t1807 = _igen_dd_mm256_set_pd(_t1803, _t1804, _t1805, _t1806);
  ddi_4 _t1808 = _igen_dd_mm256_mul_pd(_t1798, s4693);
  ddi_4 _t1809 = _igen_dd_mm256_mul_pd(_t1807, s4697);
  s5043 = _igen_dd_mm256_add_pd(_t1808, _t1809);
  t4018 = _igen_dd_mm256_add_pd(s5040, s5042);
  t4019 = _igen_dd_mm256_add_pd(s5041, s5043);
  t4020 = _igen_dd_mm256_sub_pd(s5040, s5042);
  t4021 = _igen_dd_mm256_sub_pd(s5041, s5043);
  t4022 = _igen_dd_mm256_add_pd(t4014, t4018);
  t4023 = _igen_dd_mm256_add_pd(t4015, t4019);
  t4024 = _igen_dd_mm256_sub_pd(t4014, t4018);
  t4025 = _igen_dd_mm256_sub_pd(t4015, t4019);
  s5044 = _igen_dd_mm256_unpacklo_pd(t4022, t4023);
  s5045 = _igen_dd_mm256_unpackhi_pd(t4022, t4023);
  s5046 = _igen_dd_mm256_permute2f128_pd(s5044, s5045, (0) | ((2) << 4));
  *((a1309 + 20)) = s5046;
  s5047 = _igen_dd_mm256_permute2f128_pd(s5044, s5045, (1) | ((3) << 4));
  *((a1309 + 21)) = s5047;
  s5048 = _igen_dd_mm256_unpacklo_pd(t4024, t4025);
  s5049 = _igen_dd_mm256_unpackhi_pd(t4024, t4025);
  s5050 = _igen_dd_mm256_permute2f128_pd(s5048, s5049, (0) | ((2) << 4));
  *((a1309 + 84)) = s5050;
  s5051 = _igen_dd_mm256_permute2f128_pd(s5048, s5049, (1) | ((3) << 4));
  *((a1309 + 85)) = s5051;
  t4026 = _igen_dd_mm256_sub_pd(t4016, t4021);
  t4027 = _igen_dd_mm256_add_pd(t4017, t4020);
  t4028 = _igen_dd_mm256_add_pd(t4016, t4021);
  t4029 = _igen_dd_mm256_sub_pd(t4017, t4020);
  s5052 = _igen_dd_mm256_unpacklo_pd(t4026, t4027);
  s5053 = _igen_dd_mm256_unpackhi_pd(t4026, t4027);
  s5054 = _igen_dd_mm256_permute2f128_pd(s5052, s5053, (0) | ((2) << 4));
  *((a1309 + 52)) = s5054;
  s5055 = _igen_dd_mm256_permute2f128_pd(s5052, s5053, (1) | ((3) << 4));
  *((a1309 + 53)) = s5055;
  s5056 = _igen_dd_mm256_unpacklo_pd(t4028, t4029);
  s5057 = _igen_dd_mm256_unpackhi_pd(t4028, t4029);
  s5058 = _igen_dd_mm256_permute2f128_pd(s5056, s5057, (0) | ((2) << 4));
  *((a1309 + 116)) = s5058;
  s5059 = _igen_dd_mm256_permute2f128_pd(s5056, s5057, (1) | ((3) << 4));
  *((a1309 + 117)) = s5059;
  dd_I _t1810 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1811 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1812 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1813 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t1814 = _ia_neg_dd(_t1810);
  dd_I _t1815 = _ia_neg_dd(_t1811);
  dd_I _t1816 = _ia_neg_dd(_t1812);
  dd_I _t1817 = _ia_neg_dd(_t1813);
  ddi_4 _t1818 = _igen_dd_mm256_set_pd(_t1814, _t1815, _t1816, _t1817);
  dd_I _t1819 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1820 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1821 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1822 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1823 = _igen_dd_mm256_set_pd(_t1819, _t1820, _t1821, _t1822);
  ddi_4 _t1824 = _igen_dd_mm256_mul_pd(_t1818, s4716);
  ddi_4 _t1825 = _igen_dd_mm256_mul_pd(_t1823, s4720);
  s5060 = _igen_dd_mm256_sub_pd(_t1824, _t1825);
  dd_I _t1826 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1827 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1828 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1829 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t1830 = _igen_dd_mm256_set_pd(_t1826, _t1827, _t1828, _t1829);
  dd_I _t1831 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1832 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1833 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1834 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t1835 = _ia_neg_dd(_t1831);
  dd_I _t1836 = _ia_neg_dd(_t1832);
  dd_I _t1837 = _ia_neg_dd(_t1833);
  dd_I _t1838 = _ia_neg_dd(_t1834);
  ddi_4 _t1839 = _igen_dd_mm256_set_pd(_t1835, _t1836, _t1837, _t1838);
  ddi_4 _t1840 = _igen_dd_mm256_mul_pd(_t1830, s4716);
  ddi_4 _t1841 = _igen_dd_mm256_mul_pd(_t1839, s4720);
  s5061 = _igen_dd_mm256_add_pd(_t1840, _t1841);
  t4030 = _igen_dd_mm256_add_pd(s4714, s5060);
  t4031 = _igen_dd_mm256_add_pd(s4718, s5061);
  t4032 = _igen_dd_mm256_sub_pd(s4714, s5060);
  t4033 = _igen_dd_mm256_sub_pd(s4718, s5061);
  dd_I _t1842 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1843 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1844 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1845 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t1846 = _igen_dd_mm256_set_pd(_t1842, _t1843, _t1844, _t1845);
  dd_I _t1847 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1848 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1849 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1850 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t1851 = _igen_dd_mm256_set_pd(_t1847, _t1848, _t1849, _t1850);
  ddi_4 _t1852 = _igen_dd_mm256_mul_pd(_t1846, s4715);
  ddi_4 _t1853 = _igen_dd_mm256_mul_pd(_t1851, s4719);
  s5062 = _igen_dd_mm256_sub_pd(_t1852, _t1853);
  dd_I _t1854 = _ia_set_dd(-0.91420975570353069, 9.5119735720800237e-19,
                           0.91420975570353069, -9.5119735720800218e-19);
  dd_I _t1855 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t1856 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1857 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  ddi_4 _t1858 = _igen_dd_mm256_set_pd(_t1854, _t1855, _t1856, _t1857);
  dd_I _t1859 = _ia_set_dd(-0.40524131400498986, 9.9734111121506439e-19,
                           0.40524131400498986, -9.973411112150642e-19);
  dd_I _t1860 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t1861 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1862 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  ddi_4 _t1863 = _igen_dd_mm256_set_pd(_t1859, _t1860, _t1861, _t1862);
  ddi_4 _t1864 = _igen_dd_mm256_mul_pd(_t1858, s4715);
  ddi_4 _t1865 = _igen_dd_mm256_mul_pd(_t1863, s4719);
  s5063 = _igen_dd_mm256_add_pd(_t1864, _t1865);
  dd_I _t1866 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1867 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1868 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t1869 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t1870 = _ia_neg_dd(_t1866);
  dd_I _t1871 = _ia_neg_dd(_t1867);
  dd_I _t1872 = _ia_neg_dd(_t1868);
  dd_I _t1873 = _ia_neg_dd(_t1869);
  ddi_4 _t1874 = _igen_dd_mm256_set_pd(_t1870, _t1871, _t1872, _t1873);
  dd_I _t1875 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1876 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1877 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t1878 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t1879 = _ia_neg_dd(_t1875);
  dd_I _t1880 = _ia_neg_dd(_t1876);
  dd_I _t1881 = _ia_neg_dd(_t1877);
  dd_I _t1882 = _ia_neg_dd(_t1878);
  ddi_4 _t1883 = _igen_dd_mm256_set_pd(_t1879, _t1880, _t1881, _t1882);
  ddi_4 _t1884 = _igen_dd_mm256_mul_pd(_t1874, s4717);
  ddi_4 _t1885 = _igen_dd_mm256_mul_pd(_t1883, s4721);
  s5064 = _igen_dd_mm256_sub_pd(_t1884, _t1885);
  dd_I _t1886 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1887 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t1888 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t1889 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t1890 = _ia_neg_dd(_t1886);
  dd_I _t1891 = _ia_neg_dd(_t1887);
  dd_I _t1892 = _ia_neg_dd(_t1888);
  dd_I _t1893 = _ia_neg_dd(_t1889);
  ddi_4 _t1894 = _igen_dd_mm256_set_pd(_t1890, _t1891, _t1892, _t1893);
  dd_I _t1895 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1896 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t1897 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t1898 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t1899 = _ia_neg_dd(_t1895);
  dd_I _t1900 = _ia_neg_dd(_t1896);
  dd_I _t1901 = _ia_neg_dd(_t1897);
  dd_I _t1902 = _ia_neg_dd(_t1898);
  ddi_4 _t1903 = _igen_dd_mm256_set_pd(_t1899, _t1900, _t1901, _t1902);
  ddi_4 _t1904 = _igen_dd_mm256_mul_pd(_t1894, s4717);
  ddi_4 _t1905 = _igen_dd_mm256_mul_pd(_t1903, s4721);
  s5065 = _igen_dd_mm256_add_pd(_t1904, _t1905);
  t4034 = _igen_dd_mm256_add_pd(s5062, s5064);
  t4035 = _igen_dd_mm256_add_pd(s5063, s5065);
  t4036 = _igen_dd_mm256_sub_pd(s5062, s5064);
  t4037 = _igen_dd_mm256_sub_pd(s5063, s5065);
  t4038 = _igen_dd_mm256_add_pd(t4030, t4034);
  t4039 = _igen_dd_mm256_add_pd(t4031, t4035);
  t4040 = _igen_dd_mm256_sub_pd(t4030, t4034);
  t4041 = _igen_dd_mm256_sub_pd(t4031, t4035);
  s5066 = _igen_dd_mm256_unpacklo_pd(t4038, t4039);
  s5067 = _igen_dd_mm256_unpackhi_pd(t4038, t4039);
  s5068 = _igen_dd_mm256_permute2f128_pd(s5066, s5067, (0) | ((2) << 4));
  *((a1309 + 22)) = s5068;
  s5069 = _igen_dd_mm256_permute2f128_pd(s5066, s5067, (1) | ((3) << 4));
  *((a1309 + 23)) = s5069;
  s5070 = _igen_dd_mm256_unpacklo_pd(t4040, t4041);
  s5071 = _igen_dd_mm256_unpackhi_pd(t4040, t4041);
  s5072 = _igen_dd_mm256_permute2f128_pd(s5070, s5071, (0) | ((2) << 4));
  *((a1309 + 86)) = s5072;
  s5073 = _igen_dd_mm256_permute2f128_pd(s5070, s5071, (1) | ((3) << 4));
  *((a1309 + 87)) = s5073;
  t4042 = _igen_dd_mm256_sub_pd(t4032, t4037);
  t4043 = _igen_dd_mm256_add_pd(t4033, t4036);
  t4044 = _igen_dd_mm256_add_pd(t4032, t4037);
  t4045 = _igen_dd_mm256_sub_pd(t4033, t4036);
  s5074 = _igen_dd_mm256_unpacklo_pd(t4042, t4043);
  s5075 = _igen_dd_mm256_unpackhi_pd(t4042, t4043);
  s5076 = _igen_dd_mm256_permute2f128_pd(s5074, s5075, (0) | ((2) << 4));
  *((a1309 + 54)) = s5076;
  s5077 = _igen_dd_mm256_permute2f128_pd(s5074, s5075, (1) | ((3) << 4));
  *((a1309 + 55)) = s5077;
  s5078 = _igen_dd_mm256_unpacklo_pd(t4044, t4045);
  s5079 = _igen_dd_mm256_unpackhi_pd(t4044, t4045);
  s5080 = _igen_dd_mm256_permute2f128_pd(s5078, s5079, (0) | ((2) << 4));
  *((a1309 + 118)) = s5080;
  s5081 = _igen_dd_mm256_permute2f128_pd(s5078, s5079, (1) | ((3) << 4));
  *((a1309 + 119)) = s5081;
  dd_I _t1906 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1907 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1908 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1909 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  dd_I _t1910 = _ia_neg_dd(_t1906);
  dd_I _t1911 = _ia_neg_dd(_t1907);
  dd_I _t1912 = _ia_neg_dd(_t1908);
  dd_I _t1913 = _ia_neg_dd(_t1909);
  ddi_4 _t1914 = _igen_dd_mm256_set_pd(_t1910, _t1911, _t1912, _t1913);
  dd_I _t1915 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1916 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1917 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1918 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1919 = _igen_dd_mm256_set_pd(_t1915, _t1916, _t1917, _t1918);
  ddi_4 _t1920 = _igen_dd_mm256_mul_pd(_t1914, s4740);
  ddi_4 _t1921 = _igen_dd_mm256_mul_pd(_t1919, s4744);
  s5082 = _igen_dd_mm256_sub_pd(_t1920, _t1921);
  dd_I _t1922 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                           0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t1923 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t1924 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t1925 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t1926 = _igen_dd_mm256_set_pd(_t1922, _t1923, _t1924, _t1925);
  dd_I _t1927 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                           0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t1928 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t1929 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t1930 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                           0.70710678118654757, -2.737310929369414e-18);
  dd_I _t1931 = _ia_neg_dd(_t1927);
  dd_I _t1932 = _ia_neg_dd(_t1928);
  dd_I _t1933 = _ia_neg_dd(_t1929);
  dd_I _t1934 = _ia_neg_dd(_t1930);
  ddi_4 _t1935 = _igen_dd_mm256_set_pd(_t1931, _t1932, _t1933, _t1934);
  ddi_4 _t1936 = _igen_dd_mm256_mul_pd(_t1926, s4740);
  ddi_4 _t1937 = _igen_dd_mm256_mul_pd(_t1935, s4744);
  s5083 = _igen_dd_mm256_add_pd(_t1936, _t1937);
  t4046 = _igen_dd_mm256_add_pd(s4738, s5082);
  t4047 = _igen_dd_mm256_add_pd(s4742, s5083);
  t4048 = _igen_dd_mm256_sub_pd(s4738, s5082);
  t4049 = _igen_dd_mm256_sub_pd(s4742, s5083);
  dd_I _t1938 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1939 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1940 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t1941 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1942 = _igen_dd_mm256_set_pd(_t1938, _t1939, _t1940, _t1941);
  dd_I _t1943 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1944 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1945 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t1946 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1947 = _igen_dd_mm256_set_pd(_t1943, _t1944, _t1945, _t1946);
  ddi_4 _t1948 = _igen_dd_mm256_mul_pd(_t1942, s4739);
  ddi_4 _t1949 = _igen_dd_mm256_mul_pd(_t1947, s4743);
  s5084 = _igen_dd_mm256_sub_pd(_t1948, _t1949);
  dd_I _t1950 = _ia_set_dd(-0.94952818059303667, 4.7503512669936756e-18,
                           0.94952818059303667, -4.7503512669936748e-18);
  dd_I _t1951 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t1952 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t1953 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t1954 = _igen_dd_mm256_set_pd(_t1950, _t1951, _t1952, _t1953);
  dd_I _t1955 = _ia_set_dd(-0.31368174039889152, -2.392817222716985e-18,
                           0.31368174039889152, 2.3928172227169853e-18);
  dd_I _t1956 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t1957 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t1958 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t1959 = _igen_dd_mm256_set_pd(_t1955, _t1956, _t1957, _t1958);
  ddi_4 _t1960 = _igen_dd_mm256_mul_pd(_t1954, s4739);
  ddi_4 _t1961 = _igen_dd_mm256_mul_pd(_t1959, s4743);
  s5085 = _igen_dd_mm256_add_pd(_t1960, _t1961);
  dd_I _t1962 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1963 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1964 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1965 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t1966 = _ia_neg_dd(_t1962);
  dd_I _t1967 = _ia_neg_dd(_t1963);
  dd_I _t1968 = _ia_neg_dd(_t1964);
  dd_I _t1969 = _ia_neg_dd(_t1965);
  ddi_4 _t1970 = _igen_dd_mm256_set_pd(_t1966, _t1967, _t1968, _t1969);
  dd_I _t1971 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1972 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1973 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1974 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t1975 = _ia_neg_dd(_t1971);
  dd_I _t1976 = _ia_neg_dd(_t1972);
  dd_I _t1977 = _ia_neg_dd(_t1973);
  dd_I _t1978 = _ia_neg_dd(_t1974);
  ddi_4 _t1979 = _igen_dd_mm256_set_pd(_t1975, _t1976, _t1977, _t1978);
  ddi_4 _t1980 = _igen_dd_mm256_mul_pd(_t1970, s4741);
  ddi_4 _t1981 = _igen_dd_mm256_mul_pd(_t1979, s4745);
  s5086 = _igen_dd_mm256_sub_pd(_t1980, _t1981);
  dd_I _t1982 = _ia_set_dd(-0.57580819141784534, -1.3445320872415321e-18,
                           0.57580819141784534, 1.3445320872415323e-18);
  dd_I _t1983 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t1984 = _ia_set_dd(-0.4496113296546066, -4.8368978437792975e-18,
                           0.4496113296546066, 4.8368978437792983e-18);
  dd_I _t1985 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t1986 = _ia_neg_dd(_t1982);
  dd_I _t1987 = _ia_neg_dd(_t1983);
  dd_I _t1988 = _ia_neg_dd(_t1984);
  dd_I _t1989 = _ia_neg_dd(_t1985);
  ddi_4 _t1990 = _igen_dd_mm256_set_pd(_t1986, _t1987, _t1988, _t1989);
  dd_I _t1991 = _ia_set_dd(-0.81758481315158371, 1.3880706965574064e-18,
                           0.81758481315158371, -1.3880706965574062e-18);
  dd_I _t1992 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t1993 = _ia_set_dd(-0.89322430119551532, 4.4585403626842896e-18,
                           0.89322430119551532, -4.4585403626842888e-18);
  dd_I _t1994 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t1995 = _ia_neg_dd(_t1991);
  dd_I _t1996 = _ia_neg_dd(_t1992);
  dd_I _t1997 = _ia_neg_dd(_t1993);
  dd_I _t1998 = _ia_neg_dd(_t1994);
  ddi_4 _t1999 = _igen_dd_mm256_set_pd(_t1995, _t1996, _t1997, _t1998);
  ddi_4 _t2000 = _igen_dd_mm256_mul_pd(_t1990, s4741);
  ddi_4 _t2001 = _igen_dd_mm256_mul_pd(_t1999, s4745);
  s5087 = _igen_dd_mm256_add_pd(_t2000, _t2001);
  t4050 = _igen_dd_mm256_add_pd(s5084, s5086);
  t4051 = _igen_dd_mm256_add_pd(s5085, s5087);
  t4052 = _igen_dd_mm256_sub_pd(s5084, s5086);
  t4053 = _igen_dd_mm256_sub_pd(s5085, s5087);
  t4054 = _igen_dd_mm256_add_pd(t4046, t4050);
  t4055 = _igen_dd_mm256_add_pd(t4047, t4051);
  t4056 = _igen_dd_mm256_sub_pd(t4046, t4050);
  t4057 = _igen_dd_mm256_sub_pd(t4047, t4051);
  s5088 = _igen_dd_mm256_unpacklo_pd(t4054, t4055);
  s5089 = _igen_dd_mm256_unpackhi_pd(t4054, t4055);
  s5090 = _igen_dd_mm256_permute2f128_pd(s5088, s5089, (0) | ((2) << 4));
  *((a1309 + 24)) = s5090;
  s5091 = _igen_dd_mm256_permute2f128_pd(s5088, s5089, (1) | ((3) << 4));
  *((a1309 + 25)) = s5091;
  s5092 = _igen_dd_mm256_unpacklo_pd(t4056, t4057);
  s5093 = _igen_dd_mm256_unpackhi_pd(t4056, t4057);
  s5094 = _igen_dd_mm256_permute2f128_pd(s5092, s5093, (0) | ((2) << 4));
  *((a1309 + 88)) = s5094;
  s5095 = _igen_dd_mm256_permute2f128_pd(s5092, s5093, (1) | ((3) << 4));
  *((a1309 + 89)) = s5095;
  t4058 = _igen_dd_mm256_sub_pd(t4048, t4053);
  t4059 = _igen_dd_mm256_add_pd(t4049, t4052);
  t4060 = _igen_dd_mm256_add_pd(t4048, t4053);
  t4061 = _igen_dd_mm256_sub_pd(t4049, t4052);
  s5096 = _igen_dd_mm256_unpacklo_pd(t4058, t4059);
  s5097 = _igen_dd_mm256_unpackhi_pd(t4058, t4059);
  s5098 = _igen_dd_mm256_permute2f128_pd(s5096, s5097, (0) | ((2) << 4));
  *((a1309 + 56)) = s5098;
  s5099 = _igen_dd_mm256_permute2f128_pd(s5096, s5097, (1) | ((3) << 4));
  *((a1309 + 57)) = s5099;
  s5100 = _igen_dd_mm256_unpacklo_pd(t4060, t4061);
  s5101 = _igen_dd_mm256_unpackhi_pd(t4060, t4061);
  s5102 = _igen_dd_mm256_permute2f128_pd(s5100, s5101, (0) | ((2) << 4));
  *((a1309 + 120)) = s5102;
  s5103 = _igen_dd_mm256_permute2f128_pd(s5100, s5101, (1) | ((3) << 4));
  *((a1309 + 121)) = s5103;
  dd_I _t2002 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t2003 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t2004 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t2005 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t2006 = _ia_neg_dd(_t2002);
  dd_I _t2007 = _ia_neg_dd(_t2003);
  dd_I _t2008 = _ia_neg_dd(_t2004);
  dd_I _t2009 = _ia_neg_dd(_t2005);
  ddi_4 _t2010 = _igen_dd_mm256_set_pd(_t2006, _t2007, _t2008, _t2009);
  dd_I _t2011 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t2012 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t2013 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t2014 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t2015 = _igen_dd_mm256_set_pd(_t2011, _t2012, _t2013, _t2014);
  ddi_4 _t2016 = _igen_dd_mm256_mul_pd(_t2010, s4764);
  ddi_4 _t2017 = _igen_dd_mm256_mul_pd(_t2015, s4768);
  s5104 = _igen_dd_mm256_sub_pd(_t2016, _t2017);
  dd_I _t2018 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t2019 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                           0.47139673682599764, -2.039709489836241e-18);
  dd_I _t2020 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                           0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t2021 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t2022 = _igen_dd_mm256_set_pd(_t2018, _t2019, _t2020, _t2021);
  dd_I _t2023 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t2024 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                           0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t2025 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                           0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t2026 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t2027 = _ia_neg_dd(_t2023);
  dd_I _t2028 = _ia_neg_dd(_t2024);
  dd_I _t2029 = _ia_neg_dd(_t2025);
  dd_I _t2030 = _ia_neg_dd(_t2026);
  ddi_4 _t2031 = _igen_dd_mm256_set_pd(_t2027, _t2028, _t2029, _t2030);
  ddi_4 _t2032 = _igen_dd_mm256_mul_pd(_t2022, s4764);
  ddi_4 _t2033 = _igen_dd_mm256_mul_pd(_t2031, s4768);
  s5105 = _igen_dd_mm256_add_pd(_t2032, _t2033);
  t4062 = _igen_dd_mm256_add_pd(s4762, s5104);
  t4063 = _igen_dd_mm256_add_pd(s4766, s5105);
  t4064 = _igen_dd_mm256_sub_pd(s4762, s5104);
  t4065 = _igen_dd_mm256_sub_pd(s4766, s5105);
  dd_I _t2034 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t2035 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t2036 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t2037 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t2038 = _igen_dd_mm256_set_pd(_t2034, _t2035, _t2036, _t2037);
  dd_I _t2039 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                           0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t2040 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t2041 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t2042 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t2043 = _igen_dd_mm256_set_pd(_t2039, _t2040, _t2041, _t2042);
  ddi_4 _t2044 = _igen_dd_mm256_mul_pd(_t2038, s4763);
  ddi_4 _t2045 = _igen_dd_mm256_mul_pd(_t2043, s4767);
  s5106 = _igen_dd_mm256_sub_pd(_t2044, _t2045);
  dd_I _t2046 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                           0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t2047 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t2048 = _ia_set_dd(-0.96377606579543984, 2.2251379428780639e-19,
                           0.96377606579543984, -2.2251379428780634e-19);
  dd_I _t2049 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  ddi_4 _t2050 = _igen_dd_mm256_set_pd(_t2046, _t2047, _t2048, _t2049);
  dd_I _t2051 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t2052 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t2053 = _ia_set_dd(-0.26671275747489842, 8.9521516754757615e-19,
                           0.26671275747489842, -8.9521516754757595e-19);
  dd_I _t2054 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  ddi_4 _t2055 = _igen_dd_mm256_set_pd(_t2051, _t2052, _t2053, _t2054);
  ddi_4 _t2056 = _igen_dd_mm256_mul_pd(_t2050, s4763);
  ddi_4 _t2057 = _igen_dd_mm256_mul_pd(_t2055, s4767);
  s5107 = _igen_dd_mm256_add_pd(_t2056, _t2057);
  dd_I _t2058 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t2059 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t2060 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t2061 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t2062 = _ia_neg_dd(_t2058);
  dd_I _t2063 = _ia_neg_dd(_t2059);
  dd_I _t2064 = _ia_neg_dd(_t2060);
  dd_I _t2065 = _ia_neg_dd(_t2061);
  ddi_4 _t2066 = _igen_dd_mm256_set_pd(_t2062, _t2063, _t2064, _t2065);
  dd_I _t2067 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t2068 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t2069 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t2070 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t2071 = _ia_neg_dd(_t2067);
  dd_I _t2072 = _ia_neg_dd(_t2068);
  dd_I _t2073 = _ia_neg_dd(_t2069);
  dd_I _t2074 = _ia_neg_dd(_t2070);
  ddi_4 _t2075 = _igen_dd_mm256_set_pd(_t2071, _t2072, _t2073, _t2074);
  ddi_4 _t2076 = _igen_dd_mm256_mul_pd(_t2066, s4765);
  ddi_4 _t2077 = _igen_dd_mm256_mul_pd(_t2075, s4769);
  s5108 = _igen_dd_mm256_sub_pd(_t2076, _t2077);
  dd_I _t2078 = _ia_set_dd(-0.78834642762660634, -1.365525986184366e-18,
                           0.78834642762660634, 1.3655259861843662e-18);
  dd_I _t2079 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                           0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t2080 = _ia_set_dd(-0.68954054473706694, 5.0605392476427373e-19,
                           0.68954054473706694, -5.0605392476427363e-19);
  dd_I _t2081 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                           0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t2082 = _ia_neg_dd(_t2078);
  dd_I _t2083 = _ia_neg_dd(_t2079);
  dd_I _t2084 = _ia_neg_dd(_t2080);
  dd_I _t2085 = _ia_neg_dd(_t2081);
  ddi_4 _t2086 = _igen_dd_mm256_set_pd(_t2082, _t2083, _t2084, _t2085);
  dd_I _t2087 = _ia_set_dd(-0.61523159058062682, -7.4650420385296447e-19,
                           0.61523159058062682, 7.4650420385296457e-19);
  dd_I _t2088 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                           0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t2089 = _ia_set_dd(-0.72424708295146689, 1.7425979088875466e-18,
                           0.72424708295146689, -1.7425979088875462e-18);
  dd_I _t2090 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                           0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t2091 = _ia_neg_dd(_t2087);
  dd_I _t2092 = _ia_neg_dd(_t2088);
  dd_I _t2093 = _ia_neg_dd(_t2089);
  dd_I _t2094 = _ia_neg_dd(_t2090);
  ddi_4 _t2095 = _igen_dd_mm256_set_pd(_t2091, _t2092, _t2093, _t2094);
  ddi_4 _t2096 = _igen_dd_mm256_mul_pd(_t2086, s4765);
  ddi_4 _t2097 = _igen_dd_mm256_mul_pd(_t2095, s4769);
  s5109 = _igen_dd_mm256_add_pd(_t2096, _t2097);
  t4066 = _igen_dd_mm256_add_pd(s5106, s5108);
  t4067 = _igen_dd_mm256_add_pd(s5107, s5109);
  t4068 = _igen_dd_mm256_sub_pd(s5106, s5108);
  t4069 = _igen_dd_mm256_sub_pd(s5107, s5109);
  t4070 = _igen_dd_mm256_add_pd(t4062, t4066);
  t4071 = _igen_dd_mm256_add_pd(t4063, t4067);
  t4072 = _igen_dd_mm256_sub_pd(t4062, t4066);
  t4073 = _igen_dd_mm256_sub_pd(t4063, t4067);
  s5110 = _igen_dd_mm256_unpacklo_pd(t4070, t4071);
  s5111 = _igen_dd_mm256_unpackhi_pd(t4070, t4071);
  s5112 = _igen_dd_mm256_permute2f128_pd(s5110, s5111, (0) | ((2) << 4));
  *((a1309 + 26)) = s5112;
  s5113 = _igen_dd_mm256_permute2f128_pd(s5110, s5111, (1) | ((3) << 4));
  *((a1309 + 27)) = s5113;
  s5114 = _igen_dd_mm256_unpacklo_pd(t4072, t4073);
  s5115 = _igen_dd_mm256_unpackhi_pd(t4072, t4073);
  s5116 = _igen_dd_mm256_permute2f128_pd(s5114, s5115, (0) | ((2) << 4));
  *((a1309 + 90)) = s5116;
  s5117 = _igen_dd_mm256_permute2f128_pd(s5114, s5115, (1) | ((3) << 4));
  *((a1309 + 91)) = s5117;
  t4074 = _igen_dd_mm256_sub_pd(t4064, t4069);
  t4075 = _igen_dd_mm256_add_pd(t4065, t4068);
  t4076 = _igen_dd_mm256_add_pd(t4064, t4069);
  t4077 = _igen_dd_mm256_sub_pd(t4065, t4068);
  s5118 = _igen_dd_mm256_unpacklo_pd(t4074, t4075);
  s5119 = _igen_dd_mm256_unpackhi_pd(t4074, t4075);
  s5120 = _igen_dd_mm256_permute2f128_pd(s5118, s5119, (0) | ((2) << 4));
  *((a1309 + 58)) = s5120;
  s5121 = _igen_dd_mm256_permute2f128_pd(s5118, s5119, (1) | ((3) << 4));
  *((a1309 + 59)) = s5121;
  s5122 = _igen_dd_mm256_unpacklo_pd(t4076, t4077);
  s5123 = _igen_dd_mm256_unpackhi_pd(t4076, t4077);
  s5124 = _igen_dd_mm256_permute2f128_pd(s5122, s5123, (0) | ((2) << 4));
  *((a1309 + 122)) = s5124;
  s5125 = _igen_dd_mm256_permute2f128_pd(s5122, s5123, (1) | ((3) << 4));
  *((a1309 + 123)) = s5125;
  dd_I _t2098 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t2099 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t2100 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t2101 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t2102 = _ia_neg_dd(_t2098);
  dd_I _t2103 = _ia_neg_dd(_t2099);
  dd_I _t2104 = _ia_neg_dd(_t2100);
  dd_I _t2105 = _ia_neg_dd(_t2101);
  ddi_4 _t2106 = _igen_dd_mm256_set_pd(_t2102, _t2103, _t2104, _t2105);
  dd_I _t2107 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t2108 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t2109 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t2110 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t2111 = _igen_dd_mm256_set_pd(_t2107, _t2108, _t2109, _t2110);
  ddi_4 _t2112 = _igen_dd_mm256_mul_pd(_t2106, s4788);
  ddi_4 _t2113 = _igen_dd_mm256_mul_pd(_t2111, s4792);
  s5126 = _igen_dd_mm256_sub_pd(_t2112, _t2113);
  dd_I _t2114 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                           0.24298017990326387, -9.441300761682213e-19);
  dd_I _t2115 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t2116 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                           0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t2117 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                           0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t2118 = _igen_dd_mm256_set_pd(_t2114, _t2115, _t2116, _t2117);
  dd_I _t2119 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                           0.97003125319454397, -4.238683858857257e-18);
  dd_I _t2120 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t2121 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                           0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t2122 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                           0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t2123 = _ia_neg_dd(_t2119);
  dd_I _t2124 = _ia_neg_dd(_t2120);
  dd_I _t2125 = _ia_neg_dd(_t2121);
  dd_I _t2126 = _ia_neg_dd(_t2122);
  ddi_4 _t2127 = _igen_dd_mm256_set_pd(_t2123, _t2124, _t2125, _t2126);
  ddi_4 _t2128 = _igen_dd_mm256_mul_pd(_t2118, s4788);
  ddi_4 _t2129 = _igen_dd_mm256_mul_pd(_t2127, s4792);
  s5127 = _igen_dd_mm256_add_pd(_t2128, _t2129);
  t4078 = _igen_dd_mm256_add_pd(s4786, s5126);
  t4079 = _igen_dd_mm256_add_pd(s4790, s5127);
  t4080 = _igen_dd_mm256_sub_pd(s4786, s5126);
  t4081 = _igen_dd_mm256_sub_pd(s4790, s5127);
  dd_I _t2130 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t2131 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t2132 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t2133 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t2134 = _igen_dd_mm256_set_pd(_t2130, _t2131, _t2132, _t2133);
  dd_I _t2135 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t2136 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t2137 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t2138 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t2139 = _igen_dd_mm256_set_pd(_t2135, _t2136, _t2137, _t2138);
  ddi_4 _t2140 = _igen_dd_mm256_mul_pd(_t2134, s4787);
  ddi_4 _t2141 = _igen_dd_mm256_mul_pd(_t2139, s4791);
  s5128 = _igen_dd_mm256_sub_pd(_t2140, _t2141);
  dd_I _t2142 = _ia_set_dd(-0.99247953459870997, -2.9362878437677864e-18,
                           0.99247953459870997, 2.9362878437677868e-18);
  dd_I _t2143 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t2144 = _ia_set_dd(-0.98527764238894122, 1.618381405278342e-18,
                           0.98527764238894122, -1.6183814052783418e-18);
  dd_I _t2145 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t2146 = _igen_dd_mm256_set_pd(_t2142, _t2143, _t2144, _t2145);
  dd_I _t2147 = _ia_set_dd(-0.1224106751992162, -4.3367456748455873e-18,
                           0.1224106751992162, 4.3367456748455881e-18);
  dd_I _t2148 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t2149 = _ia_set_dd(-0.17096188876030122, -2.8283556609676452e-18,
                           0.17096188876030122, 2.8283556609676456e-18);
  dd_I _t2150 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t2151 = _igen_dd_mm256_set_pd(_t2147, _t2148, _t2149, _t2150);
  ddi_4 _t2152 = _igen_dd_mm256_mul_pd(_t2146, s4787);
  ddi_4 _t2153 = _igen_dd_mm256_mul_pd(_t2151, s4791);
  s5129 = _igen_dd_mm256_add_pd(_t2152, _t2153);
  dd_I _t2154 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t2155 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t2156 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t2157 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t2158 = _ia_neg_dd(_t2154);
  dd_I _t2159 = _ia_neg_dd(_t2155);
  dd_I _t2160 = _ia_neg_dd(_t2156);
  dd_I _t2161 = _ia_neg_dd(_t2157);
  ddi_4 _t2162 = _igen_dd_mm256_set_pd(_t2158, _t2159, _t2160, _t2161);
  dd_I _t2163 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t2164 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t2165 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t2166 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t2167 = _ia_neg_dd(_t2163);
  dd_I _t2168 = _ia_neg_dd(_t2164);
  dd_I _t2169 = _ia_neg_dd(_t2165);
  dd_I _t2170 = _ia_neg_dd(_t2166);
  ddi_4 _t2171 = _igen_dd_mm256_set_pd(_t2167, _t2168, _t2169, _t2170);
  ddi_4 _t2172 = _igen_dd_mm256_mul_pd(_t2162, s4789);
  ddi_4 _t2173 = _igen_dd_mm256_mul_pd(_t2171, s4793);
  s5130 = _igen_dd_mm256_sub_pd(_t2172, _t2173);
  dd_I _t2174 = _ia_set_dd(-0.93299279883473885, -4.3297552998410537e-18,
                           0.93299279883473885, 4.3297552998410545e-18);
  dd_I _t2175 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                           0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t2176 = _ia_set_dd(-0.87008699110871146, 5.4080327303381639e-19,
                           0.87008699110871146, -5.4080327303381629e-19);
  dd_I _t2177 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                           0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t2178 = _ia_neg_dd(_t2174);
  dd_I _t2179 = _ia_neg_dd(_t2175);
  dd_I _t2180 = _ia_neg_dd(_t2176);
  dd_I _t2181 = _ia_neg_dd(_t2177);
  ddi_4 _t2182 = _igen_dd_mm256_set_pd(_t2178, _t2179, _t2180, _t2181);
  dd_I _t2183 = _ia_set_dd(-0.35989503653498817, -3.6232083038339624e-18,
                           0.35989503653498817, 3.6232083038339631e-18);
  dd_I _t2184 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                           0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t2185 = _ia_set_dd(-0.49289819222978404, -2.1011901435849721e-18,
                           0.49289819222978404, 2.1011901435849725e-18);
  dd_I _t2186 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                           0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t2187 = _ia_neg_dd(_t2183);
  dd_I _t2188 = _ia_neg_dd(_t2184);
  dd_I _t2189 = _ia_neg_dd(_t2185);
  dd_I _t2190 = _ia_neg_dd(_t2186);
  ddi_4 _t2191 = _igen_dd_mm256_set_pd(_t2187, _t2188, _t2189, _t2190);
  ddi_4 _t2192 = _igen_dd_mm256_mul_pd(_t2182, s4789);
  ddi_4 _t2193 = _igen_dd_mm256_mul_pd(_t2191, s4793);
  s5131 = _igen_dd_mm256_add_pd(_t2192, _t2193);
  t4082 = _igen_dd_mm256_add_pd(s5128, s5130);
  t4083 = _igen_dd_mm256_add_pd(s5129, s5131);
  t4084 = _igen_dd_mm256_sub_pd(s5128, s5130);
  t4085 = _igen_dd_mm256_sub_pd(s5129, s5131);
  t4086 = _igen_dd_mm256_add_pd(t4078, t4082);
  t4087 = _igen_dd_mm256_add_pd(t4079, t4083);
  t4088 = _igen_dd_mm256_sub_pd(t4078, t4082);
  t4089 = _igen_dd_mm256_sub_pd(t4079, t4083);
  s5132 = _igen_dd_mm256_unpacklo_pd(t4086, t4087);
  s5133 = _igen_dd_mm256_unpackhi_pd(t4086, t4087);
  s5134 = _igen_dd_mm256_permute2f128_pd(s5132, s5133, (0) | ((2) << 4));
  *((a1309 + 28)) = s5134;
  s5135 = _igen_dd_mm256_permute2f128_pd(s5132, s5133, (1) | ((3) << 4));
  *((a1309 + 29)) = s5135;
  s5136 = _igen_dd_mm256_unpacklo_pd(t4088, t4089);
  s5137 = _igen_dd_mm256_unpackhi_pd(t4088, t4089);
  s5138 = _igen_dd_mm256_permute2f128_pd(s5136, s5137, (0) | ((2) << 4));
  *((a1309 + 92)) = s5138;
  s5139 = _igen_dd_mm256_permute2f128_pd(s5136, s5137, (1) | ((3) << 4));
  *((a1309 + 93)) = s5139;
  t4090 = _igen_dd_mm256_sub_pd(t4080, t4085);
  t4091 = _igen_dd_mm256_add_pd(t4081, t4084);
  t4092 = _igen_dd_mm256_add_pd(t4080, t4085);
  t4093 = _igen_dd_mm256_sub_pd(t4081, t4084);
  s5140 = _igen_dd_mm256_unpacklo_pd(t4090, t4091);
  s5141 = _igen_dd_mm256_unpackhi_pd(t4090, t4091);
  s5142 = _igen_dd_mm256_permute2f128_pd(s5140, s5141, (0) | ((2) << 4));
  *((a1309 + 60)) = s5142;
  s5143 = _igen_dd_mm256_permute2f128_pd(s5140, s5141, (1) | ((3) << 4));
  *((a1309 + 61)) = s5143;
  s5144 = _igen_dd_mm256_unpacklo_pd(t4092, t4093);
  s5145 = _igen_dd_mm256_unpackhi_pd(t4092, t4093);
  s5146 = _igen_dd_mm256_permute2f128_pd(s5144, s5145, (0) | ((2) << 4));
  *((a1309 + 124)) = s5146;
  s5147 = _igen_dd_mm256_permute2f128_pd(s5144, s5145, (1) | ((3) << 4));
  *((a1309 + 125)) = s5147;
  dd_I _t2194 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t2195 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t2196 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t2197 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t2198 = _ia_neg_dd(_t2194);
  dd_I _t2199 = _ia_neg_dd(_t2195);
  dd_I _t2200 = _ia_neg_dd(_t2196);
  dd_I _t2201 = _ia_neg_dd(_t2197);
  ddi_4 _t2202 = _igen_dd_mm256_set_pd(_t2198, _t2199, _t2200, _t2201);
  dd_I _t2203 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t2204 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t2205 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t2206 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t2207 = _igen_dd_mm256_set_pd(_t2203, _t2204, _t2205, _t2206);
  ddi_4 _t2208 = _igen_dd_mm256_mul_pd(_t2202, s4812);
  ddi_4 _t2209 = _igen_dd_mm256_mul_pd(_t2207, s4816);
  s5148 = _igen_dd_mm256_sub_pd(_t2208, _t2209);
  dd_I _t2210 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t2211 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t2212 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t2213 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                           0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t2214 = _igen_dd_mm256_set_pd(_t2210, _t2211, _t2212, _t2213);
  dd_I _t2215 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t2216 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  dd_I _t2217 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t2218 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                           0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t2219 = _ia_neg_dd(_t2215);
  dd_I _t2220 = _ia_neg_dd(_t2216);
  dd_I _t2221 = _ia_neg_dd(_t2217);
  dd_I _t2222 = _ia_neg_dd(_t2218);
  ddi_4 _t2223 = _igen_dd_mm256_set_pd(_t2219, _t2220, _t2221, _t2222);
  ddi_4 _t2224 = _igen_dd_mm256_mul_pd(_t2214, s4812);
  ddi_4 _t2225 = _igen_dd_mm256_mul_pd(_t2223, s4816);
  s5149 = _igen_dd_mm256_add_pd(_t2224, _t2225);
  t4094 = _igen_dd_mm256_add_pd(s4810, s5148);
  t4095 = _igen_dd_mm256_add_pd(s4814, s5149);
  t4096 = _igen_dd_mm256_sub_pd(s4810, s5148);
  t4097 = _igen_dd_mm256_sub_pd(s4814, s5149);
  dd_I _t2226 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                           0.024541228522912288, -1.236030195850617e-19);
  dd_I _t2227 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t2228 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                           0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t2229 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t2230 = _igen_dd_mm256_set_pd(_t2226, _t2227, _t2228, _t2229);
  dd_I _t2231 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                           0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t2232 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t2233 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                           0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t2234 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t2235 = _igen_dd_mm256_set_pd(_t2231, _t2232, _t2233, _t2234);
  ddi_4 _t2236 = _igen_dd_mm256_mul_pd(_t2230, s4811);
  ddi_4 _t2237 = _igen_dd_mm256_mul_pd(_t2235, s4815);
  s5150 = _igen_dd_mm256_sub_pd(_t2236, _t2237);
  dd_I _t2238 = _ia_set_dd(-0.99969881869620425, -3.2747946534072979e-20,
                           0.99969881869620425, 3.2747946534072985e-20);
  dd_I _t2239 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                           0.99879545620517241, 4.993535058165435e-18);
  dd_I _t2240 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                           0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t2241 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                           0.99518472667219693, 1.268249368586112e-18);
  ddi_4 _t2242 = _igen_dd_mm256_set_pd(_t2238, _t2239, _t2240, _t2241);
  dd_I _t2243 = _ia_set_dd(-0.024541228522912288, 1.2360301958506172e-19,
                           0.024541228522912288, -1.236030195850617e-19);
  dd_I _t2244 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                           0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t2245 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                           0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t2246 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                           0.098017140329560604, 3.7122207386710215e-19);
  ddi_4 _t2247 = _igen_dd_mm256_set_pd(_t2243, _t2244, _t2245, _t2246);
  ddi_4 _t2248 = _igen_dd_mm256_mul_pd(_t2242, s4811);
  ddi_4 _t2249 = _igen_dd_mm256_mul_pd(_t2247, s4815);
  s5151 = _igen_dd_mm256_add_pd(_t2248, _t2249);
  dd_I _t2250 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                           0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t2251 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t2252 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t2253 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t2254 = _ia_neg_dd(_t2250);
  dd_I _t2255 = _ia_neg_dd(_t2251);
  dd_I _t2256 = _ia_neg_dd(_t2252);
  dd_I _t2257 = _ia_neg_dd(_t2253);
  ddi_4 _t2258 = _igen_dd_mm256_set_pd(_t2254, _t2255, _t2256, _t2257);
  dd_I _t2259 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                           0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t2260 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t2261 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                           0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t2262 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t2263 = _ia_neg_dd(_t2259);
  dd_I _t2264 = _ia_neg_dd(_t2260);
  dd_I _t2265 = _ia_neg_dd(_t2261);
  dd_I _t2266 = _ia_neg_dd(_t2262);
  ddi_4 _t2267 = _igen_dd_mm256_set_pd(_t2263, _t2264, _t2265, _t2266);
  ddi_4 _t2268 = _igen_dd_mm256_mul_pd(_t2258, s4813);
  ddi_4 _t2269 = _igen_dd_mm256_mul_pd(_t2267, s4817);
  s5152 = _igen_dd_mm256_sub_pd(_t2268, _t2269);
  dd_I _t2270 = _ia_set_dd(-0.99729045667869021, -3.0291723969276063e-18,
                           0.99729045667869021, 3.0291723969276067e-18);
  dd_I _t2271 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                           0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t2272 = _ia_set_dd(-0.97570213003852857, 3.2951847679214553e-20,
                           0.97570213003852857, -3.2951847679214547e-20);
  dd_I _t2273 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                           0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t2274 = _ia_neg_dd(_t2270);
  dd_I _t2275 = _ia_neg_dd(_t2271);
  dd_I _t2276 = _ia_neg_dd(_t2272);
  dd_I _t2277 = _ia_neg_dd(_t2273);
  ddi_4 _t2278 = _igen_dd_mm256_set_pd(_t2274, _t2275, _t2276, _t2277);
  dd_I _t2279 = _ia_set_dd(-0.073564563599667426, 3.0795977220259377e-19,
                           0.073564563599667426, -3.0795977220259372e-19);
  dd_I _t2280 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                           0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t2281 = _ia_set_dd(-0.2191012401568698, -2.4071243295111343e-18,
                           0.2191012401568698, 2.4071243295111347e-18);
  dd_I _t2282 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                           0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t2283 = _ia_neg_dd(_t2279);
  dd_I _t2284 = _ia_neg_dd(_t2280);
  dd_I _t2285 = _ia_neg_dd(_t2281);
  dd_I _t2286 = _ia_neg_dd(_t2282);
  ddi_4 _t2287 = _igen_dd_mm256_set_pd(_t2283, _t2284, _t2285, _t2286);
  ddi_4 _t2288 = _igen_dd_mm256_mul_pd(_t2278, s4813);
  ddi_4 _t2289 = _igen_dd_mm256_mul_pd(_t2287, s4817);
  s5153 = _igen_dd_mm256_add_pd(_t2288, _t2289);
  t4098 = _igen_dd_mm256_add_pd(s5150, s5152);
  t4099 = _igen_dd_mm256_add_pd(s5151, s5153);
  t4100 = _igen_dd_mm256_sub_pd(s5150, s5152);
  t4101 = _igen_dd_mm256_sub_pd(s5151, s5153);
  t4102 = _igen_dd_mm256_add_pd(t4094, t4098);
  t4103 = _igen_dd_mm256_add_pd(t4095, t4099);
  t4104 = _igen_dd_mm256_sub_pd(t4094, t4098);
  t4105 = _igen_dd_mm256_sub_pd(t4095, t4099);
  s5154 = _igen_dd_mm256_unpacklo_pd(t4102, t4103);
  s5155 = _igen_dd_mm256_unpackhi_pd(t4102, t4103);
  s5156 = _igen_dd_mm256_permute2f128_pd(s5154, s5155, (0) | ((2) << 4));
  *((a1309 + 30)) = s5156;
  s5157 = _igen_dd_mm256_permute2f128_pd(s5154, s5155, (1) | ((3) << 4));
  *((a1309 + 31)) = s5157;
  s5158 = _igen_dd_mm256_unpacklo_pd(t4104, t4105);
  s5159 = _igen_dd_mm256_unpackhi_pd(t4104, t4105);
  s5160 = _igen_dd_mm256_permute2f128_pd(s5158, s5159, (0) | ((2) << 4));
  *((a1309 + 94)) = s5160;
  s5161 = _igen_dd_mm256_permute2f128_pd(s5158, s5159, (1) | ((3) << 4));
  *((a1309 + 95)) = s5161;
  t4106 = _igen_dd_mm256_sub_pd(t4096, t4101);
  t4107 = _igen_dd_mm256_add_pd(t4097, t4100);
  t4108 = _igen_dd_mm256_add_pd(t4096, t4101);
  t4109 = _igen_dd_mm256_sub_pd(t4097, t4100);
  s5162 = _igen_dd_mm256_unpacklo_pd(t4106, t4107);
  s5163 = _igen_dd_mm256_unpackhi_pd(t4106, t4107);
  s5164 = _igen_dd_mm256_permute2f128_pd(s5162, s5163, (0) | ((2) << 4));
  *((a1309 + 62)) = s5164;
  s5165 = _igen_dd_mm256_permute2f128_pd(s5162, s5163, (1) | ((3) << 4));
  *((a1309 + 63)) = s5165;
  s5166 = _igen_dd_mm256_unpacklo_pd(t4108, t4109);
  s5167 = _igen_dd_mm256_unpackhi_pd(t4108, t4109);
  s5168 = _igen_dd_mm256_permute2f128_pd(s5166, s5167, (0) | ((2) << 4));
  *((a1309 + 126)) = s5168;
  s5169 = _igen_dd_mm256_permute2f128_pd(s5166, s5167, (1) | ((3) << 4));
  *((a1309 + 127)) = s5169;
}
