#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
void init_AVX_DFT128(dd_I a) {}

void AVX_DFT128(dd_I *Y, dd_I *X) {
  ddi_4 a519;
  ddi_4 a520;
  ddi_4 a521;
  ddi_4 a522;
  ddi_4 a523;
  ddi_4 a524;
  ddi_4 a525;
  ddi_4 a526;
  ddi_4 a527;
  ddi_4 a528;
  ddi_4 a530;
  ddi_4 a531;
  ddi_4 a532;
  ddi_4 a533;
  ddi_4 a534;
  ddi_4 a535;
  ddi_4 s1850;
  ddi_4 s1851;
  ddi_4 s1852;
  ddi_4 s1853;
  ddi_4 s1854;
  ddi_4 s1855;
  ddi_4 s1856;
  ddi_4 s1857;
  ddi_4 s1858;
  ddi_4 s1859;
  ddi_4 s1860;
  ddi_4 s1861;
  ddi_4 s1862;
  ddi_4 s1863;
  ddi_4 s1864;
  ddi_4 s1865;
  ddi_4 s1866;
  ddi_4 s1867;
  ddi_4 s1868;
  ddi_4 s1869;
  ddi_4 s1870;
  ddi_4 s1871;
  ddi_4 s1872;
  ddi_4 s1873;
  ddi_4 s1874;
  ddi_4 s1875;
  ddi_4 s1876;
  ddi_4 s1877;
  ddi_4 s1878;
  ddi_4 s1879;
  ddi_4 s1880;
  ddi_4 s1881;
  ddi_4 s1882;
  ddi_4 s1883;
  ddi_4 s1884;
  ddi_4 s1885;
  ddi_4 s1886;
  ddi_4 s1887;
  ddi_4 s1888;
  ddi_4 s1889;
  ddi_4 s1890;
  ddi_4 s1891;
  ddi_4 s1892;
  ddi_4 s1893;
  ddi_4 s1894;
  ddi_4 s1895;
  ddi_4 s1896;
  ddi_4 s1897;
  ddi_4 s1898;
  ddi_4 s1899;
  ddi_4 s1900;
  ddi_4 s1901;
  ddi_4 s1902;
  ddi_4 s1903;
  ddi_4 s1904;
  ddi_4 s1905;
  ddi_4 s1906;
  ddi_4 s1907;
  ddi_4 s1908;
  ddi_4 s1909;
  ddi_4 s1910;
  ddi_4 s1911;
  ddi_4 s1912;
  ddi_4 s1913;
  ddi_4 s1914;
  ddi_4 s1915;
  ddi_4 s1916;
  ddi_4 s1917;
  ddi_4 s1918;
  ddi_4 s1919;
  ddi_4 s1920;
  ddi_4 s1921;
  ddi_4 s1922;
  ddi_4 s1923;
  ddi_4 s1924;
  ddi_4 s1925;
  ddi_4 s1926;
  ddi_4 s1927;
  ddi_4 s1928;
  ddi_4 s1929;
  ddi_4 s1930;
  ddi_4 s1931;
  ddi_4 s1932;
  ddi_4 s1933;
  ddi_4 s1934;
  ddi_4 s1935;
  ddi_4 s1936;
  ddi_4 s1937;
  ddi_4 s1938;
  ddi_4 s1939;
  ddi_4 s1940;
  ddi_4 s1941;
  ddi_4 s1942;
  ddi_4 s1943;
  ddi_4 s1944;
  ddi_4 s1945;
  ddi_4 s1946;
  ddi_4 s1947;
  ddi_4 s1948;
  ddi_4 s1949;
  ddi_4 s1950;
  ddi_4 s1951;
  ddi_4 s1952;
  ddi_4 s1953;
  ddi_4 s1954;
  ddi_4 s1955;
  ddi_4 s1956;
  ddi_4 s1957;
  ddi_4 s1958;
  ddi_4 s1959;
  ddi_4 s1960;
  ddi_4 s1961;
  ddi_4 s1962;
  ddi_4 s1963;
  ddi_4 s1964;
  ddi_4 s1965;
  ddi_4 s1966;
  ddi_4 s1967;
  ddi_4 s1968;
  ddi_4 s1969;
  ddi_4 s1970;
  ddi_4 s1971;
  ddi_4 s1972;
  ddi_4 s1973;
  ddi_4 s1974;
  ddi_4 s1975;
  ddi_4 s1976;
  ddi_4 s1977;
  ddi_4 s1978;
  ddi_4 s1979;
  ddi_4 s1980;
  ddi_4 s1981;
  ddi_4 s1982;
  ddi_4 s1983;
  ddi_4 s1984;
  ddi_4 s1985;
  ddi_4 s1986;
  ddi_4 s1987;
  ddi_4 s1988;
  ddi_4 s1989;
  ddi_4 s1990;
  ddi_4 s1991;
  ddi_4 s1992;
  ddi_4 s1993;
  ddi_4 s1994;
  ddi_4 s1995;
  ddi_4 s1996;
  ddi_4 s1997;
  ddi_4 s1998;
  ddi_4 s1999;
  ddi_4 s2000;
  ddi_4 s2001;
  ddi_4 s2002;
  ddi_4 s2003;
  ddi_4 s2004;
  ddi_4 s2005;
  ddi_4 s2006;
  ddi_4 s2007;
  ddi_4 s2008;
  ddi_4 s2009;
  ddi_4 s2010;
  ddi_4 s2011;
  ddi_4 s2012;
  ddi_4 s2013;
  ddi_4 s2014;
  ddi_4 s2015;
  ddi_4 s2016;
  ddi_4 s2017;
  ddi_4 s2018;
  ddi_4 s2019;
  ddi_4 s2020;
  ddi_4 s2021;
  ddi_4 s2022;
  ddi_4 s2023;
  ddi_4 s2024;
  ddi_4 s2025;
  ddi_4 s2026;
  ddi_4 s2027;
  ddi_4 s2028;
  ddi_4 s2029;
  ddi_4 s2030;
  ddi_4 s2031;
  ddi_4 s2032;
  ddi_4 s2033;
  ddi_4 s2034;
  ddi_4 s2035;
  ddi_4 s2036;
  ddi_4 s2037;
  ddi_4 s2038;
  ddi_4 s2039;
  ddi_4 s2040;
  ddi_4 s2041;
  ddi_4 s2042;
  ddi_4 s2043;
  ddi_4 s2044;
  ddi_4 s2045;
  ddi_4 s2046;
  ddi_4 s2047;
  ddi_4 s2048;
  ddi_4 s2049;
  ddi_4 s2050;
  ddi_4 s2051;
  ddi_4 s2052;
  ddi_4 s2053;
  ddi_4 s2054;
  ddi_4 s2055;
  ddi_4 s2056;
  ddi_4 s2057;
  ddi_4 s2058;
  ddi_4 s2059;
  ddi_4 s2060;
  ddi_4 s2061;
  ddi_4 s2062;
  ddi_4 s2063;
  ddi_4 s2064;
  ddi_4 s2065;
  ddi_4 s2066;
  ddi_4 s2067;
  ddi_4 s2068;
  ddi_4 s2069;
  ddi_4 s2070;
  ddi_4 s2071;
  ddi_4 s2072;
  ddi_4 s2073;
  ddi_4 s2074;
  ddi_4 s2075;
  ddi_4 s2076;
  ddi_4 s2077;
  ddi_4 s2078;
  ddi_4 s2079;
  ddi_4 s2080;
  ddi_4 s2081;
  ddi_4 s2082;
  ddi_4 s2083;
  ddi_4 s2084;
  ddi_4 s2085;
  ddi_4 s2086;
  ddi_4 s2087;
  ddi_4 s2088;
  ddi_4 s2089;
  ddi_4 s2090;
  ddi_4 s2091;
  ddi_4 s2092;
  ddi_4 s2093;
  ddi_4 s2094;
  ddi_4 s2095;
  ddi_4 s2096;
  ddi_4 s2097;
  ddi_4 s2098;
  ddi_4 s2099;
  ddi_4 s2100;
  ddi_4 s2101;
  ddi_4 s2102;
  ddi_4 s2103;
  ddi_4 s2104;
  ddi_4 s2105;
  ddi_4 s2106;
  ddi_4 s2107;
  ddi_4 s2108;
  ddi_4 s2109;
  ddi_4 s2110;
  ddi_4 s2111;
  ddi_4 s2112;
  ddi_4 s2113;
  ddi_4 s2114;
  ddi_4 s2115;
  ddi_4 s2116;
  ddi_4 s2117;
  ddi_4 s2118;
  ddi_4 s2119;
  ddi_4 s2120;
  ddi_4 s2121;
  ddi_4 s2122;
  ddi_4 s2123;
  ddi_4 s2124;
  ddi_4 s2125;
  ddi_4 s2126;
  ddi_4 s2127;
  ddi_4 s2128;
  ddi_4 s2129;
  ddi_4 s2130;
  ddi_4 s2131;
  ddi_4 s2132;
  ddi_4 s2133;
  ddi_4 s2134;
  ddi_4 s2135;
  ddi_4 s2136;
  ddi_4 s2137;
  ddi_4 s2138;
  ddi_4 s2139;
  ddi_4 s2140;
  ddi_4 s2141;
  ddi_4 s2142;
  ddi_4 s2143;
  ddi_4 s2144;
  ddi_4 s2145;
  ddi_4 s2146;
  ddi_4 s2147;
  ddi_4 s2148;
  ddi_4 s2149;
  ddi_4 s2150;
  ddi_4 s2151;
  ddi_4 s2152;
  ddi_4 s2153;
  ddi_4 s2154;
  ddi_4 s2155;
  ddi_4 s2156;
  ddi_4 s2157;
  ddi_4 s2158;
  ddi_4 s2159;
  ddi_4 s2160;
  ddi_4 s2161;
  ddi_4 s2162;
  ddi_4 s2163;
  ddi_4 s2164;
  ddi_4 s2165;
  ddi_4 s2166;
  ddi_4 s2167;
  ddi_4 s2168;
  ddi_4 s2169;
  ddi_4 s2170;
  ddi_4 s2171;
  ddi_4 s2172;
  ddi_4 s2173;
  ddi_4 s2174;
  ddi_4 s2175;
  ddi_4 s2176;
  ddi_4 s2177;
  ddi_4 s2178;
  ddi_4 s2179;
  ddi_4 s2180;
  ddi_4 s2181;
  ddi_4 s2182;
  ddi_4 s2183;
  ddi_4 s2184;
  ddi_4 s2185;
  ddi_4 s2186;
  ddi_4 s2187;
  ddi_4 s2188;
  ddi_4 s2189;
  ddi_4 s2190;
  ddi_4 s2191;
  ddi_4 s2192;
  ddi_4 s2193;
  ddi_4 s2194;
  ddi_4 s2195;
  ddi_4 s2196;
  ddi_4 s2197;
  ddi_4 s2198;
  ddi_4 s2199;
  ddi_4 s2200;
  ddi_4 s2201;
  ddi_4 s2202;
  ddi_4 s2203;
  ddi_4 s2204;
  ddi_4 s2205;
  ddi_4 s2206;
  ddi_4 s2207;
  ddi_4 s2208;
  ddi_4 s2209;
  ddi_4 s2210;
  ddi_4 s2211;
  ddi_4 s2212;
  ddi_4 s2213;
  ddi_4 s2214;
  ddi_4 s2215;
  ddi_4 s2216;
  ddi_4 s2217;
  ddi_4 s2218;
  ddi_4 s2219;
  ddi_4 s2220;
  ddi_4 s2221;
  ddi_4 s2222;
  ddi_4 s2223;
  ddi_4 s2224;
  ddi_4 s2225;
  ddi_4 s2226;
  ddi_4 s2227;
  ddi_4 s2228;
  ddi_4 s2229;
  ddi_4 s2230;
  ddi_4 s2231;
  ddi_4 s2232;
  ddi_4 s2233;
  ddi_4 s2234;
  ddi_4 s2235;
  ddi_4 s2236;
  ddi_4 s2237;
  ddi_4 s2238;
  ddi_4 s2239;
  ddi_4 s2240;
  ddi_4 s2241;
  ddi_4 s2242;
  ddi_4 s2243;
  ddi_4 s2244;
  ddi_4 s2245;
  ddi_4 s2246;
  ddi_4 s2247;
  ddi_4 s2248;
  ddi_4 s2249;
  ddi_4 s2250;
  ddi_4 s2251;
  ddi_4 s2252;
  ddi_4 s2253;
  ddi_4 s2254;
  ddi_4 s2255;
  ddi_4 s2256;
  ddi_4 s2257;
  ddi_4 s2258;
  ddi_4 s2259;
  ddi_4 s2260;
  ddi_4 s2261;
  ddi_4 s2262;
  ddi_4 s2263;
  ddi_4 s2264;
  ddi_4 s2265;
  ddi_4 s2266;
  ddi_4 s2267;
  ddi_4 s2268;
  ddi_4 s2269;
  ddi_4 s2270;
  ddi_4 s2271;
  ddi_4 s2272;
  ddi_4 s2273;
  ddi_4 s2274;
  ddi_4 s2275;
  ddi_4 s2276;
  ddi_4 s2277;
  ddi_4 s2278;
  ddi_4 s2279;
  ddi_4 s2280;
  ddi_4 s2281;
  ddi_4 s2282;
  ddi_4 s2283;
  ddi_4 s2284;
  ddi_4 s2285;
  ddi_4 s2286;
  ddi_4 s2287;
  ddi_4 s2288;
  ddi_4 s2289;
  ddi_4 s2290;
  ddi_4 s2291;
  ddi_4 s2292;
  ddi_4 s2293;
  ddi_4 s2294;
  ddi_4 s2295;
  ddi_4 s2296;
  ddi_4 s2297;
  ddi_4 s2298;
  ddi_4 s2299;
  ddi_4 s2300;
  ddi_4 s2301;
  ddi_4 s2302;
  ddi_4 s2303;
  ddi_4 s2304;
  ddi_4 s2305;
  ddi_4 s2306;
  ddi_4 s2307;
  ddi_4 s2308;
  ddi_4 s2309;
  ddi_4 s2310;
  ddi_4 s2311;
  ddi_4 s2312;
  ddi_4 s2313;
  ddi_4 s2314;
  ddi_4 s2315;
  ddi_4 s2316;
  ddi_4 s2317;
  ddi_4 s2318;
  ddi_4 s2319;
  ddi_4 s2320;
  ddi_4 s2321;
  ddi_4 s2322;
  ddi_4 s2323;
  ddi_4 s2324;
  ddi_4 s2325;
  ddi_4 s2326;
  ddi_4 s2327;
  ddi_4 s2328;
  ddi_4 s2329;
  ddi_4 s2330;
  ddi_4 s2331;
  ddi_4 s2332;
  ddi_4 s2333;
  ddi_4 s2334;
  ddi_4 s2335;
  ddi_4 s2336;
  ddi_4 s2337;
  ddi_4 s2338;
  ddi_4 s2339;
  ddi_4 s2340;
  ddi_4 s2341;
  ddi_4 s2342;
  ddi_4 s2343;
  ddi_4 s2344;
  ddi_4 s2345;
  ddi_4 s2346;
  ddi_4 s2347;
  ddi_4 s2348;
  ddi_4 s2349;
  ddi_4 s2350;
  ddi_4 s2351;
  ddi_4 s2352;
  ddi_4 s2353;
  ddi_4 s2354;
  ddi_4 s2355;
  ddi_4 s2356;
  ddi_4 s2357;
  ddi_4 s2358;
  ddi_4 s2359;
  ddi_4 s2360;
  ddi_4 s2361;
  ddi_4 s2362;
  ddi_4 s2363;
  ddi_4 s2364;
  ddi_4 s2365;
  ddi_4 s2366;
  ddi_4 s2367;
  ddi_4 s2368;
  ddi_4 s2369;
  ddi_4 s2370;
  ddi_4 s2371;
  ddi_4 s2372;
  ddi_4 s2373;
  ddi_4 s2374;
  ddi_4 s2375;
  ddi_4 s2376;
  ddi_4 s2377;
  ddi_4 s2378;
  ddi_4 s2379;
  ddi_4 s2380;
  ddi_4 s2381;
  ddi_4 s2382;
  ddi_4 s2383;
  ddi_4 s2384;
  ddi_4 s2385;
  ddi_4 s2386;
  ddi_4 s2387;
  ddi_4 s2388;
  ddi_4 s2389;
  ddi_4 s2390;
  ddi_4 s2391;
  ddi_4 s2392;
  ddi_4 s2393;
  ddi_4 s2394;
  ddi_4 s2395;
  ddi_4 s2396;
  ddi_4 s2397;
  ddi_4 s2398;
  ddi_4 s2399;
  ddi_4 s2400;
  ddi_4 s2401;
  ddi_4 s2402;
  ddi_4 s2403;
  ddi_4 s2404;
  ddi_4 s2405;
  ddi_4 s2406;
  ddi_4 s2407;
  ddi_4 s2408;
  ddi_4 s2409;
  ddi_4 s2410;
  ddi_4 s2411;
  ddi_4 s2412;
  ddi_4 s2413;
  ddi_4 s2414;
  ddi_4 s2415;
  ddi_4 s2416;
  ddi_4 s2417;
  ddi_4 s2418;
  ddi_4 s2419;
  ddi_4 s2420;
  ddi_4 s2421;
  ddi_4 s2422;
  ddi_4 s2423;
  ddi_4 s2424;
  ddi_4 s2425;
  ddi_4 s2426;
  ddi_4 s2427;
  ddi_4 s2428;
  ddi_4 s2429;
  ddi_4 s2430;
  ddi_4 s2431;
  ddi_4 s2432;
  ddi_4 s2433;
  ddi_4 s2434;
  ddi_4 s2435;
  ddi_4 s2436;
  ddi_4 s2437;
  ddi_4 s2438;
  ddi_4 s2439;
  ddi_4 s2440;
  ddi_4 s2441;
  ddi_4 s2442;
  ddi_4 s2443;
  ddi_4 s2444;
  ddi_4 s2445;
  ddi_4 s2446;
  ddi_4 s2447;
  ddi_4 s2448;
  ddi_4 s2449;
  ddi_4 s2450;
  ddi_4 s2451;
  ddi_4 s2452;
  ddi_4 s2453;
  ddi_4 s2454;
  ddi_4 s2455;
  ddi_4 s2456;
  ddi_4 s2457;
  ddi_4 s2458;
  ddi_4 s2459;
  ddi_4 s2460;
  ddi_4 s2461;
  ddi_4 s2462;
  ddi_4 s2463;
  ddi_4 s2464;
  ddi_4 s2465;
  ddi_4 t1386;
  ddi_4 t1387;
  ddi_4 t1388;
  ddi_4 t1389;
  ddi_4 t1390;
  ddi_4 t1391;
  ddi_4 t1392;
  ddi_4 t1393;
  ddi_4 t1394;
  ddi_4 t1395;
  ddi_4 t1396;
  ddi_4 t1397;
  ddi_4 t1398;
  ddi_4 t1399;
  ddi_4 t1400;
  ddi_4 t1401;
  ddi_4 t1402;
  ddi_4 t1403;
  ddi_4 t1404;
  ddi_4 t1405;
  ddi_4 t1406;
  ddi_4 t1407;
  ddi_4 t1408;
  ddi_4 t1409;
  ddi_4 t1410;
  ddi_4 t1411;
  ddi_4 t1412;
  ddi_4 t1413;
  ddi_4 t1414;
  ddi_4 t1415;
  ddi_4 t1416;
  ddi_4 t1417;
  ddi_4 t1418;
  ddi_4 t1419;
  ddi_4 t1420;
  ddi_4 t1421;
  ddi_4 t1422;
  ddi_4 t1423;
  ddi_4 t1424;
  ddi_4 t1425;
  ddi_4 t1426;
  ddi_4 t1427;
  ddi_4 t1428;
  ddi_4 t1429;
  ddi_4 t1430;
  ddi_4 t1431;
  ddi_4 t1432;
  ddi_4 t1433;
  ddi_4 t1434;
  ddi_4 t1435;
  ddi_4 t1436;
  ddi_4 t1437;
  ddi_4 t1438;
  ddi_4 t1439;
  ddi_4 t1440;
  ddi_4 t1441;
  ddi_4 t1442;
  ddi_4 t1443;
  ddi_4 t1444;
  ddi_4 t1445;
  ddi_4 t1446;
  ddi_4 t1447;
  ddi_4 t1448;
  ddi_4 t1449;
  ddi_4 t1450;
  ddi_4 t1451;
  ddi_4 t1452;
  ddi_4 t1453;
  ddi_4 t1454;
  ddi_4 t1455;
  ddi_4 t1456;
  ddi_4 t1457;
  ddi_4 t1458;
  ddi_4 t1459;
  ddi_4 t1460;
  ddi_4 t1461;
  ddi_4 t1462;
  ddi_4 t1463;
  ddi_4 t1464;
  ddi_4 t1465;
  ddi_4 t1466;
  ddi_4 t1467;
  ddi_4 t1468;
  ddi_4 t1469;
  ddi_4 t1470;
  ddi_4 t1471;
  ddi_4 t1472;
  ddi_4 t1473;
  ddi_4 t1474;
  ddi_4 t1475;
  ddi_4 t1476;
  ddi_4 t1477;
  ddi_4 t1478;
  ddi_4 t1479;
  ddi_4 t1480;
  ddi_4 t1481;
  ddi_4 t1482;
  ddi_4 t1483;
  ddi_4 t1484;
  ddi_4 t1485;
  ddi_4 t1486;
  ddi_4 t1487;
  ddi_4 t1488;
  ddi_4 t1489;
  ddi_4 t1490;
  ddi_4 t1491;
  ddi_4 t1492;
  ddi_4 t1493;
  ddi_4 t1494;
  ddi_4 t1495;
  ddi_4 t1496;
  ddi_4 t1497;
  ddi_4 t1498;
  ddi_4 t1499;
  ddi_4 t1500;
  ddi_4 t1501;
  ddi_4 t1502;
  ddi_4 t1503;
  ddi_4 t1504;
  ddi_4 t1505;
  ddi_4 t1506;
  ddi_4 t1507;
  ddi_4 t1508;
  ddi_4 t1509;
  ddi_4 t1510;
  ddi_4 t1511;
  ddi_4 t1512;
  ddi_4 t1513;
  ddi_4 t1514;
  ddi_4 t1515;
  ddi_4 t1516;
  ddi_4 t1517;
  ddi_4 t1518;
  ddi_4 t1519;
  ddi_4 t1520;
  ddi_4 t1521;
  ddi_4 t1522;
  ddi_4 t1523;
  ddi_4 t1524;
  ddi_4 t1525;
  ddi_4 t1526;
  ddi_4 t1527;
  ddi_4 t1528;
  ddi_4 t1529;
  ddi_4 t1530;
  ddi_4 t1531;
  ddi_4 t1532;
  ddi_4 t1533;
  ddi_4 t1534;
  ddi_4 t1535;
  ddi_4 t1536;
  ddi_4 t1537;
  ddi_4 t1538;
  ddi_4 t1539;
  ddi_4 t1540;
  ddi_4 t1541;
  ddi_4 t1542;
  ddi_4 t1543;
  ddi_4 t1544;
  ddi_4 t1545;
  ddi_4 t1546;
  ddi_4 t1547;
  ddi_4 t1548;
  ddi_4 t1549;
  ddi_4 t1550;
  ddi_4 t1551;
  ddi_4 t1552;
  ddi_4 t1553;
  ddi_4 t1554;
  ddi_4 t1555;
  ddi_4 t1556;
  ddi_4 t1557;
  ddi_4 t1558;
  ddi_4 t1559;
  ddi_4 t1560;
  ddi_4 t1561;
  ddi_4 t1562;
  ddi_4 t1563;
  ddi_4 t1564;
  ddi_4 t1565;
  ddi_4 t1566;
  ddi_4 t1567;
  ddi_4 t1568;
  ddi_4 t1569;
  ddi_4 t1570;
  ddi_4 t1571;
  ddi_4 t1572;
  ddi_4 t1573;
  ddi_4 t1574;
  ddi_4 t1575;
  ddi_4 t1576;
  ddi_4 t1577;
  ddi_4 t1578;
  ddi_4 t1579;
  ddi_4 t1580;
  ddi_4 t1581;
  ddi_4 t1582;
  ddi_4 t1583;
  ddi_4 t1584;
  ddi_4 t1585;
  ddi_4 t1586;
  ddi_4 t1587;
  ddi_4 t1588;
  ddi_4 t1589;
  ddi_4 t1590;
  ddi_4 t1591;
  ddi_4 t1592;
  ddi_4 t1593;
  ddi_4 t1594;
  ddi_4 t1595;
  ddi_4 t1596;
  ddi_4 t1597;
  ddi_4 t1598;
  ddi_4 t1599;
  ddi_4 t1600;
  ddi_4 t1601;
  ddi_4 t1602;
  ddi_4 t1603;
  ddi_4 t1604;
  ddi_4 t1605;
  ddi_4 t1606;
  ddi_4 t1607;
  ddi_4 t1608;
  ddi_4 t1609;
  ddi_4 t1610;
  ddi_4 t1611;
  ddi_4 t1612;
  ddi_4 t1613;
  ddi_4 t1614;
  ddi_4 t1615;
  ddi_4 t1616;
  ddi_4 t1617;
  ddi_4 t1618;
  ddi_4 t1619;
  ddi_4 t1620;
  ddi_4 t1621;
  ddi_4 t1622;
  ddi_4 t1623;
  ddi_4 t1624;
  ddi_4 t1625;
  ddi_4 t1626;
  ddi_4 t1627;
  ddi_4 t1628;
  ddi_4 t1629;
  ddi_4 t1630;
  ddi_4 t1631;
  ddi_4 t1632;
  ddi_4 t1633;
  ddi_4 t1634;
  ddi_4 t1635;
  ddi_4 t1636;
  ddi_4 t1637;
  ddi_4 t1638;
  ddi_4 t1639;
  ddi_4 t1640;
  ddi_4 t1641;
  ddi_4 t1642;
  ddi_4 t1643;
  ddi_4 t1644;
  ddi_4 t1645;
  ddi_4 t1646;
  ddi_4 t1647;
  ddi_4 t1648;
  ddi_4 t1649;
  ddi_4 t1650;
  ddi_4 t1651;
  ddi_4 t1652;
  ddi_4 t1653;
  ddi_4 t1654;
  ddi_4 t1655;
  ddi_4 t1656;
  ddi_4 t1657;
  ddi_4 t1658;
  ddi_4 t1659;
  ddi_4 t1660;
  ddi_4 t1661;
  ddi_4 t1662;
  ddi_4 t1663;
  ddi_4 t1664;
  ddi_4 t1665;
  ddi_4 t1666;
  ddi_4 t1667;
  ddi_4 t1668;
  ddi_4 t1669;
  ddi_4 t1670;
  ddi_4 t1671;
  ddi_4 t1672;
  ddi_4 t1673;
  ddi_4 t1674;
  ddi_4 t1675;
  ddi_4 t1676;
  ddi_4 t1677;
  ddi_4 t1678;
  ddi_4 t1679;
  ddi_4 t1680;
  ddi_4 t1681;
  ddi_4 t1682;
  ddi_4 t1683;
  ddi_4 t1684;
  ddi_4 t1685;
  ddi_4 t1686;
  ddi_4 t1687;
  ddi_4 t1688;
  ddi_4 t1689;
  ddi_4 t1690;
  ddi_4 t1691;
  ddi_4 t1692;
  ddi_4 t1693;
  ddi_4 t1694;
  ddi_4 t1695;
  ddi_4 t1696;
  ddi_4 t1697;
  ddi_4 t1698;
  ddi_4 t1699;
  ddi_4 t1700;
  ddi_4 t1701;
  ddi_4 t1702;
  ddi_4 t1703;
  ddi_4 t1704;
  ddi_4 t1705;
  ddi_4 t1706;
  ddi_4 t1707;
  ddi_4 t1708;
  ddi_4 t1709;
  ddi_4 t1710;
  ddi_4 t1711;
  ddi_4 t1712;
  ddi_4 t1713;
  ddi_4 t1714;
  ddi_4 t1715;
  ddi_4 t1716;
  ddi_4 t1717;
  ddi_4 t1718;
  ddi_4 t1719;
  ddi_4 t1720;
  ddi_4 t1721;
  ddi_4 t1722;
  ddi_4 t1723;
  ddi_4 t1724;
  ddi_4 t1725;
  ddi_4 t1726;
  ddi_4 t1727;
  ddi_4 t1728;
  ddi_4 t1729;
  ddi_4 t1730;
  ddi_4 t1731;
  ddi_4 t1732;
  ddi_4 t1733;
  ddi_4 t1734;
  ddi_4 t1735;
  ddi_4 t1736;
  ddi_4 t1737;
  ddi_4 t1738;
  ddi_4 t1739;
  ddi_4 t1740;
  ddi_4 t1741;
  ddi_4 t1742;
  ddi_4 t1743;
  ddi_4 t1744;
  ddi_4 t1745;
  ddi_4 t1746;
  ddi_4 t1747;
  ddi_4 t1748;
  ddi_4 t1749;
  ddi_4 t1750;
  ddi_4 t1751;
  ddi_4 t1752;
  ddi_4 t1753;
  ddi_4 t1754;
  ddi_4 t1755;
  ddi_4 t1756;
  ddi_4 t1757;
  ddi_4 t1758;
  ddi_4 t1759;
  ddi_4 t1760;
  ddi_4 t1761;
  ddi_4 t1762;
  ddi_4 t1763;
  ddi_4 t1764;
  ddi_4 t1765;
  ddi_4 t1766;
  ddi_4 t1767;
  ddi_4 t1768;
  ddi_4 t1769;
  ddi_4 t1770;
  ddi_4 t1771;
  ddi_4 t1772;
  ddi_4 t1773;
  ddi_4 t1774;
  ddi_4 t1775;
  ddi_4 t1776;
  ddi_4 t1777;
  ddi_4 t1778;
  ddi_4 t1779;
  ddi_4 t1780;
  ddi_4 t1781;
  ddi_4 t1782;
  ddi_4 t1783;
  ddi_4 t1784;
  ddi_4 t1785;
  ddi_4 t1786;
  ddi_4 t1787;
  ddi_4 t1788;
  ddi_4 t1789;
  ddi_4 t1790;
  ddi_4 t1791;
  ddi_4 t1792;
  ddi_4 t1793;
  ddi_4 t1794;
  ddi_4 t1795;
  ddi_4 t1796;
  ddi_4 t1797;
  ddi_4 t1798;
  ddi_4 t1799;
  ddi_4 t1800;
  ddi_4 t1801;
  ddi_4 t1802;
  ddi_4 t1803;
  ddi_4 t1804;
  ddi_4 t1805;
  ddi_4 t1806;
  ddi_4 t1807;
  ddi_4 t1808;
  ddi_4 t1809;
  ddi_4 t1810;
  ddi_4 t1811;
  ddi_4 t1812;
  ddi_4 t1813;
  ddi_4 t1814;
  ddi_4 t1815;
  ddi_4 t1816;
  ddi_4 t1817;
  ddi_4 *a518;
  ddi_4 *a529;
  a518 = ((ddi_4 *)X);
  s1850 = *(a518);
  s1851 = *((a518 + 1));
  s1852 = _igen_dd_mm256_permute2f128_pd(s1850, s1851, (0) | ((2) << 4));
  s1853 = _igen_dd_mm256_permute2f128_pd(s1850, s1851, (1) | ((3) << 4));
  s1854 = _igen_dd_mm256_unpacklo_pd(s1852, s1853);
  s1855 = _igen_dd_mm256_unpackhi_pd(s1852, s1853);
  s1856 = *((a518 + 32));
  s1857 = *((a518 + 33));
  s1858 = _igen_dd_mm256_permute2f128_pd(s1856, s1857, (0) | ((2) << 4));
  s1859 = _igen_dd_mm256_permute2f128_pd(s1856, s1857, (1) | ((3) << 4));
  s1860 = _igen_dd_mm256_unpacklo_pd(s1858, s1859);
  s1861 = _igen_dd_mm256_unpackhi_pd(s1858, s1859);
  t1386 = _igen_dd_mm256_add_pd(s1854, s1860);
  t1387 = _igen_dd_mm256_add_pd(s1855, s1861);
  t1388 = _igen_dd_mm256_sub_pd(s1854, s1860);
  t1389 = _igen_dd_mm256_sub_pd(s1855, s1861);
  s1862 = *((a518 + 16));
  s1863 = *((a518 + 17));
  s1864 = _igen_dd_mm256_permute2f128_pd(s1862, s1863, (0) | ((2) << 4));
  s1865 = _igen_dd_mm256_permute2f128_pd(s1862, s1863, (1) | ((3) << 4));
  s1866 = _igen_dd_mm256_unpacklo_pd(s1864, s1865);
  s1867 = _igen_dd_mm256_unpackhi_pd(s1864, s1865);
  s1868 = *((a518 + 48));
  s1869 = *((a518 + 49));
  s1870 = _igen_dd_mm256_permute2f128_pd(s1868, s1869, (0) | ((2) << 4));
  s1871 = _igen_dd_mm256_permute2f128_pd(s1868, s1869, (1) | ((3) << 4));
  s1872 = _igen_dd_mm256_unpacklo_pd(s1870, s1871);
  s1873 = _igen_dd_mm256_unpackhi_pd(s1870, s1871);
  t1390 = _igen_dd_mm256_add_pd(s1866, s1872);
  t1391 = _igen_dd_mm256_add_pd(s1867, s1873);
  t1392 = _igen_dd_mm256_sub_pd(s1866, s1872);
  t1393 = _igen_dd_mm256_sub_pd(s1867, s1873);
  t1394 = _igen_dd_mm256_add_pd(t1386, t1390);
  t1395 = _igen_dd_mm256_add_pd(t1387, t1391);
  t1396 = _igen_dd_mm256_sub_pd(t1386, t1390);
  t1397 = _igen_dd_mm256_sub_pd(t1387, t1391);
  t1398 = _igen_dd_mm256_sub_pd(t1388, t1393);
  t1399 = _igen_dd_mm256_add_pd(t1389, t1392);
  t1400 = _igen_dd_mm256_add_pd(t1388, t1393);
  t1401 = _igen_dd_mm256_sub_pd(t1389, t1392);
  s1874 = *((a518 + 4));
  s1875 = *((a518 + 5));
  s1876 = _igen_dd_mm256_permute2f128_pd(s1874, s1875, (0) | ((2) << 4));
  s1877 = _igen_dd_mm256_permute2f128_pd(s1874, s1875, (1) | ((3) << 4));
  s1878 = _igen_dd_mm256_unpacklo_pd(s1876, s1877);
  s1879 = _igen_dd_mm256_unpackhi_pd(s1876, s1877);
  s1880 = *((a518 + 36));
  s1881 = *((a518 + 37));
  s1882 = _igen_dd_mm256_permute2f128_pd(s1880, s1881, (0) | ((2) << 4));
  s1883 = _igen_dd_mm256_permute2f128_pd(s1880, s1881, (1) | ((3) << 4));
  s1884 = _igen_dd_mm256_unpacklo_pd(s1882, s1883);
  s1885 = _igen_dd_mm256_unpackhi_pd(s1882, s1883);
  t1402 = _igen_dd_mm256_add_pd(s1878, s1884);
  t1403 = _igen_dd_mm256_add_pd(s1879, s1885);
  t1404 = _igen_dd_mm256_sub_pd(s1878, s1884);
  t1405 = _igen_dd_mm256_sub_pd(s1879, s1885);
  s1886 = *((a518 + 20));
  s1887 = *((a518 + 21));
  s1888 = _igen_dd_mm256_permute2f128_pd(s1886, s1887, (0) | ((2) << 4));
  s1889 = _igen_dd_mm256_permute2f128_pd(s1886, s1887, (1) | ((3) << 4));
  s1890 = _igen_dd_mm256_unpacklo_pd(s1888, s1889);
  s1891 = _igen_dd_mm256_unpackhi_pd(s1888, s1889);
  s1892 = *((a518 + 52));
  s1893 = *((a518 + 53));
  s1894 = _igen_dd_mm256_permute2f128_pd(s1892, s1893, (0) | ((2) << 4));
  s1895 = _igen_dd_mm256_permute2f128_pd(s1892, s1893, (1) | ((3) << 4));
  s1896 = _igen_dd_mm256_unpacklo_pd(s1894, s1895);
  s1897 = _igen_dd_mm256_unpackhi_pd(s1894, s1895);
  t1406 = _igen_dd_mm256_add_pd(s1890, s1896);
  t1407 = _igen_dd_mm256_add_pd(s1891, s1897);
  t1408 = _igen_dd_mm256_sub_pd(s1890, s1896);
  t1409 = _igen_dd_mm256_sub_pd(s1891, s1897);
  t1410 = _igen_dd_mm256_add_pd(t1402, t1406);
  t1411 = _igen_dd_mm256_add_pd(t1403, t1407);
  t1412 = _igen_dd_mm256_sub_pd(t1402, t1406);
  t1413 = _igen_dd_mm256_sub_pd(t1403, t1407);
  dd_I _t1 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t2 = _igen_dd_mm256_set1_pd(_t1);
  ddi_4 _t3 = _igen_dd_mm256_sub_pd(t1412, t1413);
  s1898 = _igen_dd_mm256_mul_pd(_t2, _t3);
  dd_I _t4 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t5 = _igen_dd_mm256_set1_pd(_t4);
  ddi_4 _t6 = _igen_dd_mm256_add_pd(t1412, t1413);
  s1899 = _igen_dd_mm256_mul_pd(_t5, _t6);
  t1414 = _igen_dd_mm256_sub_pd(t1404, t1409);
  t1415 = _igen_dd_mm256_add_pd(t1405, t1408);
  t1416 = _igen_dd_mm256_add_pd(t1404, t1409);
  t1417 = _igen_dd_mm256_sub_pd(t1405, t1408);
  dd_I _t7 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                        0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t8 = _igen_dd_mm256_set1_pd(_t7);
  dd_I _t9 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                        0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t10 = _igen_dd_mm256_set1_pd(_t9);
  ddi_4 _t11 = _igen_dd_mm256_mul_pd(_t8, t1414);
  ddi_4 _t12 = _igen_dd_mm256_mul_pd(_t10, t1415);
  s1900 = _igen_dd_mm256_sub_pd(_t11, _t12);
  dd_I _t13 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t14 = _igen_dd_mm256_set1_pd(_t13);
  dd_I _t15 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t16 = _igen_dd_mm256_set1_pd(_t15);
  ddi_4 _t17 = _igen_dd_mm256_mul_pd(_t14, t1414);
  ddi_4 _t18 = _igen_dd_mm256_mul_pd(_t16, t1415);
  s1901 = _igen_dd_mm256_add_pd(_t17, _t18);
  dd_I _t19 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t20 = _igen_dd_mm256_set1_pd(_t19);
  dd_I _t21 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t22 = _igen_dd_mm256_set1_pd(_t21);
  ddi_4 _t23 = _igen_dd_mm256_mul_pd(_t20, t1416);
  ddi_4 _t24 = _igen_dd_mm256_mul_pd(_t22, t1417);
  s1902 = _igen_dd_mm256_sub_pd(_t23, _t24);
  dd_I _t25 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t26 = _igen_dd_mm256_set1_pd(_t25);
  dd_I _t27 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t28 = _igen_dd_mm256_set1_pd(_t27);
  ddi_4 _t29 = _igen_dd_mm256_mul_pd(_t26, t1416);
  ddi_4 _t30 = _igen_dd_mm256_mul_pd(_t28, t1417);
  s1903 = _igen_dd_mm256_add_pd(_t29, _t30);
  s1904 = *((a518 + 8));
  s1905 = *((a518 + 9));
  s1906 = _igen_dd_mm256_permute2f128_pd(s1904, s1905, (0) | ((2) << 4));
  s1907 = _igen_dd_mm256_permute2f128_pd(s1904, s1905, (1) | ((3) << 4));
  s1908 = _igen_dd_mm256_unpacklo_pd(s1906, s1907);
  s1909 = _igen_dd_mm256_unpackhi_pd(s1906, s1907);
  s1910 = *((a518 + 40));
  s1911 = *((a518 + 41));
  s1912 = _igen_dd_mm256_permute2f128_pd(s1910, s1911, (0) | ((2) << 4));
  s1913 = _igen_dd_mm256_permute2f128_pd(s1910, s1911, (1) | ((3) << 4));
  s1914 = _igen_dd_mm256_unpacklo_pd(s1912, s1913);
  s1915 = _igen_dd_mm256_unpackhi_pd(s1912, s1913);
  t1418 = _igen_dd_mm256_add_pd(s1908, s1914);
  t1419 = _igen_dd_mm256_add_pd(s1909, s1915);
  t1420 = _igen_dd_mm256_sub_pd(s1908, s1914);
  t1421 = _igen_dd_mm256_sub_pd(s1909, s1915);
  s1916 = *((a518 + 24));
  s1917 = *((a518 + 25));
  s1918 = _igen_dd_mm256_permute2f128_pd(s1916, s1917, (0) | ((2) << 4));
  s1919 = _igen_dd_mm256_permute2f128_pd(s1916, s1917, (1) | ((3) << 4));
  s1920 = _igen_dd_mm256_unpacklo_pd(s1918, s1919);
  s1921 = _igen_dd_mm256_unpackhi_pd(s1918, s1919);
  s1922 = *((a518 + 56));
  s1923 = *((a518 + 57));
  s1924 = _igen_dd_mm256_permute2f128_pd(s1922, s1923, (0) | ((2) << 4));
  s1925 = _igen_dd_mm256_permute2f128_pd(s1922, s1923, (1) | ((3) << 4));
  s1926 = _igen_dd_mm256_unpacklo_pd(s1924, s1925);
  s1927 = _igen_dd_mm256_unpackhi_pd(s1924, s1925);
  t1422 = _igen_dd_mm256_add_pd(s1920, s1926);
  t1423 = _igen_dd_mm256_add_pd(s1921, s1927);
  t1424 = _igen_dd_mm256_sub_pd(s1920, s1926);
  t1425 = _igen_dd_mm256_sub_pd(s1921, s1927);
  t1426 = _igen_dd_mm256_add_pd(t1418, t1422);
  t1427 = _igen_dd_mm256_add_pd(t1419, t1423);
  t1428 = _igen_dd_mm256_sub_pd(t1418, t1422);
  t1429 = _igen_dd_mm256_sub_pd(t1419, t1423);
  t1430 = _igen_dd_mm256_sub_pd(t1420, t1425);
  t1431 = _igen_dd_mm256_add_pd(t1421, t1424);
  dd_I _t31 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t32 = _igen_dd_mm256_set1_pd(_t31);
  ddi_4 _t33 = _igen_dd_mm256_sub_pd(t1430, t1431);
  s1928 = _igen_dd_mm256_mul_pd(_t32, _t33);
  dd_I _t34 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t35 = _igen_dd_mm256_set1_pd(_t34);
  ddi_4 _t36 = _igen_dd_mm256_add_pd(t1430, t1431);
  s1929 = _igen_dd_mm256_mul_pd(_t35, _t36);
  dd_I _t37 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t38 = _ia_neg_dd(_t37);
  ddi_4 _t39 = _igen_dd_mm256_set1_pd(_t38);
  ddi_4 _t40 = _igen_dd_mm256_add_pd(t1420, t1425);
  a519 = _igen_dd_mm256_mul_pd(_t39, _t40);
  dd_I _t41 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t42 = _igen_dd_mm256_set1_pd(_t41);
  ddi_4 _t43 = _igen_dd_mm256_sub_pd(t1421, t1424);
  a520 = _igen_dd_mm256_mul_pd(_t42, _t43);
  s1930 = _igen_dd_mm256_sub_pd(a519, a520);
  s1931 = _igen_dd_mm256_add_pd(a519, a520);
  s1932 = *((a518 + 12));
  s1933 = *((a518 + 13));
  s1934 = _igen_dd_mm256_permute2f128_pd(s1932, s1933, (0) | ((2) << 4));
  s1935 = _igen_dd_mm256_permute2f128_pd(s1932, s1933, (1) | ((3) << 4));
  s1936 = _igen_dd_mm256_unpacklo_pd(s1934, s1935);
  s1937 = _igen_dd_mm256_unpackhi_pd(s1934, s1935);
  s1938 = *((a518 + 44));
  s1939 = *((a518 + 45));
  s1940 = _igen_dd_mm256_permute2f128_pd(s1938, s1939, (0) | ((2) << 4));
  s1941 = _igen_dd_mm256_permute2f128_pd(s1938, s1939, (1) | ((3) << 4));
  s1942 = _igen_dd_mm256_unpacklo_pd(s1940, s1941);
  s1943 = _igen_dd_mm256_unpackhi_pd(s1940, s1941);
  t1432 = _igen_dd_mm256_add_pd(s1936, s1942);
  t1433 = _igen_dd_mm256_add_pd(s1937, s1943);
  t1434 = _igen_dd_mm256_sub_pd(s1936, s1942);
  t1435 = _igen_dd_mm256_sub_pd(s1937, s1943);
  s1944 = *((a518 + 28));
  s1945 = *((a518 + 29));
  s1946 = _igen_dd_mm256_permute2f128_pd(s1944, s1945, (0) | ((2) << 4));
  s1947 = _igen_dd_mm256_permute2f128_pd(s1944, s1945, (1) | ((3) << 4));
  s1948 = _igen_dd_mm256_unpacklo_pd(s1946, s1947);
  s1949 = _igen_dd_mm256_unpackhi_pd(s1946, s1947);
  s1950 = *((a518 + 60));
  s1951 = *((a518 + 61));
  s1952 = _igen_dd_mm256_permute2f128_pd(s1950, s1951, (0) | ((2) << 4));
  s1953 = _igen_dd_mm256_permute2f128_pd(s1950, s1951, (1) | ((3) << 4));
  s1954 = _igen_dd_mm256_unpacklo_pd(s1952, s1953);
  s1955 = _igen_dd_mm256_unpackhi_pd(s1952, s1953);
  t1436 = _igen_dd_mm256_add_pd(s1948, s1954);
  t1437 = _igen_dd_mm256_add_pd(s1949, s1955);
  t1438 = _igen_dd_mm256_sub_pd(s1948, s1954);
  t1439 = _igen_dd_mm256_sub_pd(s1949, s1955);
  t1440 = _igen_dd_mm256_add_pd(t1432, t1436);
  t1441 = _igen_dd_mm256_add_pd(t1433, t1437);
  dd_I _t44 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t45 = _ia_neg_dd(_t44);
  ddi_4 _t46 = _igen_dd_mm256_set1_pd(_t45);
  ddi_4 _t47 = _igen_dd_mm256_sub_pd(t1432, t1436);
  a521 = _igen_dd_mm256_mul_pd(_t46, _t47);
  dd_I _t48 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t49 = _igen_dd_mm256_set1_pd(_t48);
  ddi_4 _t50 = _igen_dd_mm256_sub_pd(t1433, t1437);
  a522 = _igen_dd_mm256_mul_pd(_t49, _t50);
  s1956 = _igen_dd_mm256_sub_pd(a521, a522);
  s1957 = _igen_dd_mm256_add_pd(a521, a522);
  t1442 = _igen_dd_mm256_sub_pd(t1434, t1439);
  t1443 = _igen_dd_mm256_add_pd(t1435, t1438);
  t1444 = _igen_dd_mm256_add_pd(t1434, t1439);
  t1445 = _igen_dd_mm256_sub_pd(t1435, t1438);
  dd_I _t51 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t52 = _igen_dd_mm256_set1_pd(_t51);
  dd_I _t53 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t54 = _igen_dd_mm256_set1_pd(_t53);
  ddi_4 _t55 = _igen_dd_mm256_mul_pd(_t52, t1442);
  ddi_4 _t56 = _igen_dd_mm256_mul_pd(_t54, t1443);
  s1958 = _igen_dd_mm256_sub_pd(_t55, _t56);
  dd_I _t57 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t58 = _igen_dd_mm256_set1_pd(_t57);
  dd_I _t59 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t60 = _igen_dd_mm256_set1_pd(_t59);
  ddi_4 _t61 = _igen_dd_mm256_mul_pd(_t58, t1442);
  ddi_4 _t62 = _igen_dd_mm256_mul_pd(_t60, t1443);
  s1959 = _igen_dd_mm256_add_pd(_t61, _t62);
  dd_I _t63 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t64 = _ia_neg_dd(_t63);
  ddi_4 _t65 = _igen_dd_mm256_set1_pd(_t64);
  dd_I _t66 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t67 = _ia_neg_dd(_t66);
  ddi_4 _t68 = _igen_dd_mm256_set1_pd(_t67);
  ddi_4 _t69 = _igen_dd_mm256_mul_pd(_t65, t1444);
  ddi_4 _t70 = _igen_dd_mm256_mul_pd(_t68, t1445);
  s1960 = _igen_dd_mm256_sub_pd(_t69, _t70);
  dd_I _t71 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t72 = _ia_neg_dd(_t71);
  ddi_4 _t73 = _igen_dd_mm256_set1_pd(_t72);
  dd_I _t74 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t75 = _ia_neg_dd(_t74);
  ddi_4 _t76 = _igen_dd_mm256_set1_pd(_t75);
  ddi_4 _t77 = _igen_dd_mm256_mul_pd(_t73, t1444);
  ddi_4 _t78 = _igen_dd_mm256_mul_pd(_t76, t1445);
  s1961 = _igen_dd_mm256_add_pd(_t77, _t78);
  t1446 = _igen_dd_mm256_add_pd(t1394, t1426);
  t1447 = _igen_dd_mm256_add_pd(t1395, t1427);
  t1448 = _igen_dd_mm256_sub_pd(t1394, t1426);
  t1449 = _igen_dd_mm256_sub_pd(t1395, t1427);
  t1450 = _igen_dd_mm256_add_pd(t1410, t1440);
  t1451 = _igen_dd_mm256_add_pd(t1411, t1441);
  t1452 = _igen_dd_mm256_sub_pd(t1410, t1440);
  t1453 = _igen_dd_mm256_sub_pd(t1411, t1441);
  t1454 = _igen_dd_mm256_add_pd(t1446, t1450);
  t1455 = _igen_dd_mm256_add_pd(t1447, t1451);
  t1456 = _igen_dd_mm256_sub_pd(t1446, t1450);
  t1457 = _igen_dd_mm256_sub_pd(t1447, t1451);
  t1458 = _igen_dd_mm256_sub_pd(t1448, t1453);
  t1459 = _igen_dd_mm256_add_pd(t1449, t1452);
  t1460 = _igen_dd_mm256_add_pd(t1448, t1453);
  t1461 = _igen_dd_mm256_sub_pd(t1449, t1452);
  t1462 = _igen_dd_mm256_add_pd(t1398, s1928);
  t1463 = _igen_dd_mm256_add_pd(t1399, s1929);
  t1464 = _igen_dd_mm256_sub_pd(t1398, s1928);
  t1465 = _igen_dd_mm256_sub_pd(t1399, s1929);
  t1466 = _igen_dd_mm256_add_pd(s1900, s1958);
  t1467 = _igen_dd_mm256_add_pd(s1901, s1959);
  t1468 = _igen_dd_mm256_sub_pd(s1900, s1958);
  t1469 = _igen_dd_mm256_sub_pd(s1901, s1959);
  t1470 = _igen_dd_mm256_add_pd(t1462, t1466);
  t1471 = _igen_dd_mm256_add_pd(t1463, t1467);
  t1472 = _igen_dd_mm256_sub_pd(t1462, t1466);
  t1473 = _igen_dd_mm256_sub_pd(t1463, t1467);
  t1474 = _igen_dd_mm256_sub_pd(t1464, t1469);
  t1475 = _igen_dd_mm256_add_pd(t1465, t1468);
  t1476 = _igen_dd_mm256_add_pd(t1464, t1469);
  t1477 = _igen_dd_mm256_sub_pd(t1465, t1468);
  t1478 = _igen_dd_mm256_sub_pd(t1396, t1429);
  t1479 = _igen_dd_mm256_add_pd(t1397, t1428);
  t1480 = _igen_dd_mm256_add_pd(t1396, t1429);
  t1481 = _igen_dd_mm256_sub_pd(t1397, t1428);
  t1482 = _igen_dd_mm256_add_pd(s1898, s1956);
  t1483 = _igen_dd_mm256_sub_pd(s1899, s1957);
  t1484 = _igen_dd_mm256_sub_pd(s1898, s1956);
  t1485 = _igen_dd_mm256_add_pd(s1899, s1957);
  t1486 = _igen_dd_mm256_add_pd(t1478, t1482);
  t1487 = _igen_dd_mm256_add_pd(t1479, t1483);
  t1488 = _igen_dd_mm256_sub_pd(t1478, t1482);
  t1489 = _igen_dd_mm256_sub_pd(t1479, t1483);
  t1490 = _igen_dd_mm256_sub_pd(t1480, t1485);
  t1491 = _igen_dd_mm256_add_pd(t1481, t1484);
  t1492 = _igen_dd_mm256_add_pd(t1480, t1485);
  t1493 = _igen_dd_mm256_sub_pd(t1481, t1484);
  t1494 = _igen_dd_mm256_add_pd(t1400, s1930);
  t1495 = _igen_dd_mm256_sub_pd(t1401, s1931);
  t1496 = _igen_dd_mm256_sub_pd(t1400, s1930);
  t1497 = _igen_dd_mm256_add_pd(t1401, s1931);
  t1498 = _igen_dd_mm256_add_pd(s1902, s1960);
  t1499 = _igen_dd_mm256_add_pd(s1903, s1961);
  t1500 = _igen_dd_mm256_sub_pd(s1902, s1960);
  t1501 = _igen_dd_mm256_sub_pd(s1903, s1961);
  t1502 = _igen_dd_mm256_add_pd(t1494, t1498);
  t1503 = _igen_dd_mm256_add_pd(t1495, t1499);
  t1504 = _igen_dd_mm256_sub_pd(t1494, t1498);
  t1505 = _igen_dd_mm256_sub_pd(t1495, t1499);
  t1506 = _igen_dd_mm256_sub_pd(t1496, t1501);
  t1507 = _igen_dd_mm256_add_pd(t1497, t1500);
  t1508 = _igen_dd_mm256_add_pd(t1496, t1501);
  t1509 = _igen_dd_mm256_sub_pd(t1497, t1500);
  s1962 = _igen_dd_mm256_unpacklo_pd(t1454, t1470);
  s1963 = _igen_dd_mm256_unpackhi_pd(t1454, t1470);
  s1964 = _igen_dd_mm256_unpacklo_pd(t1455, t1471);
  s1965 = _igen_dd_mm256_unpackhi_pd(t1455, t1471);
  s1966 = _igen_dd_mm256_permute2f128_pd(s1962, s1963, (0) | ((2) << 4));
  s1967 = _igen_dd_mm256_permute2f128_pd(s1962, s1963, (1) | ((3) << 4));
  s1968 = _igen_dd_mm256_permute2f128_pd(s1964, s1965, (0) | ((2) << 4));
  s1969 = _igen_dd_mm256_permute2f128_pd(s1964, s1965, (1) | ((3) << 4));
  s1970 = _igen_dd_mm256_unpacklo_pd(t1486, t1502);
  s1971 = _igen_dd_mm256_unpackhi_pd(t1486, t1502);
  s1972 = _igen_dd_mm256_unpacklo_pd(t1487, t1503);
  s1973 = _igen_dd_mm256_unpackhi_pd(t1487, t1503);
  s1974 = _igen_dd_mm256_permute2f128_pd(s1970, s1971, (0) | ((2) << 4));
  s1975 = _igen_dd_mm256_permute2f128_pd(s1970, s1971, (1) | ((3) << 4));
  s1976 = _igen_dd_mm256_permute2f128_pd(s1972, s1973, (0) | ((2) << 4));
  s1977 = _igen_dd_mm256_permute2f128_pd(s1972, s1973, (1) | ((3) << 4));
  s1978 = _igen_dd_mm256_permute2f128_pd(s1966, s1974, (0) | ((2) << 4));
  s1979 = _igen_dd_mm256_permute2f128_pd(s1966, s1974, (1) | ((3) << 4));
  s1980 = _igen_dd_mm256_permute2f128_pd(s1967, s1975, (0) | ((2) << 4));
  s1981 = _igen_dd_mm256_permute2f128_pd(s1967, s1975, (1) | ((3) << 4));
  s1982 = _igen_dd_mm256_permute2f128_pd(s1968, s1976, (0) | ((2) << 4));
  s1983 = _igen_dd_mm256_permute2f128_pd(s1968, s1976, (1) | ((3) << 4));
  s1984 = _igen_dd_mm256_permute2f128_pd(s1969, s1977, (0) | ((2) << 4));
  s1985 = _igen_dd_mm256_permute2f128_pd(s1969, s1977, (1) | ((3) << 4));
  s1986 = _igen_dd_mm256_unpacklo_pd(t1458, t1474);
  s1987 = _igen_dd_mm256_unpackhi_pd(t1458, t1474);
  s1988 = _igen_dd_mm256_unpacklo_pd(t1459, t1475);
  s1989 = _igen_dd_mm256_unpackhi_pd(t1459, t1475);
  s1990 = _igen_dd_mm256_permute2f128_pd(s1986, s1987, (0) | ((2) << 4));
  s1991 = _igen_dd_mm256_permute2f128_pd(s1986, s1987, (1) | ((3) << 4));
  s1992 = _igen_dd_mm256_permute2f128_pd(s1988, s1989, (0) | ((2) << 4));
  s1993 = _igen_dd_mm256_permute2f128_pd(s1988, s1989, (1) | ((3) << 4));
  s1994 = _igen_dd_mm256_unpacklo_pd(t1490, t1506);
  s1995 = _igen_dd_mm256_unpackhi_pd(t1490, t1506);
  s1996 = _igen_dd_mm256_unpacklo_pd(t1491, t1507);
  s1997 = _igen_dd_mm256_unpackhi_pd(t1491, t1507);
  s1998 = _igen_dd_mm256_permute2f128_pd(s1994, s1995, (0) | ((2) << 4));
  s1999 = _igen_dd_mm256_permute2f128_pd(s1994, s1995, (1) | ((3) << 4));
  s2000 = _igen_dd_mm256_permute2f128_pd(s1996, s1997, (0) | ((2) << 4));
  s2001 = _igen_dd_mm256_permute2f128_pd(s1996, s1997, (1) | ((3) << 4));
  s2002 = _igen_dd_mm256_permute2f128_pd(s1990, s1998, (0) | ((2) << 4));
  s2003 = _igen_dd_mm256_permute2f128_pd(s1990, s1998, (1) | ((3) << 4));
  s2004 = _igen_dd_mm256_permute2f128_pd(s1991, s1999, (0) | ((2) << 4));
  s2005 = _igen_dd_mm256_permute2f128_pd(s1991, s1999, (1) | ((3) << 4));
  s2006 = _igen_dd_mm256_permute2f128_pd(s1992, s2000, (0) | ((2) << 4));
  s2007 = _igen_dd_mm256_permute2f128_pd(s1992, s2000, (1) | ((3) << 4));
  s2008 = _igen_dd_mm256_permute2f128_pd(s1993, s2001, (0) | ((2) << 4));
  s2009 = _igen_dd_mm256_permute2f128_pd(s1993, s2001, (1) | ((3) << 4));
  s2010 = _igen_dd_mm256_unpacklo_pd(t1456, t1472);
  s2011 = _igen_dd_mm256_unpackhi_pd(t1456, t1472);
  s2012 = _igen_dd_mm256_unpacklo_pd(t1457, t1473);
  s2013 = _igen_dd_mm256_unpackhi_pd(t1457, t1473);
  s2014 = _igen_dd_mm256_permute2f128_pd(s2010, s2011, (0) | ((2) << 4));
  s2015 = _igen_dd_mm256_permute2f128_pd(s2010, s2011, (1) | ((3) << 4));
  s2016 = _igen_dd_mm256_permute2f128_pd(s2012, s2013, (0) | ((2) << 4));
  s2017 = _igen_dd_mm256_permute2f128_pd(s2012, s2013, (1) | ((3) << 4));
  s2018 = _igen_dd_mm256_unpacklo_pd(t1488, t1504);
  s2019 = _igen_dd_mm256_unpackhi_pd(t1488, t1504);
  s2020 = _igen_dd_mm256_unpacklo_pd(t1489, t1505);
  s2021 = _igen_dd_mm256_unpackhi_pd(t1489, t1505);
  s2022 = _igen_dd_mm256_permute2f128_pd(s2018, s2019, (0) | ((2) << 4));
  s2023 = _igen_dd_mm256_permute2f128_pd(s2018, s2019, (1) | ((3) << 4));
  s2024 = _igen_dd_mm256_permute2f128_pd(s2020, s2021, (0) | ((2) << 4));
  s2025 = _igen_dd_mm256_permute2f128_pd(s2020, s2021, (1) | ((3) << 4));
  s2026 = _igen_dd_mm256_permute2f128_pd(s2014, s2022, (0) | ((2) << 4));
  s2027 = _igen_dd_mm256_permute2f128_pd(s2014, s2022, (1) | ((3) << 4));
  s2028 = _igen_dd_mm256_permute2f128_pd(s2015, s2023, (0) | ((2) << 4));
  s2029 = _igen_dd_mm256_permute2f128_pd(s2015, s2023, (1) | ((3) << 4));
  s2030 = _igen_dd_mm256_permute2f128_pd(s2016, s2024, (0) | ((2) << 4));
  s2031 = _igen_dd_mm256_permute2f128_pd(s2016, s2024, (1) | ((3) << 4));
  s2032 = _igen_dd_mm256_permute2f128_pd(s2017, s2025, (0) | ((2) << 4));
  s2033 = _igen_dd_mm256_permute2f128_pd(s2017, s2025, (1) | ((3) << 4));
  s2034 = _igen_dd_mm256_unpacklo_pd(t1460, t1476);
  s2035 = _igen_dd_mm256_unpackhi_pd(t1460, t1476);
  s2036 = _igen_dd_mm256_unpacklo_pd(t1461, t1477);
  s2037 = _igen_dd_mm256_unpackhi_pd(t1461, t1477);
  s2038 = _igen_dd_mm256_permute2f128_pd(s2034, s2035, (0) | ((2) << 4));
  s2039 = _igen_dd_mm256_permute2f128_pd(s2034, s2035, (1) | ((3) << 4));
  s2040 = _igen_dd_mm256_permute2f128_pd(s2036, s2037, (0) | ((2) << 4));
  s2041 = _igen_dd_mm256_permute2f128_pd(s2036, s2037, (1) | ((3) << 4));
  s2042 = _igen_dd_mm256_unpacklo_pd(t1492, t1508);
  s2043 = _igen_dd_mm256_unpackhi_pd(t1492, t1508);
  s2044 = _igen_dd_mm256_unpacklo_pd(t1493, t1509);
  s2045 = _igen_dd_mm256_unpackhi_pd(t1493, t1509);
  s2046 = _igen_dd_mm256_permute2f128_pd(s2042, s2043, (0) | ((2) << 4));
  s2047 = _igen_dd_mm256_permute2f128_pd(s2042, s2043, (1) | ((3) << 4));
  s2048 = _igen_dd_mm256_permute2f128_pd(s2044, s2045, (0) | ((2) << 4));
  s2049 = _igen_dd_mm256_permute2f128_pd(s2044, s2045, (1) | ((3) << 4));
  s2050 = _igen_dd_mm256_permute2f128_pd(s2038, s2046, (0) | ((2) << 4));
  s2051 = _igen_dd_mm256_permute2f128_pd(s2038, s2046, (1) | ((3) << 4));
  s2052 = _igen_dd_mm256_permute2f128_pd(s2039, s2047, (0) | ((2) << 4));
  s2053 = _igen_dd_mm256_permute2f128_pd(s2039, s2047, (1) | ((3) << 4));
  s2054 = _igen_dd_mm256_permute2f128_pd(s2040, s2048, (0) | ((2) << 4));
  s2055 = _igen_dd_mm256_permute2f128_pd(s2040, s2048, (1) | ((3) << 4));
  s2056 = _igen_dd_mm256_permute2f128_pd(s2041, s2049, (0) | ((2) << 4));
  s2057 = _igen_dd_mm256_permute2f128_pd(s2041, s2049, (1) | ((3) << 4));
  s2058 = *((a518 + 2));
  s2059 = *((a518 + 3));
  s2060 = _igen_dd_mm256_permute2f128_pd(s2058, s2059, (0) | ((2) << 4));
  s2061 = _igen_dd_mm256_permute2f128_pd(s2058, s2059, (1) | ((3) << 4));
  s2062 = _igen_dd_mm256_unpacklo_pd(s2060, s2061);
  s2063 = _igen_dd_mm256_unpackhi_pd(s2060, s2061);
  s2064 = *((a518 + 34));
  s2065 = *((a518 + 35));
  s2066 = _igen_dd_mm256_permute2f128_pd(s2064, s2065, (0) | ((2) << 4));
  s2067 = _igen_dd_mm256_permute2f128_pd(s2064, s2065, (1) | ((3) << 4));
  s2068 = _igen_dd_mm256_unpacklo_pd(s2066, s2067);
  s2069 = _igen_dd_mm256_unpackhi_pd(s2066, s2067);
  t1510 = _igen_dd_mm256_add_pd(s2062, s2068);
  t1511 = _igen_dd_mm256_add_pd(s2063, s2069);
  t1512 = _igen_dd_mm256_sub_pd(s2062, s2068);
  t1513 = _igen_dd_mm256_sub_pd(s2063, s2069);
  s2070 = *((a518 + 18));
  s2071 = *((a518 + 19));
  s2072 = _igen_dd_mm256_permute2f128_pd(s2070, s2071, (0) | ((2) << 4));
  s2073 = _igen_dd_mm256_permute2f128_pd(s2070, s2071, (1) | ((3) << 4));
  s2074 = _igen_dd_mm256_unpacklo_pd(s2072, s2073);
  s2075 = _igen_dd_mm256_unpackhi_pd(s2072, s2073);
  s2076 = *((a518 + 50));
  s2077 = *((a518 + 51));
  s2078 = _igen_dd_mm256_permute2f128_pd(s2076, s2077, (0) | ((2) << 4));
  s2079 = _igen_dd_mm256_permute2f128_pd(s2076, s2077, (1) | ((3) << 4));
  s2080 = _igen_dd_mm256_unpacklo_pd(s2078, s2079);
  s2081 = _igen_dd_mm256_unpackhi_pd(s2078, s2079);
  t1514 = _igen_dd_mm256_add_pd(s2074, s2080);
  t1515 = _igen_dd_mm256_add_pd(s2075, s2081);
  t1516 = _igen_dd_mm256_sub_pd(s2074, s2080);
  t1517 = _igen_dd_mm256_sub_pd(s2075, s2081);
  t1518 = _igen_dd_mm256_add_pd(t1510, t1514);
  t1519 = _igen_dd_mm256_add_pd(t1511, t1515);
  t1520 = _igen_dd_mm256_sub_pd(t1510, t1514);
  t1521 = _igen_dd_mm256_sub_pd(t1511, t1515);
  t1522 = _igen_dd_mm256_sub_pd(t1512, t1517);
  t1523 = _igen_dd_mm256_add_pd(t1513, t1516);
  t1524 = _igen_dd_mm256_add_pd(t1512, t1517);
  t1525 = _igen_dd_mm256_sub_pd(t1513, t1516);
  s2082 = *((a518 + 6));
  s2083 = *((a518 + 7));
  s2084 = _igen_dd_mm256_permute2f128_pd(s2082, s2083, (0) | ((2) << 4));
  s2085 = _igen_dd_mm256_permute2f128_pd(s2082, s2083, (1) | ((3) << 4));
  s2086 = _igen_dd_mm256_unpacklo_pd(s2084, s2085);
  s2087 = _igen_dd_mm256_unpackhi_pd(s2084, s2085);
  s2088 = *((a518 + 38));
  s2089 = *((a518 + 39));
  s2090 = _igen_dd_mm256_permute2f128_pd(s2088, s2089, (0) | ((2) << 4));
  s2091 = _igen_dd_mm256_permute2f128_pd(s2088, s2089, (1) | ((3) << 4));
  s2092 = _igen_dd_mm256_unpacklo_pd(s2090, s2091);
  s2093 = _igen_dd_mm256_unpackhi_pd(s2090, s2091);
  t1526 = _igen_dd_mm256_add_pd(s2086, s2092);
  t1527 = _igen_dd_mm256_add_pd(s2087, s2093);
  t1528 = _igen_dd_mm256_sub_pd(s2086, s2092);
  t1529 = _igen_dd_mm256_sub_pd(s2087, s2093);
  s2094 = *((a518 + 22));
  s2095 = *((a518 + 23));
  s2096 = _igen_dd_mm256_permute2f128_pd(s2094, s2095, (0) | ((2) << 4));
  s2097 = _igen_dd_mm256_permute2f128_pd(s2094, s2095, (1) | ((3) << 4));
  s2098 = _igen_dd_mm256_unpacklo_pd(s2096, s2097);
  s2099 = _igen_dd_mm256_unpackhi_pd(s2096, s2097);
  s2100 = *((a518 + 54));
  s2101 = *((a518 + 55));
  s2102 = _igen_dd_mm256_permute2f128_pd(s2100, s2101, (0) | ((2) << 4));
  s2103 = _igen_dd_mm256_permute2f128_pd(s2100, s2101, (1) | ((3) << 4));
  s2104 = _igen_dd_mm256_unpacklo_pd(s2102, s2103);
  s2105 = _igen_dd_mm256_unpackhi_pd(s2102, s2103);
  t1530 = _igen_dd_mm256_add_pd(s2098, s2104);
  t1531 = _igen_dd_mm256_add_pd(s2099, s2105);
  t1532 = _igen_dd_mm256_sub_pd(s2098, s2104);
  t1533 = _igen_dd_mm256_sub_pd(s2099, s2105);
  t1534 = _igen_dd_mm256_add_pd(t1526, t1530);
  t1535 = _igen_dd_mm256_add_pd(t1527, t1531);
  t1536 = _igen_dd_mm256_sub_pd(t1526, t1530);
  t1537 = _igen_dd_mm256_sub_pd(t1527, t1531);
  dd_I _t79 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t80 = _igen_dd_mm256_set1_pd(_t79);
  ddi_4 _t81 = _igen_dd_mm256_sub_pd(t1536, t1537);
  s2106 = _igen_dd_mm256_mul_pd(_t80, _t81);
  dd_I _t82 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t83 = _igen_dd_mm256_set1_pd(_t82);
  ddi_4 _t84 = _igen_dd_mm256_add_pd(t1536, t1537);
  s2107 = _igen_dd_mm256_mul_pd(_t83, _t84);
  t1538 = _igen_dd_mm256_sub_pd(t1528, t1533);
  t1539 = _igen_dd_mm256_add_pd(t1529, t1532);
  t1540 = _igen_dd_mm256_add_pd(t1528, t1533);
  t1541 = _igen_dd_mm256_sub_pd(t1529, t1532);
  dd_I _t85 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t86 = _igen_dd_mm256_set1_pd(_t85);
  dd_I _t87 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t88 = _igen_dd_mm256_set1_pd(_t87);
  ddi_4 _t89 = _igen_dd_mm256_mul_pd(_t86, t1538);
  ddi_4 _t90 = _igen_dd_mm256_mul_pd(_t88, t1539);
  s2108 = _igen_dd_mm256_sub_pd(_t89, _t90);
  dd_I _t91 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t92 = _igen_dd_mm256_set1_pd(_t91);
  dd_I _t93 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t94 = _igen_dd_mm256_set1_pd(_t93);
  ddi_4 _t95 = _igen_dd_mm256_mul_pd(_t92, t1538);
  ddi_4 _t96 = _igen_dd_mm256_mul_pd(_t94, t1539);
  s2109 = _igen_dd_mm256_add_pd(_t95, _t96);
  dd_I _t97 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t98 = _igen_dd_mm256_set1_pd(_t97);
  dd_I _t99 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t100 = _igen_dd_mm256_set1_pd(_t99);
  ddi_4 _t101 = _igen_dd_mm256_mul_pd(_t98, t1540);
  ddi_4 _t102 = _igen_dd_mm256_mul_pd(_t100, t1541);
  s2110 = _igen_dd_mm256_sub_pd(_t101, _t102);
  dd_I _t103 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t104 = _igen_dd_mm256_set1_pd(_t103);
  dd_I _t105 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t106 = _igen_dd_mm256_set1_pd(_t105);
  ddi_4 _t107 = _igen_dd_mm256_mul_pd(_t104, t1540);
  ddi_4 _t108 = _igen_dd_mm256_mul_pd(_t106, t1541);
  s2111 = _igen_dd_mm256_add_pd(_t107, _t108);
  s2112 = *((a518 + 10));
  s2113 = *((a518 + 11));
  s2114 = _igen_dd_mm256_permute2f128_pd(s2112, s2113, (0) | ((2) << 4));
  s2115 = _igen_dd_mm256_permute2f128_pd(s2112, s2113, (1) | ((3) << 4));
  s2116 = _igen_dd_mm256_unpacklo_pd(s2114, s2115);
  s2117 = _igen_dd_mm256_unpackhi_pd(s2114, s2115);
  s2118 = *((a518 + 42));
  s2119 = *((a518 + 43));
  s2120 = _igen_dd_mm256_permute2f128_pd(s2118, s2119, (0) | ((2) << 4));
  s2121 = _igen_dd_mm256_permute2f128_pd(s2118, s2119, (1) | ((3) << 4));
  s2122 = _igen_dd_mm256_unpacklo_pd(s2120, s2121);
  s2123 = _igen_dd_mm256_unpackhi_pd(s2120, s2121);
  t1542 = _igen_dd_mm256_add_pd(s2116, s2122);
  t1543 = _igen_dd_mm256_add_pd(s2117, s2123);
  t1544 = _igen_dd_mm256_sub_pd(s2116, s2122);
  t1545 = _igen_dd_mm256_sub_pd(s2117, s2123);
  s2124 = *((a518 + 26));
  s2125 = *((a518 + 27));
  s2126 = _igen_dd_mm256_permute2f128_pd(s2124, s2125, (0) | ((2) << 4));
  s2127 = _igen_dd_mm256_permute2f128_pd(s2124, s2125, (1) | ((3) << 4));
  s2128 = _igen_dd_mm256_unpacklo_pd(s2126, s2127);
  s2129 = _igen_dd_mm256_unpackhi_pd(s2126, s2127);
  s2130 = *((a518 + 58));
  s2131 = *((a518 + 59));
  s2132 = _igen_dd_mm256_permute2f128_pd(s2130, s2131, (0) | ((2) << 4));
  s2133 = _igen_dd_mm256_permute2f128_pd(s2130, s2131, (1) | ((3) << 4));
  s2134 = _igen_dd_mm256_unpacklo_pd(s2132, s2133);
  s2135 = _igen_dd_mm256_unpackhi_pd(s2132, s2133);
  t1546 = _igen_dd_mm256_add_pd(s2128, s2134);
  t1547 = _igen_dd_mm256_add_pd(s2129, s2135);
  t1548 = _igen_dd_mm256_sub_pd(s2128, s2134);
  t1549 = _igen_dd_mm256_sub_pd(s2129, s2135);
  t1550 = _igen_dd_mm256_add_pd(t1542, t1546);
  t1551 = _igen_dd_mm256_add_pd(t1543, t1547);
  t1552 = _igen_dd_mm256_sub_pd(t1542, t1546);
  t1553 = _igen_dd_mm256_sub_pd(t1543, t1547);
  t1554 = _igen_dd_mm256_sub_pd(t1544, t1549);
  t1555 = _igen_dd_mm256_add_pd(t1545, t1548);
  dd_I _t109 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t110 = _igen_dd_mm256_set1_pd(_t109);
  ddi_4 _t111 = _igen_dd_mm256_sub_pd(t1554, t1555);
  s2136 = _igen_dd_mm256_mul_pd(_t110, _t111);
  dd_I _t112 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t113 = _igen_dd_mm256_set1_pd(_t112);
  ddi_4 _t114 = _igen_dd_mm256_add_pd(t1554, t1555);
  s2137 = _igen_dd_mm256_mul_pd(_t113, _t114);
  dd_I _t115 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t116 = _ia_neg_dd(_t115);
  ddi_4 _t117 = _igen_dd_mm256_set1_pd(_t116);
  ddi_4 _t118 = _igen_dd_mm256_add_pd(t1544, t1549);
  a523 = _igen_dd_mm256_mul_pd(_t117, _t118);
  dd_I _t119 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t120 = _igen_dd_mm256_set1_pd(_t119);
  ddi_4 _t121 = _igen_dd_mm256_sub_pd(t1545, t1548);
  a524 = _igen_dd_mm256_mul_pd(_t120, _t121);
  s2138 = _igen_dd_mm256_sub_pd(a523, a524);
  s2139 = _igen_dd_mm256_add_pd(a523, a524);
  s2140 = *((a518 + 14));
  s2141 = *((a518 + 15));
  s2142 = _igen_dd_mm256_permute2f128_pd(s2140, s2141, (0) | ((2) << 4));
  s2143 = _igen_dd_mm256_permute2f128_pd(s2140, s2141, (1) | ((3) << 4));
  s2144 = _igen_dd_mm256_unpacklo_pd(s2142, s2143);
  s2145 = _igen_dd_mm256_unpackhi_pd(s2142, s2143);
  s2146 = *((a518 + 46));
  s2147 = *((a518 + 47));
  s2148 = _igen_dd_mm256_permute2f128_pd(s2146, s2147, (0) | ((2) << 4));
  s2149 = _igen_dd_mm256_permute2f128_pd(s2146, s2147, (1) | ((3) << 4));
  s2150 = _igen_dd_mm256_unpacklo_pd(s2148, s2149);
  s2151 = _igen_dd_mm256_unpackhi_pd(s2148, s2149);
  t1556 = _igen_dd_mm256_add_pd(s2144, s2150);
  t1557 = _igen_dd_mm256_add_pd(s2145, s2151);
  t1558 = _igen_dd_mm256_sub_pd(s2144, s2150);
  t1559 = _igen_dd_mm256_sub_pd(s2145, s2151);
  s2152 = *((a518 + 30));
  s2153 = *((a518 + 31));
  s2154 = _igen_dd_mm256_permute2f128_pd(s2152, s2153, (0) | ((2) << 4));
  s2155 = _igen_dd_mm256_permute2f128_pd(s2152, s2153, (1) | ((3) << 4));
  s2156 = _igen_dd_mm256_unpacklo_pd(s2154, s2155);
  s2157 = _igen_dd_mm256_unpackhi_pd(s2154, s2155);
  s2158 = *((a518 + 62));
  s2159 = *((a518 + 63));
  s2160 = _igen_dd_mm256_permute2f128_pd(s2158, s2159, (0) | ((2) << 4));
  s2161 = _igen_dd_mm256_permute2f128_pd(s2158, s2159, (1) | ((3) << 4));
  s2162 = _igen_dd_mm256_unpacklo_pd(s2160, s2161);
  s2163 = _igen_dd_mm256_unpackhi_pd(s2160, s2161);
  t1560 = _igen_dd_mm256_add_pd(s2156, s2162);
  t1561 = _igen_dd_mm256_add_pd(s2157, s2163);
  t1562 = _igen_dd_mm256_sub_pd(s2156, s2162);
  t1563 = _igen_dd_mm256_sub_pd(s2157, s2163);
  t1564 = _igen_dd_mm256_add_pd(t1556, t1560);
  t1565 = _igen_dd_mm256_add_pd(t1557, t1561);
  dd_I _t122 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t123 = _ia_neg_dd(_t122);
  ddi_4 _t124 = _igen_dd_mm256_set1_pd(_t123);
  ddi_4 _t125 = _igen_dd_mm256_sub_pd(t1556, t1560);
  a525 = _igen_dd_mm256_mul_pd(_t124, _t125);
  dd_I _t126 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t127 = _igen_dd_mm256_set1_pd(_t126);
  ddi_4 _t128 = _igen_dd_mm256_sub_pd(t1557, t1561);
  a526 = _igen_dd_mm256_mul_pd(_t127, _t128);
  s2164 = _igen_dd_mm256_sub_pd(a525, a526);
  s2165 = _igen_dd_mm256_add_pd(a525, a526);
  t1566 = _igen_dd_mm256_sub_pd(t1558, t1563);
  t1567 = _igen_dd_mm256_add_pd(t1559, t1562);
  t1568 = _igen_dd_mm256_add_pd(t1558, t1563);
  t1569 = _igen_dd_mm256_sub_pd(t1559, t1562);
  dd_I _t129 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t130 = _igen_dd_mm256_set1_pd(_t129);
  dd_I _t131 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t132 = _igen_dd_mm256_set1_pd(_t131);
  ddi_4 _t133 = _igen_dd_mm256_mul_pd(_t130, t1566);
  ddi_4 _t134 = _igen_dd_mm256_mul_pd(_t132, t1567);
  s2166 = _igen_dd_mm256_sub_pd(_t133, _t134);
  dd_I _t135 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t136 = _igen_dd_mm256_set1_pd(_t135);
  dd_I _t137 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t138 = _igen_dd_mm256_set1_pd(_t137);
  ddi_4 _t139 = _igen_dd_mm256_mul_pd(_t136, t1566);
  ddi_4 _t140 = _igen_dd_mm256_mul_pd(_t138, t1567);
  s2167 = _igen_dd_mm256_add_pd(_t139, _t140);
  dd_I _t141 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t142 = _ia_neg_dd(_t141);
  ddi_4 _t143 = _igen_dd_mm256_set1_pd(_t142);
  dd_I _t144 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t145 = _ia_neg_dd(_t144);
  ddi_4 _t146 = _igen_dd_mm256_set1_pd(_t145);
  ddi_4 _t147 = _igen_dd_mm256_mul_pd(_t143, t1568);
  ddi_4 _t148 = _igen_dd_mm256_mul_pd(_t146, t1569);
  s2168 = _igen_dd_mm256_sub_pd(_t147, _t148);
  dd_I _t149 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t150 = _ia_neg_dd(_t149);
  ddi_4 _t151 = _igen_dd_mm256_set1_pd(_t150);
  dd_I _t152 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t153 = _ia_neg_dd(_t152);
  ddi_4 _t154 = _igen_dd_mm256_set1_pd(_t153);
  ddi_4 _t155 = _igen_dd_mm256_mul_pd(_t151, t1568);
  ddi_4 _t156 = _igen_dd_mm256_mul_pd(_t154, t1569);
  s2169 = _igen_dd_mm256_add_pd(_t155, _t156);
  t1570 = _igen_dd_mm256_add_pd(t1518, t1550);
  t1571 = _igen_dd_mm256_add_pd(t1519, t1551);
  t1572 = _igen_dd_mm256_sub_pd(t1518, t1550);
  t1573 = _igen_dd_mm256_sub_pd(t1519, t1551);
  t1574 = _igen_dd_mm256_add_pd(t1534, t1564);
  t1575 = _igen_dd_mm256_add_pd(t1535, t1565);
  t1576 = _igen_dd_mm256_sub_pd(t1534, t1564);
  t1577 = _igen_dd_mm256_sub_pd(t1535, t1565);
  t1578 = _igen_dd_mm256_add_pd(t1570, t1574);
  t1579 = _igen_dd_mm256_add_pd(t1571, t1575);
  t1580 = _igen_dd_mm256_sub_pd(t1570, t1574);
  t1581 = _igen_dd_mm256_sub_pd(t1571, t1575);
  t1582 = _igen_dd_mm256_sub_pd(t1572, t1577);
  t1583 = _igen_dd_mm256_add_pd(t1573, t1576);
  t1584 = _igen_dd_mm256_add_pd(t1572, t1577);
  t1585 = _igen_dd_mm256_sub_pd(t1573, t1576);
  t1586 = _igen_dd_mm256_add_pd(t1522, s2136);
  t1587 = _igen_dd_mm256_add_pd(t1523, s2137);
  t1588 = _igen_dd_mm256_sub_pd(t1522, s2136);
  t1589 = _igen_dd_mm256_sub_pd(t1523, s2137);
  t1590 = _igen_dd_mm256_add_pd(s2108, s2166);
  t1591 = _igen_dd_mm256_add_pd(s2109, s2167);
  t1592 = _igen_dd_mm256_sub_pd(s2108, s2166);
  t1593 = _igen_dd_mm256_sub_pd(s2109, s2167);
  t1594 = _igen_dd_mm256_add_pd(t1586, t1590);
  t1595 = _igen_dd_mm256_add_pd(t1587, t1591);
  t1596 = _igen_dd_mm256_sub_pd(t1586, t1590);
  t1597 = _igen_dd_mm256_sub_pd(t1587, t1591);
  t1598 = _igen_dd_mm256_sub_pd(t1588, t1593);
  t1599 = _igen_dd_mm256_add_pd(t1589, t1592);
  t1600 = _igen_dd_mm256_add_pd(t1588, t1593);
  t1601 = _igen_dd_mm256_sub_pd(t1589, t1592);
  t1602 = _igen_dd_mm256_sub_pd(t1520, t1553);
  t1603 = _igen_dd_mm256_add_pd(t1521, t1552);
  t1604 = _igen_dd_mm256_add_pd(t1520, t1553);
  t1605 = _igen_dd_mm256_sub_pd(t1521, t1552);
  t1606 = _igen_dd_mm256_add_pd(s2106, s2164);
  t1607 = _igen_dd_mm256_sub_pd(s2107, s2165);
  t1608 = _igen_dd_mm256_sub_pd(s2106, s2164);
  t1609 = _igen_dd_mm256_add_pd(s2107, s2165);
  t1610 = _igen_dd_mm256_add_pd(t1602, t1606);
  t1611 = _igen_dd_mm256_add_pd(t1603, t1607);
  t1612 = _igen_dd_mm256_sub_pd(t1602, t1606);
  t1613 = _igen_dd_mm256_sub_pd(t1603, t1607);
  t1614 = _igen_dd_mm256_sub_pd(t1604, t1609);
  t1615 = _igen_dd_mm256_add_pd(t1605, t1608);
  t1616 = _igen_dd_mm256_add_pd(t1604, t1609);
  t1617 = _igen_dd_mm256_sub_pd(t1605, t1608);
  t1618 = _igen_dd_mm256_add_pd(t1524, s2138);
  t1619 = _igen_dd_mm256_sub_pd(t1525, s2139);
  t1620 = _igen_dd_mm256_sub_pd(t1524, s2138);
  t1621 = _igen_dd_mm256_add_pd(t1525, s2139);
  t1622 = _igen_dd_mm256_add_pd(s2110, s2168);
  t1623 = _igen_dd_mm256_add_pd(s2111, s2169);
  t1624 = _igen_dd_mm256_sub_pd(s2110, s2168);
  t1625 = _igen_dd_mm256_sub_pd(s2111, s2169);
  t1626 = _igen_dd_mm256_add_pd(t1618, t1622);
  t1627 = _igen_dd_mm256_add_pd(t1619, t1623);
  t1628 = _igen_dd_mm256_sub_pd(t1618, t1622);
  t1629 = _igen_dd_mm256_sub_pd(t1619, t1623);
  t1630 = _igen_dd_mm256_sub_pd(t1620, t1625);
  t1631 = _igen_dd_mm256_add_pd(t1621, t1624);
  t1632 = _igen_dd_mm256_add_pd(t1620, t1625);
  t1633 = _igen_dd_mm256_sub_pd(t1621, t1624);
  s2170 = _igen_dd_mm256_unpacklo_pd(t1578, t1594);
  s2171 = _igen_dd_mm256_unpackhi_pd(t1578, t1594);
  s2172 = _igen_dd_mm256_unpacklo_pd(t1579, t1595);
  s2173 = _igen_dd_mm256_unpackhi_pd(t1579, t1595);
  s2174 = _igen_dd_mm256_permute2f128_pd(s2170, s2171, (0) | ((2) << 4));
  s2175 = _igen_dd_mm256_permute2f128_pd(s2170, s2171, (1) | ((3) << 4));
  s2176 = _igen_dd_mm256_permute2f128_pd(s2172, s2173, (0) | ((2) << 4));
  s2177 = _igen_dd_mm256_permute2f128_pd(s2172, s2173, (1) | ((3) << 4));
  s2178 = _igen_dd_mm256_unpacklo_pd(t1610, t1626);
  s2179 = _igen_dd_mm256_unpackhi_pd(t1610, t1626);
  s2180 = _igen_dd_mm256_unpacklo_pd(t1611, t1627);
  s2181 = _igen_dd_mm256_unpackhi_pd(t1611, t1627);
  s2182 = _igen_dd_mm256_permute2f128_pd(s2178, s2179, (0) | ((2) << 4));
  s2183 = _igen_dd_mm256_permute2f128_pd(s2178, s2179, (1) | ((3) << 4));
  s2184 = _igen_dd_mm256_permute2f128_pd(s2180, s2181, (0) | ((2) << 4));
  s2185 = _igen_dd_mm256_permute2f128_pd(s2180, s2181, (1) | ((3) << 4));
  s2186 = _igen_dd_mm256_permute2f128_pd(s2174, s2182, (0) | ((2) << 4));
  s2187 = _igen_dd_mm256_permute2f128_pd(s2174, s2182, (1) | ((3) << 4));
  s2188 = _igen_dd_mm256_permute2f128_pd(s2175, s2183, (0) | ((2) << 4));
  s2189 = _igen_dd_mm256_permute2f128_pd(s2175, s2183, (1) | ((3) << 4));
  s2190 = _igen_dd_mm256_permute2f128_pd(s2176, s2184, (0) | ((2) << 4));
  s2191 = _igen_dd_mm256_permute2f128_pd(s2176, s2184, (1) | ((3) << 4));
  s2192 = _igen_dd_mm256_permute2f128_pd(s2177, s2185, (0) | ((2) << 4));
  s2193 = _igen_dd_mm256_permute2f128_pd(s2177, s2185, (1) | ((3) << 4));
  s2194 = _igen_dd_mm256_unpacklo_pd(t1582, t1598);
  s2195 = _igen_dd_mm256_unpackhi_pd(t1582, t1598);
  s2196 = _igen_dd_mm256_unpacklo_pd(t1583, t1599);
  s2197 = _igen_dd_mm256_unpackhi_pd(t1583, t1599);
  s2198 = _igen_dd_mm256_permute2f128_pd(s2194, s2195, (0) | ((2) << 4));
  s2199 = _igen_dd_mm256_permute2f128_pd(s2194, s2195, (1) | ((3) << 4));
  s2200 = _igen_dd_mm256_permute2f128_pd(s2196, s2197, (0) | ((2) << 4));
  s2201 = _igen_dd_mm256_permute2f128_pd(s2196, s2197, (1) | ((3) << 4));
  s2202 = _igen_dd_mm256_unpacklo_pd(t1614, t1630);
  s2203 = _igen_dd_mm256_unpackhi_pd(t1614, t1630);
  s2204 = _igen_dd_mm256_unpacklo_pd(t1615, t1631);
  s2205 = _igen_dd_mm256_unpackhi_pd(t1615, t1631);
  s2206 = _igen_dd_mm256_permute2f128_pd(s2202, s2203, (0) | ((2) << 4));
  s2207 = _igen_dd_mm256_permute2f128_pd(s2202, s2203, (1) | ((3) << 4));
  s2208 = _igen_dd_mm256_permute2f128_pd(s2204, s2205, (0) | ((2) << 4));
  s2209 = _igen_dd_mm256_permute2f128_pd(s2204, s2205, (1) | ((3) << 4));
  s2210 = _igen_dd_mm256_permute2f128_pd(s2198, s2206, (0) | ((2) << 4));
  s2211 = _igen_dd_mm256_permute2f128_pd(s2198, s2206, (1) | ((3) << 4));
  s2212 = _igen_dd_mm256_permute2f128_pd(s2199, s2207, (0) | ((2) << 4));
  s2213 = _igen_dd_mm256_permute2f128_pd(s2199, s2207, (1) | ((3) << 4));
  s2214 = _igen_dd_mm256_permute2f128_pd(s2200, s2208, (0) | ((2) << 4));
  s2215 = _igen_dd_mm256_permute2f128_pd(s2200, s2208, (1) | ((3) << 4));
  s2216 = _igen_dd_mm256_permute2f128_pd(s2201, s2209, (0) | ((2) << 4));
  s2217 = _igen_dd_mm256_permute2f128_pd(s2201, s2209, (1) | ((3) << 4));
  s2218 = _igen_dd_mm256_unpacklo_pd(t1580, t1596);
  s2219 = _igen_dd_mm256_unpackhi_pd(t1580, t1596);
  s2220 = _igen_dd_mm256_unpacklo_pd(t1581, t1597);
  s2221 = _igen_dd_mm256_unpackhi_pd(t1581, t1597);
  s2222 = _igen_dd_mm256_permute2f128_pd(s2218, s2219, (0) | ((2) << 4));
  s2223 = _igen_dd_mm256_permute2f128_pd(s2218, s2219, (1) | ((3) << 4));
  s2224 = _igen_dd_mm256_permute2f128_pd(s2220, s2221, (0) | ((2) << 4));
  s2225 = _igen_dd_mm256_permute2f128_pd(s2220, s2221, (1) | ((3) << 4));
  s2226 = _igen_dd_mm256_unpacklo_pd(t1612, t1628);
  s2227 = _igen_dd_mm256_unpackhi_pd(t1612, t1628);
  s2228 = _igen_dd_mm256_unpacklo_pd(t1613, t1629);
  s2229 = _igen_dd_mm256_unpackhi_pd(t1613, t1629);
  s2230 = _igen_dd_mm256_permute2f128_pd(s2226, s2227, (0) | ((2) << 4));
  s2231 = _igen_dd_mm256_permute2f128_pd(s2226, s2227, (1) | ((3) << 4));
  s2232 = _igen_dd_mm256_permute2f128_pd(s2228, s2229, (0) | ((2) << 4));
  s2233 = _igen_dd_mm256_permute2f128_pd(s2228, s2229, (1) | ((3) << 4));
  s2234 = _igen_dd_mm256_permute2f128_pd(s2222, s2230, (0) | ((2) << 4));
  s2235 = _igen_dd_mm256_permute2f128_pd(s2222, s2230, (1) | ((3) << 4));
  s2236 = _igen_dd_mm256_permute2f128_pd(s2223, s2231, (0) | ((2) << 4));
  s2237 = _igen_dd_mm256_permute2f128_pd(s2223, s2231, (1) | ((3) << 4));
  s2238 = _igen_dd_mm256_permute2f128_pd(s2224, s2232, (0) | ((2) << 4));
  s2239 = _igen_dd_mm256_permute2f128_pd(s2224, s2232, (1) | ((3) << 4));
  s2240 = _igen_dd_mm256_permute2f128_pd(s2225, s2233, (0) | ((2) << 4));
  s2241 = _igen_dd_mm256_permute2f128_pd(s2225, s2233, (1) | ((3) << 4));
  s2242 = _igen_dd_mm256_unpacklo_pd(t1584, t1600);
  s2243 = _igen_dd_mm256_unpackhi_pd(t1584, t1600);
  s2244 = _igen_dd_mm256_unpacklo_pd(t1585, t1601);
  s2245 = _igen_dd_mm256_unpackhi_pd(t1585, t1601);
  s2246 = _igen_dd_mm256_permute2f128_pd(s2242, s2243, (0) | ((2) << 4));
  s2247 = _igen_dd_mm256_permute2f128_pd(s2242, s2243, (1) | ((3) << 4));
  s2248 = _igen_dd_mm256_permute2f128_pd(s2244, s2245, (0) | ((2) << 4));
  s2249 = _igen_dd_mm256_permute2f128_pd(s2244, s2245, (1) | ((3) << 4));
  s2250 = _igen_dd_mm256_unpacklo_pd(t1616, t1632);
  s2251 = _igen_dd_mm256_unpackhi_pd(t1616, t1632);
  s2252 = _igen_dd_mm256_unpacklo_pd(t1617, t1633);
  s2253 = _igen_dd_mm256_unpackhi_pd(t1617, t1633);
  s2254 = _igen_dd_mm256_permute2f128_pd(s2250, s2251, (0) | ((2) << 4));
  s2255 = _igen_dd_mm256_permute2f128_pd(s2250, s2251, (1) | ((3) << 4));
  s2256 = _igen_dd_mm256_permute2f128_pd(s2252, s2253, (0) | ((2) << 4));
  s2257 = _igen_dd_mm256_permute2f128_pd(s2252, s2253, (1) | ((3) << 4));
  s2258 = _igen_dd_mm256_permute2f128_pd(s2246, s2254, (0) | ((2) << 4));
  s2259 = _igen_dd_mm256_permute2f128_pd(s2246, s2254, (1) | ((3) << 4));
  s2260 = _igen_dd_mm256_permute2f128_pd(s2247, s2255, (0) | ((2) << 4));
  s2261 = _igen_dd_mm256_permute2f128_pd(s2247, s2255, (1) | ((3) << 4));
  s2262 = _igen_dd_mm256_permute2f128_pd(s2248, s2256, (0) | ((2) << 4));
  s2263 = _igen_dd_mm256_permute2f128_pd(s2248, s2256, (1) | ((3) << 4));
  s2264 = _igen_dd_mm256_permute2f128_pd(s2249, s2257, (0) | ((2) << 4));
  s2265 = _igen_dd_mm256_permute2f128_pd(s2249, s2257, (1) | ((3) << 4));
  dd_I _t157 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t158 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t159 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t160 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t161 = _igen_dd_mm256_set_pd(_t157, _t158, _t159, _t160);
  dd_I _t162 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t163 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t164 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t165 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t166 = _igen_dd_mm256_set_pd(_t162, _t163, _t164, _t165);
  ddi_4 _t167 = _igen_dd_mm256_mul_pd(_t161, s2186);
  ddi_4 _t168 = _igen_dd_mm256_mul_pd(_t166, s2190);
  s2266 = _igen_dd_mm256_sub_pd(_t167, _t168);
  dd_I _t169 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t170 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t171 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t172 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t173 = _igen_dd_mm256_set_pd(_t169, _t170, _t171, _t172);
  dd_I _t174 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t175 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t176 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t177 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t178 = _igen_dd_mm256_set_pd(_t174, _t175, _t176, _t177);
  ddi_4 _t179 = _igen_dd_mm256_mul_pd(_t173, s2186);
  ddi_4 _t180 = _igen_dd_mm256_mul_pd(_t178, s2190);
  s2267 = _igen_dd_mm256_add_pd(_t179, _t180);
  t1634 = _igen_dd_mm256_add_pd(s1978, s2266);
  t1635 = _igen_dd_mm256_add_pd(s1982, s2267);
  t1636 = _igen_dd_mm256_sub_pd(s1978, s2266);
  t1637 = _igen_dd_mm256_sub_pd(s1982, s2267);
  dd_I _t181 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t182 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t183 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t184 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t185 = _igen_dd_mm256_set_pd(_t181, _t182, _t183, _t184);
  dd_I _t186 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t187 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t188 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t189 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t190 = _igen_dd_mm256_set_pd(_t186, _t187, _t188, _t189);
  ddi_4 _t191 = _igen_dd_mm256_mul_pd(_t185, s1979);
  ddi_4 _t192 = _igen_dd_mm256_mul_pd(_t190, s1983);
  s2268 = _igen_dd_mm256_sub_pd(_t191, _t192);
  dd_I _t193 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t194 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t195 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t196 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t197 = _igen_dd_mm256_set_pd(_t193, _t194, _t195, _t196);
  dd_I _t198 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t199 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t200 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t201 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t202 = _igen_dd_mm256_set_pd(_t198, _t199, _t200, _t201);
  ddi_4 _t203 = _igen_dd_mm256_mul_pd(_t197, s1979);
  ddi_4 _t204 = _igen_dd_mm256_mul_pd(_t202, s1983);
  s2269 = _igen_dd_mm256_add_pd(_t203, _t204);
  dd_I _t205 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t206 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t207 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t208 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t209 = _igen_dd_mm256_set_pd(_t205, _t206, _t207, _t208);
  dd_I _t210 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t211 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t212 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t213 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t214 = _igen_dd_mm256_set_pd(_t210, _t211, _t212, _t213);
  ddi_4 _t215 = _igen_dd_mm256_mul_pd(_t209, s2187);
  ddi_4 _t216 = _igen_dd_mm256_mul_pd(_t214, s2191);
  s2270 = _igen_dd_mm256_sub_pd(_t215, _t216);
  dd_I _t217 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t218 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t219 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t220 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t221 = _igen_dd_mm256_set_pd(_t217, _t218, _t219, _t220);
  dd_I _t222 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t223 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t224 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t225 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t226 = _igen_dd_mm256_set_pd(_t222, _t223, _t224, _t225);
  ddi_4 _t227 = _igen_dd_mm256_mul_pd(_t221, s2187);
  ddi_4 _t228 = _igen_dd_mm256_mul_pd(_t226, s2191);
  s2271 = _igen_dd_mm256_add_pd(_t227, _t228);
  t1638 = _igen_dd_mm256_add_pd(s2268, s2270);
  t1639 = _igen_dd_mm256_add_pd(s2269, s2271);
  t1640 = _igen_dd_mm256_sub_pd(s2268, s2270);
  t1641 = _igen_dd_mm256_sub_pd(s2269, s2271);
  dd_I _t229 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t230 = _igen_dd_mm256_set1_pd(_t229);
  ddi_4 _t231 = _igen_dd_mm256_sub_pd(t1640, t1641);
  s2272 = _igen_dd_mm256_mul_pd(_t230, _t231);
  dd_I _t232 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t233 = _igen_dd_mm256_set1_pd(_t232);
  ddi_4 _t234 = _igen_dd_mm256_add_pd(t1640, t1641);
  s2273 = _igen_dd_mm256_mul_pd(_t233, _t234);
  dd_I _t235 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t236 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t237 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t238 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t239 = _igen_dd_mm256_set_pd(_t235, _t236, _t237, _t238);
  dd_I _t240 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t241 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t242 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t243 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t244 = _igen_dd_mm256_set_pd(_t240, _t241, _t242, _t243);
  ddi_4 _t245 = _igen_dd_mm256_mul_pd(_t239, s1980);
  ddi_4 _t246 = _igen_dd_mm256_mul_pd(_t244, s1984);
  s2274 = _igen_dd_mm256_sub_pd(_t245, _t246);
  dd_I _t247 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t248 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t249 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t250 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t251 = _igen_dd_mm256_set_pd(_t247, _t248, _t249, _t250);
  dd_I _t252 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t253 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t254 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t255 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t256 = _igen_dd_mm256_set_pd(_t252, _t253, _t254, _t255);
  ddi_4 _t257 = _igen_dd_mm256_mul_pd(_t251, s1980);
  ddi_4 _t258 = _igen_dd_mm256_mul_pd(_t256, s1984);
  s2275 = _igen_dd_mm256_add_pd(_t257, _t258);
  dd_I _t259 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t260 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t261 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t262 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t263 = _igen_dd_mm256_set_pd(_t259, _t260, _t261, _t262);
  dd_I _t264 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t265 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t266 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t267 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t268 = _igen_dd_mm256_set_pd(_t264, _t265, _t266, _t267);
  ddi_4 _t269 = _igen_dd_mm256_mul_pd(_t263, s2188);
  ddi_4 _t270 = _igen_dd_mm256_mul_pd(_t268, s2192);
  s2276 = _igen_dd_mm256_sub_pd(_t269, _t270);
  dd_I _t271 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t272 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t273 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t274 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t275 = _igen_dd_mm256_set_pd(_t271, _t272, _t273, _t274);
  dd_I _t276 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t277 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t278 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t279 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t280 = _igen_dd_mm256_set_pd(_t276, _t277, _t278, _t279);
  ddi_4 _t281 = _igen_dd_mm256_mul_pd(_t275, s2188);
  ddi_4 _t282 = _igen_dd_mm256_mul_pd(_t280, s2192);
  s2277 = _igen_dd_mm256_add_pd(_t281, _t282);
  t1642 = _igen_dd_mm256_add_pd(s2274, s2276);
  t1643 = _igen_dd_mm256_add_pd(s2275, s2277);
  t1644 = _igen_dd_mm256_sub_pd(s2274, s2276);
  t1645 = _igen_dd_mm256_sub_pd(s2275, s2277);
  dd_I _t283 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t284 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t285 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t286 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t287 = _igen_dd_mm256_set_pd(_t283, _t284, _t285, _t286);
  dd_I _t288 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t289 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t290 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t291 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t292 = _igen_dd_mm256_set_pd(_t288, _t289, _t290, _t291);
  ddi_4 _t293 = _igen_dd_mm256_mul_pd(_t287, s1981);
  ddi_4 _t294 = _igen_dd_mm256_mul_pd(_t292, s1985);
  s2278 = _igen_dd_mm256_sub_pd(_t293, _t294);
  dd_I _t295 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t296 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t297 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t298 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t299 = _igen_dd_mm256_set_pd(_t295, _t296, _t297, _t298);
  dd_I _t300 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t301 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t302 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t303 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t304 = _igen_dd_mm256_set_pd(_t300, _t301, _t302, _t303);
  ddi_4 _t305 = _igen_dd_mm256_mul_pd(_t299, s1981);
  ddi_4 _t306 = _igen_dd_mm256_mul_pd(_t304, s1985);
  s2279 = _igen_dd_mm256_add_pd(_t305, _t306);
  dd_I _t307 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t308 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t309 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t310 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t311 = _igen_dd_mm256_set_pd(_t307, _t308, _t309, _t310);
  dd_I _t312 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t313 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t314 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t315 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t316 = _igen_dd_mm256_set_pd(_t312, _t313, _t314, _t315);
  ddi_4 _t317 = _igen_dd_mm256_mul_pd(_t311, s2189);
  ddi_4 _t318 = _igen_dd_mm256_mul_pd(_t316, s2193);
  s2280 = _igen_dd_mm256_sub_pd(_t317, _t318);
  dd_I _t319 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t320 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t321 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t322 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t323 = _igen_dd_mm256_set_pd(_t319, _t320, _t321, _t322);
  dd_I _t324 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t325 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t326 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t327 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t328 = _igen_dd_mm256_set_pd(_t324, _t325, _t326, _t327);
  ddi_4 _t329 = _igen_dd_mm256_mul_pd(_t323, s2189);
  ddi_4 _t330 = _igen_dd_mm256_mul_pd(_t328, s2193);
  s2281 = _igen_dd_mm256_add_pd(_t329, _t330);
  t1646 = _igen_dd_mm256_add_pd(s2278, s2280);
  t1647 = _igen_dd_mm256_add_pd(s2279, s2281);
  dd_I _t331 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t332 = _ia_neg_dd(_t331);
  ddi_4 _t333 = _igen_dd_mm256_set1_pd(_t332);
  ddi_4 _t334 = _igen_dd_mm256_sub_pd(s2278, s2280);
  a527 = _igen_dd_mm256_mul_pd(_t333, _t334);
  dd_I _t335 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t336 = _igen_dd_mm256_set1_pd(_t335);
  ddi_4 _t337 = _igen_dd_mm256_sub_pd(s2279, s2281);
  a528 = _igen_dd_mm256_mul_pd(_t336, _t337);
  s2282 = _igen_dd_mm256_sub_pd(a527, a528);
  s2283 = _igen_dd_mm256_add_pd(a527, a528);
  t1648 = _igen_dd_mm256_add_pd(t1634, t1642);
  t1649 = _igen_dd_mm256_add_pd(t1635, t1643);
  t1650 = _igen_dd_mm256_sub_pd(t1634, t1642);
  t1651 = _igen_dd_mm256_sub_pd(t1635, t1643);
  t1652 = _igen_dd_mm256_add_pd(t1638, t1646);
  t1653 = _igen_dd_mm256_add_pd(t1639, t1647);
  t1654 = _igen_dd_mm256_sub_pd(t1638, t1646);
  t1655 = _igen_dd_mm256_sub_pd(t1639, t1647);
  t1656 = _igen_dd_mm256_add_pd(t1648, t1652);
  t1657 = _igen_dd_mm256_add_pd(t1649, t1653);
  t1658 = _igen_dd_mm256_sub_pd(t1648, t1652);
  t1659 = _igen_dd_mm256_sub_pd(t1649, t1653);
  s2284 = _igen_dd_mm256_unpacklo_pd(t1656, t1657);
  s2285 = _igen_dd_mm256_unpackhi_pd(t1656, t1657);
  a529 = ((ddi_4 *)Y);
  s2286 = _igen_dd_mm256_permute2f128_pd(s2284, s2285, (0) | ((2) << 4));
  *(a529) = s2286;
  s2287 = _igen_dd_mm256_permute2f128_pd(s2284, s2285, (1) | ((3) << 4));
  *((a529 + 1)) = s2287;
  s2288 = _igen_dd_mm256_unpacklo_pd(t1658, t1659);
  s2289 = _igen_dd_mm256_unpackhi_pd(t1658, t1659);
  s2290 = _igen_dd_mm256_permute2f128_pd(s2288, s2289, (0) | ((2) << 4));
  *((a529 + 32)) = s2290;
  s2291 = _igen_dd_mm256_permute2f128_pd(s2288, s2289, (1) | ((3) << 4));
  *((a529 + 33)) = s2291;
  t1660 = _igen_dd_mm256_sub_pd(t1650, t1655);
  t1661 = _igen_dd_mm256_add_pd(t1651, t1654);
  t1662 = _igen_dd_mm256_add_pd(t1650, t1655);
  t1663 = _igen_dd_mm256_sub_pd(t1651, t1654);
  s2292 = _igen_dd_mm256_unpacklo_pd(t1660, t1661);
  s2293 = _igen_dd_mm256_unpackhi_pd(t1660, t1661);
  s2294 = _igen_dd_mm256_permute2f128_pd(s2292, s2293, (0) | ((2) << 4));
  *((a529 + 16)) = s2294;
  s2295 = _igen_dd_mm256_permute2f128_pd(s2292, s2293, (1) | ((3) << 4));
  *((a529 + 17)) = s2295;
  s2296 = _igen_dd_mm256_unpacklo_pd(t1662, t1663);
  s2297 = _igen_dd_mm256_unpackhi_pd(t1662, t1663);
  s2298 = _igen_dd_mm256_permute2f128_pd(s2296, s2297, (0) | ((2) << 4));
  *((a529 + 48)) = s2298;
  s2299 = _igen_dd_mm256_permute2f128_pd(s2296, s2297, (1) | ((3) << 4));
  *((a529 + 49)) = s2299;
  t1664 = _igen_dd_mm256_sub_pd(t1636, t1645);
  t1665 = _igen_dd_mm256_add_pd(t1637, t1644);
  t1666 = _igen_dd_mm256_add_pd(t1636, t1645);
  t1667 = _igen_dd_mm256_sub_pd(t1637, t1644);
  t1668 = _igen_dd_mm256_add_pd(s2272, s2282);
  t1669 = _igen_dd_mm256_sub_pd(s2273, s2283);
  t1670 = _igen_dd_mm256_sub_pd(s2272, s2282);
  t1671 = _igen_dd_mm256_add_pd(s2273, s2283);
  t1672 = _igen_dd_mm256_add_pd(t1664, t1668);
  t1673 = _igen_dd_mm256_add_pd(t1665, t1669);
  t1674 = _igen_dd_mm256_sub_pd(t1664, t1668);
  t1675 = _igen_dd_mm256_sub_pd(t1665, t1669);
  s2300 = _igen_dd_mm256_unpacklo_pd(t1672, t1673);
  s2301 = _igen_dd_mm256_unpackhi_pd(t1672, t1673);
  s2302 = _igen_dd_mm256_permute2f128_pd(s2300, s2301, (0) | ((2) << 4));
  *((a529 + 8)) = s2302;
  s2303 = _igen_dd_mm256_permute2f128_pd(s2300, s2301, (1) | ((3) << 4));
  *((a529 + 9)) = s2303;
  s2304 = _igen_dd_mm256_unpacklo_pd(t1674, t1675);
  s2305 = _igen_dd_mm256_unpackhi_pd(t1674, t1675);
  s2306 = _igen_dd_mm256_permute2f128_pd(s2304, s2305, (0) | ((2) << 4));
  *((a529 + 40)) = s2306;
  s2307 = _igen_dd_mm256_permute2f128_pd(s2304, s2305, (1) | ((3) << 4));
  *((a529 + 41)) = s2307;
  t1676 = _igen_dd_mm256_sub_pd(t1666, t1671);
  t1677 = _igen_dd_mm256_add_pd(t1667, t1670);
  t1678 = _igen_dd_mm256_add_pd(t1666, t1671);
  t1679 = _igen_dd_mm256_sub_pd(t1667, t1670);
  s2308 = _igen_dd_mm256_unpacklo_pd(t1676, t1677);
  s2309 = _igen_dd_mm256_unpackhi_pd(t1676, t1677);
  s2310 = _igen_dd_mm256_permute2f128_pd(s2308, s2309, (0) | ((2) << 4));
  *((a529 + 24)) = s2310;
  s2311 = _igen_dd_mm256_permute2f128_pd(s2308, s2309, (1) | ((3) << 4));
  *((a529 + 25)) = s2311;
  s2312 = _igen_dd_mm256_unpacklo_pd(t1678, t1679);
  s2313 = _igen_dd_mm256_unpackhi_pd(t1678, t1679);
  s2314 = _igen_dd_mm256_permute2f128_pd(s2312, s2313, (0) | ((2) << 4));
  *((a529 + 56)) = s2314;
  s2315 = _igen_dd_mm256_permute2f128_pd(s2312, s2313, (1) | ((3) << 4));
  *((a529 + 57)) = s2315;
  dd_I _t338 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t339 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t340 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t341 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t342 = _igen_dd_mm256_set_pd(_t338, _t339, _t340, _t341);
  dd_I _t343 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t344 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t345 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t346 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t347 = _igen_dd_mm256_set_pd(_t343, _t344, _t345, _t346);
  ddi_4 _t348 = _igen_dd_mm256_mul_pd(_t342, s2210);
  ddi_4 _t349 = _igen_dd_mm256_mul_pd(_t347, s2214);
  s2316 = _igen_dd_mm256_sub_pd(_t348, _t349);
  dd_I _t350 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t351 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t352 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t353 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t354 = _igen_dd_mm256_set_pd(_t350, _t351, _t352, _t353);
  dd_I _t355 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t356 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t357 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t358 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t359 = _igen_dd_mm256_set_pd(_t355, _t356, _t357, _t358);
  ddi_4 _t360 = _igen_dd_mm256_mul_pd(_t354, s2210);
  ddi_4 _t361 = _igen_dd_mm256_mul_pd(_t359, s2214);
  s2317 = _igen_dd_mm256_add_pd(_t360, _t361);
  t1680 = _igen_dd_mm256_add_pd(s2002, s2316);
  t1681 = _igen_dd_mm256_add_pd(s2006, s2317);
  t1682 = _igen_dd_mm256_sub_pd(s2002, s2316);
  t1683 = _igen_dd_mm256_sub_pd(s2006, s2317);
  dd_I _t362 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t363 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t364 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t365 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t366 = _igen_dd_mm256_set_pd(_t362, _t363, _t364, _t365);
  dd_I _t367 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t368 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t369 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t370 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t371 = _igen_dd_mm256_set_pd(_t367, _t368, _t369, _t370);
  ddi_4 _t372 = _igen_dd_mm256_mul_pd(_t366, s2003);
  ddi_4 _t373 = _igen_dd_mm256_mul_pd(_t371, s2007);
  s2318 = _igen_dd_mm256_sub_pd(_t372, _t373);
  dd_I _t374 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t375 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t376 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t377 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t378 = _igen_dd_mm256_set_pd(_t374, _t375, _t376, _t377);
  dd_I _t379 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t380 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t381 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t382 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t383 = _igen_dd_mm256_set_pd(_t379, _t380, _t381, _t382);
  ddi_4 _t384 = _igen_dd_mm256_mul_pd(_t378, s2003);
  ddi_4 _t385 = _igen_dd_mm256_mul_pd(_t383, s2007);
  s2319 = _igen_dd_mm256_add_pd(_t384, _t385);
  dd_I _t386 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t387 = _ia_neg_dd(_t386);
  dd_I _t388 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t389 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t390 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t391 = _igen_dd_mm256_set_pd(_t387, _t388, _t389, _t390);
  dd_I _t392 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t393 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t394 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t395 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t396 = _igen_dd_mm256_set_pd(_t392, _t393, _t394, _t395);
  ddi_4 _t397 = _igen_dd_mm256_mul_pd(_t391, s2211);
  ddi_4 _t398 = _igen_dd_mm256_mul_pd(_t396, s2215);
  s2320 = _igen_dd_mm256_sub_pd(_t397, _t398);
  dd_I _t399 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t400 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t401 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t402 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t403 = _igen_dd_mm256_set_pd(_t399, _t400, _t401, _t402);
  dd_I _t404 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t405 = _ia_neg_dd(_t404);
  dd_I _t406 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t407 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t408 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t409 = _igen_dd_mm256_set_pd(_t405, _t406, _t407, _t408);
  ddi_4 _t410 = _igen_dd_mm256_mul_pd(_t403, s2211);
  ddi_4 _t411 = _igen_dd_mm256_mul_pd(_t409, s2215);
  s2321 = _igen_dd_mm256_add_pd(_t410, _t411);
  t1684 = _igen_dd_mm256_add_pd(s2318, s2320);
  t1685 = _igen_dd_mm256_add_pd(s2319, s2321);
  t1686 = _igen_dd_mm256_sub_pd(s2318, s2320);
  t1687 = _igen_dd_mm256_sub_pd(s2319, s2321);
  dd_I _t412 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t413 = _igen_dd_mm256_set1_pd(_t412);
  ddi_4 _t414 = _igen_dd_mm256_sub_pd(t1686, t1687);
  s2322 = _igen_dd_mm256_mul_pd(_t413, _t414);
  dd_I _t415 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t416 = _igen_dd_mm256_set1_pd(_t415);
  ddi_4 _t417 = _igen_dd_mm256_add_pd(t1686, t1687);
  s2323 = _igen_dd_mm256_mul_pd(_t416, _t417);
  dd_I _t418 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t419 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t420 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t421 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t422 = _igen_dd_mm256_set_pd(_t418, _t419, _t420, _t421);
  dd_I _t423 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t424 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t425 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t426 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t427 = _igen_dd_mm256_set_pd(_t423, _t424, _t425, _t426);
  ddi_4 _t428 = _igen_dd_mm256_mul_pd(_t422, s2004);
  ddi_4 _t429 = _igen_dd_mm256_mul_pd(_t427, s2008);
  s2324 = _igen_dd_mm256_sub_pd(_t428, _t429);
  dd_I _t430 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t431 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t432 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t433 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t434 = _igen_dd_mm256_set_pd(_t430, _t431, _t432, _t433);
  dd_I _t435 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t436 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t437 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t438 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t439 = _igen_dd_mm256_set_pd(_t435, _t436, _t437, _t438);
  ddi_4 _t440 = _igen_dd_mm256_mul_pd(_t434, s2004);
  ddi_4 _t441 = _igen_dd_mm256_mul_pd(_t439, s2008);
  s2325 = _igen_dd_mm256_add_pd(_t440, _t441);
  dd_I _t442 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t443 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t444 = _ia_neg_dd(_t442);
  dd_I _t445 = _ia_neg_dd(_t443);
  dd_I _t446 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t447 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t448 = _igen_dd_mm256_set_pd(_t444, _t445, _t446, _t447);
  dd_I _t449 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t450 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t451 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t452 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t453 = _igen_dd_mm256_set_pd(_t449, _t450, _t451, _t452);
  ddi_4 _t454 = _igen_dd_mm256_mul_pd(_t448, s2212);
  ddi_4 _t455 = _igen_dd_mm256_mul_pd(_t453, s2216);
  s2326 = _igen_dd_mm256_sub_pd(_t454, _t455);
  dd_I _t456 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t457 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t458 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t459 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t460 = _igen_dd_mm256_set_pd(_t456, _t457, _t458, _t459);
  dd_I _t461 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t462 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t463 = _ia_neg_dd(_t461);
  dd_I _t464 = _ia_neg_dd(_t462);
  dd_I _t465 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t466 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t467 = _igen_dd_mm256_set_pd(_t463, _t464, _t465, _t466);
  ddi_4 _t468 = _igen_dd_mm256_mul_pd(_t460, s2212);
  ddi_4 _t469 = _igen_dd_mm256_mul_pd(_t467, s2216);
  s2327 = _igen_dd_mm256_add_pd(_t468, _t469);
  t1688 = _igen_dd_mm256_add_pd(s2324, s2326);
  t1689 = _igen_dd_mm256_add_pd(s2325, s2327);
  t1690 = _igen_dd_mm256_sub_pd(s2324, s2326);
  t1691 = _igen_dd_mm256_sub_pd(s2325, s2327);
  dd_I _t470 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t471 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t472 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t473 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t474 = _igen_dd_mm256_set_pd(_t470, _t471, _t472, _t473);
  dd_I _t475 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t476 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t477 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t478 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t479 = _igen_dd_mm256_set_pd(_t475, _t476, _t477, _t478);
  ddi_4 _t480 = _igen_dd_mm256_mul_pd(_t474, s2005);
  ddi_4 _t481 = _igen_dd_mm256_mul_pd(_t479, s2009);
  s2328 = _igen_dd_mm256_sub_pd(_t480, _t481);
  dd_I _t482 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t483 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t484 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t485 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t486 = _igen_dd_mm256_set_pd(_t482, _t483, _t484, _t485);
  dd_I _t487 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t488 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t489 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t490 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t491 = _igen_dd_mm256_set_pd(_t487, _t488, _t489, _t490);
  ddi_4 _t492 = _igen_dd_mm256_mul_pd(_t486, s2005);
  ddi_4 _t493 = _igen_dd_mm256_mul_pd(_t491, s2009);
  s2329 = _igen_dd_mm256_add_pd(_t492, _t493);
  dd_I _t494 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t495 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t496 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t497 = _ia_neg_dd(_t494);
  dd_I _t498 = _ia_neg_dd(_t495);
  dd_I _t499 = _ia_neg_dd(_t496);
  dd_I _t500 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t501 = _igen_dd_mm256_set_pd(_t497, _t498, _t499, _t500);
  dd_I _t502 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t503 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t504 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t505 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t506 = _igen_dd_mm256_set_pd(_t502, _t503, _t504, _t505);
  ddi_4 _t507 = _igen_dd_mm256_mul_pd(_t501, s2213);
  ddi_4 _t508 = _igen_dd_mm256_mul_pd(_t506, s2217);
  s2330 = _igen_dd_mm256_sub_pd(_t507, _t508);
  dd_I _t509 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t510 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t511 = _ia_set_dd(-0.98917650996478101, 4.4389836750633553e-18,
                          0.98917650996478101, -4.4389836750633546e-18);
  dd_I _t512 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t513 = _igen_dd_mm256_set_pd(_t509, _t510, _t511, _t512);
  dd_I _t514 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t515 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t516 = _ia_set_dd(-0.14673047445536175, -2.06809701739985e-18,
                          0.14673047445536175, 2.0680970173998504e-18);
  dd_I _t517 = _ia_neg_dd(_t514);
  dd_I _t518 = _ia_neg_dd(_t515);
  dd_I _t519 = _ia_neg_dd(_t516);
  dd_I _t520 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t521 = _igen_dd_mm256_set_pd(_t517, _t518, _t519, _t520);
  ddi_4 _t522 = _igen_dd_mm256_mul_pd(_t513, s2213);
  ddi_4 _t523 = _igen_dd_mm256_mul_pd(_t521, s2217);
  s2331 = _igen_dd_mm256_add_pd(_t522, _t523);
  t1692 = _igen_dd_mm256_add_pd(s2328, s2330);
  t1693 = _igen_dd_mm256_add_pd(s2329, s2331);
  dd_I _t524 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t525 = _ia_neg_dd(_t524);
  ddi_4 _t526 = _igen_dd_mm256_set1_pd(_t525);
  ddi_4 _t527 = _igen_dd_mm256_sub_pd(s2328, s2330);
  a530 = _igen_dd_mm256_mul_pd(_t526, _t527);
  dd_I _t528 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t529 = _igen_dd_mm256_set1_pd(_t528);
  ddi_4 _t530 = _igen_dd_mm256_sub_pd(s2329, s2331);
  a531 = _igen_dd_mm256_mul_pd(_t529, _t530);
  s2332 = _igen_dd_mm256_sub_pd(a530, a531);
  s2333 = _igen_dd_mm256_add_pd(a530, a531);
  t1694 = _igen_dd_mm256_add_pd(t1680, t1688);
  t1695 = _igen_dd_mm256_add_pd(t1681, t1689);
  t1696 = _igen_dd_mm256_sub_pd(t1680, t1688);
  t1697 = _igen_dd_mm256_sub_pd(t1681, t1689);
  t1698 = _igen_dd_mm256_add_pd(t1684, t1692);
  t1699 = _igen_dd_mm256_add_pd(t1685, t1693);
  t1700 = _igen_dd_mm256_sub_pd(t1684, t1692);
  t1701 = _igen_dd_mm256_sub_pd(t1685, t1693);
  t1702 = _igen_dd_mm256_add_pd(t1694, t1698);
  t1703 = _igen_dd_mm256_add_pd(t1695, t1699);
  t1704 = _igen_dd_mm256_sub_pd(t1694, t1698);
  t1705 = _igen_dd_mm256_sub_pd(t1695, t1699);
  s2334 = _igen_dd_mm256_unpacklo_pd(t1702, t1703);
  s2335 = _igen_dd_mm256_unpackhi_pd(t1702, t1703);
  s2336 = _igen_dd_mm256_permute2f128_pd(s2334, s2335, (0) | ((2) << 4));
  *((a529 + 2)) = s2336;
  s2337 = _igen_dd_mm256_permute2f128_pd(s2334, s2335, (1) | ((3) << 4));
  *((a529 + 3)) = s2337;
  s2338 = _igen_dd_mm256_unpacklo_pd(t1704, t1705);
  s2339 = _igen_dd_mm256_unpackhi_pd(t1704, t1705);
  s2340 = _igen_dd_mm256_permute2f128_pd(s2338, s2339, (0) | ((2) << 4));
  *((a529 + 34)) = s2340;
  s2341 = _igen_dd_mm256_permute2f128_pd(s2338, s2339, (1) | ((3) << 4));
  *((a529 + 35)) = s2341;
  t1706 = _igen_dd_mm256_sub_pd(t1696, t1701);
  t1707 = _igen_dd_mm256_add_pd(t1697, t1700);
  t1708 = _igen_dd_mm256_add_pd(t1696, t1701);
  t1709 = _igen_dd_mm256_sub_pd(t1697, t1700);
  s2342 = _igen_dd_mm256_unpacklo_pd(t1706, t1707);
  s2343 = _igen_dd_mm256_unpackhi_pd(t1706, t1707);
  s2344 = _igen_dd_mm256_permute2f128_pd(s2342, s2343, (0) | ((2) << 4));
  *((a529 + 18)) = s2344;
  s2345 = _igen_dd_mm256_permute2f128_pd(s2342, s2343, (1) | ((3) << 4));
  *((a529 + 19)) = s2345;
  s2346 = _igen_dd_mm256_unpacklo_pd(t1708, t1709);
  s2347 = _igen_dd_mm256_unpackhi_pd(t1708, t1709);
  s2348 = _igen_dd_mm256_permute2f128_pd(s2346, s2347, (0) | ((2) << 4));
  *((a529 + 50)) = s2348;
  s2349 = _igen_dd_mm256_permute2f128_pd(s2346, s2347, (1) | ((3) << 4));
  *((a529 + 51)) = s2349;
  t1710 = _igen_dd_mm256_sub_pd(t1682, t1691);
  t1711 = _igen_dd_mm256_add_pd(t1683, t1690);
  t1712 = _igen_dd_mm256_add_pd(t1682, t1691);
  t1713 = _igen_dd_mm256_sub_pd(t1683, t1690);
  t1714 = _igen_dd_mm256_add_pd(s2322, s2332);
  t1715 = _igen_dd_mm256_sub_pd(s2323, s2333);
  t1716 = _igen_dd_mm256_sub_pd(s2322, s2332);
  t1717 = _igen_dd_mm256_add_pd(s2323, s2333);
  t1718 = _igen_dd_mm256_add_pd(t1710, t1714);
  t1719 = _igen_dd_mm256_add_pd(t1711, t1715);
  t1720 = _igen_dd_mm256_sub_pd(t1710, t1714);
  t1721 = _igen_dd_mm256_sub_pd(t1711, t1715);
  s2350 = _igen_dd_mm256_unpacklo_pd(t1718, t1719);
  s2351 = _igen_dd_mm256_unpackhi_pd(t1718, t1719);
  s2352 = _igen_dd_mm256_permute2f128_pd(s2350, s2351, (0) | ((2) << 4));
  *((a529 + 10)) = s2352;
  s2353 = _igen_dd_mm256_permute2f128_pd(s2350, s2351, (1) | ((3) << 4));
  *((a529 + 11)) = s2353;
  s2354 = _igen_dd_mm256_unpacklo_pd(t1720, t1721);
  s2355 = _igen_dd_mm256_unpackhi_pd(t1720, t1721);
  s2356 = _igen_dd_mm256_permute2f128_pd(s2354, s2355, (0) | ((2) << 4));
  *((a529 + 42)) = s2356;
  s2357 = _igen_dd_mm256_permute2f128_pd(s2354, s2355, (1) | ((3) << 4));
  *((a529 + 43)) = s2357;
  t1722 = _igen_dd_mm256_sub_pd(t1712, t1717);
  t1723 = _igen_dd_mm256_add_pd(t1713, t1716);
  t1724 = _igen_dd_mm256_add_pd(t1712, t1717);
  t1725 = _igen_dd_mm256_sub_pd(t1713, t1716);
  s2358 = _igen_dd_mm256_unpacklo_pd(t1722, t1723);
  s2359 = _igen_dd_mm256_unpackhi_pd(t1722, t1723);
  s2360 = _igen_dd_mm256_permute2f128_pd(s2358, s2359, (0) | ((2) << 4));
  *((a529 + 26)) = s2360;
  s2361 = _igen_dd_mm256_permute2f128_pd(s2358, s2359, (1) | ((3) << 4));
  *((a529 + 27)) = s2361;
  s2362 = _igen_dd_mm256_unpacklo_pd(t1724, t1725);
  s2363 = _igen_dd_mm256_unpackhi_pd(t1724, t1725);
  s2364 = _igen_dd_mm256_permute2f128_pd(s2362, s2363, (0) | ((2) << 4));
  *((a529 + 58)) = s2364;
  s2365 = _igen_dd_mm256_permute2f128_pd(s2362, s2363, (1) | ((3) << 4));
  *((a529 + 59)) = s2365;
  dd_I _t531 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t532 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t533 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t534 = _ia_neg_dd(_t531);
  dd_I _t535 = _ia_neg_dd(_t532);
  dd_I _t536 = _ia_neg_dd(_t533);
  dd_I _t537 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t538 = _igen_dd_mm256_set_pd(_t534, _t535, _t536, _t537);
  dd_I _t539 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t540 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t541 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t542 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t543 = _igen_dd_mm256_set_pd(_t539, _t540, _t541, _t542);
  ddi_4 _t544 = _igen_dd_mm256_mul_pd(_t538, s2234);
  ddi_4 _t545 = _igen_dd_mm256_mul_pd(_t543, s2238);
  s2366 = _igen_dd_mm256_sub_pd(_t544, _t545);
  dd_I _t546 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t547 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t548 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t549 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t550 = _igen_dd_mm256_set_pd(_t546, _t547, _t548, _t549);
  dd_I _t551 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t552 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t553 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t554 = _ia_neg_dd(_t551);
  dd_I _t555 = _ia_neg_dd(_t552);
  dd_I _t556 = _ia_neg_dd(_t553);
  dd_I _t557 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t558 = _igen_dd_mm256_set_pd(_t554, _t555, _t556, _t557);
  ddi_4 _t559 = _igen_dd_mm256_mul_pd(_t550, s2234);
  ddi_4 _t560 = _igen_dd_mm256_mul_pd(_t558, s2238);
  s2367 = _igen_dd_mm256_add_pd(_t559, _t560);
  t1726 = _igen_dd_mm256_add_pd(s2026, s2366);
  t1727 = _igen_dd_mm256_add_pd(s2030, s2367);
  t1728 = _igen_dd_mm256_sub_pd(s2026, s2366);
  t1729 = _igen_dd_mm256_sub_pd(s2030, s2367);
  dd_I _t561 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t562 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t563 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t564 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t565 = _igen_dd_mm256_set_pd(_t561, _t562, _t563, _t564);
  dd_I _t566 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t567 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t568 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t569 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t570 = _igen_dd_mm256_set_pd(_t566, _t567, _t568, _t569);
  ddi_4 _t571 = _igen_dd_mm256_mul_pd(_t565, s2027);
  ddi_4 _t572 = _igen_dd_mm256_mul_pd(_t570, s2031);
  s2368 = _igen_dd_mm256_sub_pd(_t571, _t572);
  dd_I _t573 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t574 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t575 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t576 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t577 = _igen_dd_mm256_set_pd(_t573, _t574, _t575, _t576);
  dd_I _t578 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t579 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t580 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t581 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t582 = _igen_dd_mm256_set_pd(_t578, _t579, _t580, _t581);
  ddi_4 _t583 = _igen_dd_mm256_mul_pd(_t577, s2027);
  ddi_4 _t584 = _igen_dd_mm256_mul_pd(_t582, s2031);
  s2369 = _igen_dd_mm256_add_pd(_t583, _t584);
  dd_I _t585 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t586 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t587 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t588 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t589 = _ia_neg_dd(_t585);
  dd_I _t590 = _ia_neg_dd(_t586);
  dd_I _t591 = _ia_neg_dd(_t587);
  dd_I _t592 = _ia_neg_dd(_t588);
  ddi_4 _t593 = _igen_dd_mm256_set_pd(_t589, _t590, _t591, _t592);
  dd_I _t594 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t595 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t596 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t597 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t598 = _igen_dd_mm256_set_pd(_t594, _t595, _t596, _t597);
  ddi_4 _t599 = _igen_dd_mm256_mul_pd(_t593, s2235);
  ddi_4 _t600 = _igen_dd_mm256_mul_pd(_t598, s2239);
  s2370 = _igen_dd_mm256_sub_pd(_t599, _t600);
  dd_I _t601 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t602 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t603 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t604 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t605 = _igen_dd_mm256_set_pd(_t601, _t602, _t603, _t604);
  dd_I _t606 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t607 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t608 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t609 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t610 = _ia_neg_dd(_t606);
  dd_I _t611 = _ia_neg_dd(_t607);
  dd_I _t612 = _ia_neg_dd(_t608);
  dd_I _t613 = _ia_neg_dd(_t609);
  ddi_4 _t614 = _igen_dd_mm256_set_pd(_t610, _t611, _t612, _t613);
  ddi_4 _t615 = _igen_dd_mm256_mul_pd(_t605, s2235);
  ddi_4 _t616 = _igen_dd_mm256_mul_pd(_t614, s2239);
  s2371 = _igen_dd_mm256_add_pd(_t615, _t616);
  t1730 = _igen_dd_mm256_add_pd(s2368, s2370);
  t1731 = _igen_dd_mm256_add_pd(s2369, s2371);
  t1732 = _igen_dd_mm256_sub_pd(s2368, s2370);
  t1733 = _igen_dd_mm256_sub_pd(s2369, s2371);
  dd_I _t617 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t618 = _igen_dd_mm256_set1_pd(_t617);
  ddi_4 _t619 = _igen_dd_mm256_sub_pd(t1732, t1733);
  s2372 = _igen_dd_mm256_mul_pd(_t618, _t619);
  dd_I _t620 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t621 = _igen_dd_mm256_set1_pd(_t620);
  ddi_4 _t622 = _igen_dd_mm256_add_pd(t1732, t1733);
  s2373 = _igen_dd_mm256_mul_pd(_t621, _t622);
  dd_I _t623 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t624 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t625 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t626 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t627 = _igen_dd_mm256_set_pd(_t623, _t624, _t625, _t626);
  dd_I _t628 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t629 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t630 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t631 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t632 = _igen_dd_mm256_set_pd(_t628, _t629, _t630, _t631);
  ddi_4 _t633 = _igen_dd_mm256_mul_pd(_t627, s2028);
  ddi_4 _t634 = _igen_dd_mm256_mul_pd(_t632, s2032);
  s2374 = _igen_dd_mm256_sub_pd(_t633, _t634);
  dd_I _t635 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t636 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t637 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t638 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t639 = _igen_dd_mm256_set_pd(_t635, _t636, _t637, _t638);
  dd_I _t640 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t641 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t642 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t643 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t644 = _igen_dd_mm256_set_pd(_t640, _t641, _t642, _t643);
  ddi_4 _t645 = _igen_dd_mm256_mul_pd(_t639, s2028);
  ddi_4 _t646 = _igen_dd_mm256_mul_pd(_t644, s2032);
  s2375 = _igen_dd_mm256_add_pd(_t645, _t646);
  dd_I _t647 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t648 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t649 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t650 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t651 = _ia_neg_dd(_t647);
  dd_I _t652 = _ia_neg_dd(_t648);
  dd_I _t653 = _ia_neg_dd(_t649);
  dd_I _t654 = _ia_neg_dd(_t650);
  ddi_4 _t655 = _igen_dd_mm256_set_pd(_t651, _t652, _t653, _t654);
  dd_I _t656 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t657 = _ia_neg_dd(_t656);
  dd_I _t658 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t659 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t660 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t661 = _igen_dd_mm256_set_pd(_t657, _t658, _t659, _t660);
  ddi_4 _t662 = _igen_dd_mm256_mul_pd(_t655, s2236);
  ddi_4 _t663 = _igen_dd_mm256_mul_pd(_t661, s2240);
  s2376 = _igen_dd_mm256_sub_pd(_t662, _t663);
  dd_I _t664 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t665 = _ia_neg_dd(_t664);
  dd_I _t666 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t667 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t668 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t669 = _igen_dd_mm256_set_pd(_t665, _t666, _t667, _t668);
  dd_I _t670 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t671 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t672 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t673 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t674 = _ia_neg_dd(_t670);
  dd_I _t675 = _ia_neg_dd(_t671);
  dd_I _t676 = _ia_neg_dd(_t672);
  dd_I _t677 = _ia_neg_dd(_t673);
  ddi_4 _t678 = _igen_dd_mm256_set_pd(_t674, _t675, _t676, _t677);
  ddi_4 _t679 = _igen_dd_mm256_mul_pd(_t669, s2236);
  ddi_4 _t680 = _igen_dd_mm256_mul_pd(_t678, s2240);
  s2377 = _igen_dd_mm256_add_pd(_t679, _t680);
  t1734 = _igen_dd_mm256_add_pd(s2374, s2376);
  t1735 = _igen_dd_mm256_add_pd(s2375, s2377);
  t1736 = _igen_dd_mm256_sub_pd(s2374, s2376);
  t1737 = _igen_dd_mm256_sub_pd(s2375, s2377);
  dd_I _t681 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t682 = _ia_neg_dd(_t681);
  dd_I _t683 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t684 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t685 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t686 = _igen_dd_mm256_set_pd(_t682, _t683, _t684, _t685);
  dd_I _t687 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t688 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t689 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t690 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t691 = _igen_dd_mm256_set_pd(_t687, _t688, _t689, _t690);
  ddi_4 _t692 = _igen_dd_mm256_mul_pd(_t686, s2029);
  ddi_4 _t693 = _igen_dd_mm256_mul_pd(_t691, s2033);
  s2378 = _igen_dd_mm256_sub_pd(_t692, _t693);
  dd_I _t694 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t695 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t696 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t697 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t698 = _igen_dd_mm256_set_pd(_t694, _t695, _t696, _t697);
  dd_I _t699 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t700 = _ia_neg_dd(_t699);
  dd_I _t701 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t702 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t703 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t704 = _igen_dd_mm256_set_pd(_t700, _t701, _t702, _t703);
  ddi_4 _t705 = _igen_dd_mm256_mul_pd(_t698, s2029);
  ddi_4 _t706 = _igen_dd_mm256_mul_pd(_t704, s2033);
  s2379 = _igen_dd_mm256_add_pd(_t705, _t706);
  dd_I _t707 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t708 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t709 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t710 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t711 = _ia_neg_dd(_t707);
  dd_I _t712 = _ia_neg_dd(_t708);
  dd_I _t713 = _ia_neg_dd(_t709);
  dd_I _t714 = _ia_neg_dd(_t710);
  ddi_4 _t715 = _igen_dd_mm256_set_pd(_t711, _t712, _t713, _t714);
  dd_I _t716 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t717 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t718 = _ia_neg_dd(_t716);
  dd_I _t719 = _ia_neg_dd(_t717);
  dd_I _t720 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t721 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t722 = _igen_dd_mm256_set_pd(_t718, _t719, _t720, _t721);
  ddi_4 _t723 = _igen_dd_mm256_mul_pd(_t715, s2237);
  ddi_4 _t724 = _igen_dd_mm256_mul_pd(_t722, s2241);
  s2380 = _igen_dd_mm256_sub_pd(_t723, _t724);
  dd_I _t725 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t726 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t727 = _ia_neg_dd(_t725);
  dd_I _t728 = _ia_neg_dd(_t726);
  dd_I _t729 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t730 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t731 = _igen_dd_mm256_set_pd(_t727, _t728, _t729, _t730);
  dd_I _t732 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t733 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t734 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t735 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t736 = _ia_neg_dd(_t732);
  dd_I _t737 = _ia_neg_dd(_t733);
  dd_I _t738 = _ia_neg_dd(_t734);
  dd_I _t739 = _ia_neg_dd(_t735);
  ddi_4 _t740 = _igen_dd_mm256_set_pd(_t736, _t737, _t738, _t739);
  ddi_4 _t741 = _igen_dd_mm256_mul_pd(_t731, s2237);
  ddi_4 _t742 = _igen_dd_mm256_mul_pd(_t740, s2241);
  s2381 = _igen_dd_mm256_add_pd(_t741, _t742);
  t1738 = _igen_dd_mm256_add_pd(s2378, s2380);
  t1739 = _igen_dd_mm256_add_pd(s2379, s2381);
  dd_I _t743 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t744 = _ia_neg_dd(_t743);
  ddi_4 _t745 = _igen_dd_mm256_set1_pd(_t744);
  ddi_4 _t746 = _igen_dd_mm256_sub_pd(s2378, s2380);
  a532 = _igen_dd_mm256_mul_pd(_t745, _t746);
  dd_I _t747 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t748 = _igen_dd_mm256_set1_pd(_t747);
  ddi_4 _t749 = _igen_dd_mm256_sub_pd(s2379, s2381);
  a533 = _igen_dd_mm256_mul_pd(_t748, _t749);
  s2382 = _igen_dd_mm256_sub_pd(a532, a533);
  s2383 = _igen_dd_mm256_add_pd(a532, a533);
  t1740 = _igen_dd_mm256_add_pd(t1726, t1734);
  t1741 = _igen_dd_mm256_add_pd(t1727, t1735);
  t1742 = _igen_dd_mm256_sub_pd(t1726, t1734);
  t1743 = _igen_dd_mm256_sub_pd(t1727, t1735);
  t1744 = _igen_dd_mm256_add_pd(t1730, t1738);
  t1745 = _igen_dd_mm256_add_pd(t1731, t1739);
  t1746 = _igen_dd_mm256_sub_pd(t1730, t1738);
  t1747 = _igen_dd_mm256_sub_pd(t1731, t1739);
  t1748 = _igen_dd_mm256_add_pd(t1740, t1744);
  t1749 = _igen_dd_mm256_add_pd(t1741, t1745);
  t1750 = _igen_dd_mm256_sub_pd(t1740, t1744);
  t1751 = _igen_dd_mm256_sub_pd(t1741, t1745);
  s2384 = _igen_dd_mm256_unpacklo_pd(t1748, t1749);
  s2385 = _igen_dd_mm256_unpackhi_pd(t1748, t1749);
  s2386 = _igen_dd_mm256_permute2f128_pd(s2384, s2385, (0) | ((2) << 4));
  *((a529 + 4)) = s2386;
  s2387 = _igen_dd_mm256_permute2f128_pd(s2384, s2385, (1) | ((3) << 4));
  *((a529 + 5)) = s2387;
  s2388 = _igen_dd_mm256_unpacklo_pd(t1750, t1751);
  s2389 = _igen_dd_mm256_unpackhi_pd(t1750, t1751);
  s2390 = _igen_dd_mm256_permute2f128_pd(s2388, s2389, (0) | ((2) << 4));
  *((a529 + 36)) = s2390;
  s2391 = _igen_dd_mm256_permute2f128_pd(s2388, s2389, (1) | ((3) << 4));
  *((a529 + 37)) = s2391;
  t1752 = _igen_dd_mm256_sub_pd(t1742, t1747);
  t1753 = _igen_dd_mm256_add_pd(t1743, t1746);
  t1754 = _igen_dd_mm256_add_pd(t1742, t1747);
  t1755 = _igen_dd_mm256_sub_pd(t1743, t1746);
  s2392 = _igen_dd_mm256_unpacklo_pd(t1752, t1753);
  s2393 = _igen_dd_mm256_unpackhi_pd(t1752, t1753);
  s2394 = _igen_dd_mm256_permute2f128_pd(s2392, s2393, (0) | ((2) << 4));
  *((a529 + 20)) = s2394;
  s2395 = _igen_dd_mm256_permute2f128_pd(s2392, s2393, (1) | ((3) << 4));
  *((a529 + 21)) = s2395;
  s2396 = _igen_dd_mm256_unpacklo_pd(t1754, t1755);
  s2397 = _igen_dd_mm256_unpackhi_pd(t1754, t1755);
  s2398 = _igen_dd_mm256_permute2f128_pd(s2396, s2397, (0) | ((2) << 4));
  *((a529 + 52)) = s2398;
  s2399 = _igen_dd_mm256_permute2f128_pd(s2396, s2397, (1) | ((3) << 4));
  *((a529 + 53)) = s2399;
  t1756 = _igen_dd_mm256_sub_pd(t1728, t1737);
  t1757 = _igen_dd_mm256_add_pd(t1729, t1736);
  t1758 = _igen_dd_mm256_add_pd(t1728, t1737);
  t1759 = _igen_dd_mm256_sub_pd(t1729, t1736);
  t1760 = _igen_dd_mm256_add_pd(s2372, s2382);
  t1761 = _igen_dd_mm256_sub_pd(s2373, s2383);
  t1762 = _igen_dd_mm256_sub_pd(s2372, s2382);
  t1763 = _igen_dd_mm256_add_pd(s2373, s2383);
  t1764 = _igen_dd_mm256_add_pd(t1756, t1760);
  t1765 = _igen_dd_mm256_add_pd(t1757, t1761);
  t1766 = _igen_dd_mm256_sub_pd(t1756, t1760);
  t1767 = _igen_dd_mm256_sub_pd(t1757, t1761);
  s2400 = _igen_dd_mm256_unpacklo_pd(t1764, t1765);
  s2401 = _igen_dd_mm256_unpackhi_pd(t1764, t1765);
  s2402 = _igen_dd_mm256_permute2f128_pd(s2400, s2401, (0) | ((2) << 4));
  *((a529 + 12)) = s2402;
  s2403 = _igen_dd_mm256_permute2f128_pd(s2400, s2401, (1) | ((3) << 4));
  *((a529 + 13)) = s2403;
  s2404 = _igen_dd_mm256_unpacklo_pd(t1766, t1767);
  s2405 = _igen_dd_mm256_unpackhi_pd(t1766, t1767);
  s2406 = _igen_dd_mm256_permute2f128_pd(s2404, s2405, (0) | ((2) << 4));
  *((a529 + 44)) = s2406;
  s2407 = _igen_dd_mm256_permute2f128_pd(s2404, s2405, (1) | ((3) << 4));
  *((a529 + 45)) = s2407;
  t1768 = _igen_dd_mm256_sub_pd(t1758, t1763);
  t1769 = _igen_dd_mm256_add_pd(t1759, t1762);
  t1770 = _igen_dd_mm256_add_pd(t1758, t1763);
  t1771 = _igen_dd_mm256_sub_pd(t1759, t1762);
  s2408 = _igen_dd_mm256_unpacklo_pd(t1768, t1769);
  s2409 = _igen_dd_mm256_unpackhi_pd(t1768, t1769);
  s2410 = _igen_dd_mm256_permute2f128_pd(s2408, s2409, (0) | ((2) << 4));
  *((a529 + 28)) = s2410;
  s2411 = _igen_dd_mm256_permute2f128_pd(s2408, s2409, (1) | ((3) << 4));
  *((a529 + 29)) = s2411;
  s2412 = _igen_dd_mm256_unpacklo_pd(t1770, t1771);
  s2413 = _igen_dd_mm256_unpackhi_pd(t1770, t1771);
  s2414 = _igen_dd_mm256_permute2f128_pd(s2412, s2413, (0) | ((2) << 4));
  *((a529 + 60)) = s2414;
  s2415 = _igen_dd_mm256_permute2f128_pd(s2412, s2413, (1) | ((3) << 4));
  *((a529 + 61)) = s2415;
  dd_I _t750 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t751 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t752 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t753 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t754 = _ia_neg_dd(_t750);
  dd_I _t755 = _ia_neg_dd(_t751);
  dd_I _t756 = _ia_neg_dd(_t752);
  dd_I _t757 = _ia_neg_dd(_t753);
  ddi_4 _t758 = _igen_dd_mm256_set_pd(_t754, _t755, _t756, _t757);
  dd_I _t759 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t760 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t761 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t762 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t763 = _igen_dd_mm256_set_pd(_t759, _t760, _t761, _t762);
  ddi_4 _t764 = _igen_dd_mm256_mul_pd(_t758, s2258);
  ddi_4 _t765 = _igen_dd_mm256_mul_pd(_t763, s2262);
  s2416 = _igen_dd_mm256_sub_pd(_t764, _t765);
  dd_I _t766 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t767 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t768 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t769 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t770 = _igen_dd_mm256_set_pd(_t766, _t767, _t768, _t769);
  dd_I _t771 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t772 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t773 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t774 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t775 = _ia_neg_dd(_t771);
  dd_I _t776 = _ia_neg_dd(_t772);
  dd_I _t777 = _ia_neg_dd(_t773);
  dd_I _t778 = _ia_neg_dd(_t774);
  ddi_4 _t779 = _igen_dd_mm256_set_pd(_t775, _t776, _t777, _t778);
  ddi_4 _t780 = _igen_dd_mm256_mul_pd(_t770, s2258);
  ddi_4 _t781 = _igen_dd_mm256_mul_pd(_t779, s2262);
  s2417 = _igen_dd_mm256_add_pd(_t780, _t781);
  t1772 = _igen_dd_mm256_add_pd(s2050, s2416);
  t1773 = _igen_dd_mm256_add_pd(s2054, s2417);
  t1774 = _igen_dd_mm256_sub_pd(s2050, s2416);
  t1775 = _igen_dd_mm256_sub_pd(s2054, s2417);
  dd_I _t782 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t783 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t784 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t785 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t786 = _igen_dd_mm256_set_pd(_t782, _t783, _t784, _t785);
  dd_I _t787 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t788 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t789 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t790 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t791 = _igen_dd_mm256_set_pd(_t787, _t788, _t789, _t790);
  ddi_4 _t792 = _igen_dd_mm256_mul_pd(_t786, s2051);
  ddi_4 _t793 = _igen_dd_mm256_mul_pd(_t791, s2055);
  s2418 = _igen_dd_mm256_sub_pd(_t792, _t793);
  dd_I _t794 = _ia_set_dd(-0.67155895484701844, 1.1144145997241141e-18,
                          0.67155895484701844, -1.1144145997241139e-18);
  dd_I _t795 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t796 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t797 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  ddi_4 _t798 = _igen_dd_mm256_set_pd(_t794, _t795, _t796, _t797);
  dd_I _t799 = _ia_set_dd(-0.74095112535495911, -4.1157661502074916e-18,
                          0.74095112535495911, 4.1157661502074923e-18);
  dd_I _t800 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t801 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t802 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  ddi_4 _t803 = _igen_dd_mm256_set_pd(_t799, _t800, _t801, _t802);
  ddi_4 _t804 = _igen_dd_mm256_mul_pd(_t798, s2051);
  ddi_4 _t805 = _igen_dd_mm256_mul_pd(_t803, s2055);
  s2419 = _igen_dd_mm256_add_pd(_t804, _t805);
  dd_I _t806 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t807 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t808 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t809 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t810 = _ia_neg_dd(_t806);
  dd_I _t811 = _ia_neg_dd(_t807);
  dd_I _t812 = _ia_neg_dd(_t808);
  dd_I _t813 = _ia_neg_dd(_t809);
  ddi_4 _t814 = _igen_dd_mm256_set_pd(_t810, _t811, _t812, _t813);
  dd_I _t815 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t816 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t817 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t818 = _ia_neg_dd(_t815);
  dd_I _t819 = _ia_neg_dd(_t816);
  dd_I _t820 = _ia_neg_dd(_t817);
  dd_I _t821 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t822 = _igen_dd_mm256_set_pd(_t818, _t819, _t820, _t821);
  ddi_4 _t823 = _igen_dd_mm256_mul_pd(_t814, s2259);
  ddi_4 _t824 = _igen_dd_mm256_mul_pd(_t822, s2263);
  s2420 = _igen_dd_mm256_sub_pd(_t823, _t824);
  dd_I _t825 = _ia_set_dd(-0.51410274419322177, 2.3064013625844385e-18,
                          0.51410274419322177, -2.3064013625844381e-18);
  dd_I _t826 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t827 = _ia_set_dd(-0.049067674327418015, -6.5434651005489285e-20,
                          0.049067674327418015, 6.5434651005489297e-20);
  dd_I _t828 = _ia_neg_dd(_t825);
  dd_I _t829 = _ia_neg_dd(_t826);
  dd_I _t830 = _ia_neg_dd(_t827);
  dd_I _t831 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  ddi_4 _t832 = _igen_dd_mm256_set_pd(_t828, _t829, _t830, _t831);
  dd_I _t833 = _ia_set_dd(-0.85772861000027201, -2.9365845418942623e-18,
                          0.85772861000027201, 2.9365845418942627e-18);
  dd_I _t834 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t835 = _ia_set_dd(-0.99879545620517241, -4.9935350581654342e-18,
                          0.99879545620517241, 4.993535058165435e-18);
  dd_I _t836 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t837 = _ia_neg_dd(_t833);
  dd_I _t838 = _ia_neg_dd(_t834);
  dd_I _t839 = _ia_neg_dd(_t835);
  dd_I _t840 = _ia_neg_dd(_t836);
  ddi_4 _t841 = _igen_dd_mm256_set_pd(_t837, _t838, _t839, _t840);
  ddi_4 _t842 = _igen_dd_mm256_mul_pd(_t832, s2259);
  ddi_4 _t843 = _igen_dd_mm256_mul_pd(_t841, s2263);
  s2421 = _igen_dd_mm256_add_pd(_t842, _t843);
  t1776 = _igen_dd_mm256_add_pd(s2418, s2420);
  t1777 = _igen_dd_mm256_add_pd(s2419, s2421);
  t1778 = _igen_dd_mm256_sub_pd(s2418, s2420);
  t1779 = _igen_dd_mm256_sub_pd(s2419, s2421);
  dd_I _t844 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t845 = _igen_dd_mm256_set1_pd(_t844);
  ddi_4 _t846 = _igen_dd_mm256_sub_pd(t1778, t1779);
  s2422 = _igen_dd_mm256_mul_pd(_t845, _t846);
  dd_I _t847 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t848 = _igen_dd_mm256_set1_pd(_t847);
  ddi_4 _t849 = _igen_dd_mm256_add_pd(t1778, t1779);
  s2423 = _igen_dd_mm256_mul_pd(_t848, _t849);
  dd_I _t850 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t851 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t852 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t853 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t854 = _igen_dd_mm256_set_pd(_t850, _t851, _t852, _t853);
  dd_I _t855 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t856 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t857 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t858 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t859 = _igen_dd_mm256_set_pd(_t855, _t856, _t857, _t858);
  ddi_4 _t860 = _igen_dd_mm256_mul_pd(_t854, s2052);
  ddi_4 _t861 = _igen_dd_mm256_mul_pd(_t859, s2056);
  s2424 = _igen_dd_mm256_sub_pd(_t860, _t861);
  dd_I _t862 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t863 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  dd_I _t864 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t865 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  ddi_4 _t866 = _igen_dd_mm256_set_pd(_t862, _t863, _t864, _t865);
  dd_I _t867 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t868 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t869 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t870 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  ddi_4 _t871 = _igen_dd_mm256_set_pd(_t867, _t868, _t869, _t870);
  ddi_4 _t872 = _igen_dd_mm256_mul_pd(_t866, s2052);
  ddi_4 _t873 = _igen_dd_mm256_mul_pd(_t871, s2056);
  s2425 = _igen_dd_mm256_add_pd(_t872, _t873);
  dd_I _t874 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t875 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t876 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t877 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t878 = _ia_neg_dd(_t874);
  dd_I _t879 = _ia_neg_dd(_t875);
  dd_I _t880 = _ia_neg_dd(_t876);
  dd_I _t881 = _ia_neg_dd(_t877);
  ddi_4 _t882 = _igen_dd_mm256_set_pd(_t878, _t879, _t880, _t881);
  dd_I _t883 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t884 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t885 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t886 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t887 = _ia_neg_dd(_t883);
  dd_I _t888 = _ia_neg_dd(_t884);
  dd_I _t889 = _ia_neg_dd(_t885);
  dd_I _t890 = _ia_neg_dd(_t886);
  ddi_4 _t891 = _igen_dd_mm256_set_pd(_t887, _t888, _t889, _t890);
  ddi_4 _t892 = _igen_dd_mm256_mul_pd(_t882, s2260);
  ddi_4 _t893 = _igen_dd_mm256_mul_pd(_t891, s2264);
  s2426 = _igen_dd_mm256_sub_pd(_t892, _t893);
  dd_I _t894 = _ia_set_dd(-0.95694033573220882, 4.3819280251045715e-18,
                          0.95694033573220882, -4.3819280251045707e-18);
  dd_I _t895 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t896 = _ia_set_dd(-0.63439328416364549, -2.2057303160545414e-18,
                          0.63439328416364549, 2.2057303160545418e-18);
  dd_I _t897 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                          0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t898 = _ia_neg_dd(_t894);
  dd_I _t899 = _ia_neg_dd(_t895);
  dd_I _t900 = _ia_neg_dd(_t896);
  dd_I _t901 = _ia_neg_dd(_t897);
  ddi_4 _t902 = _igen_dd_mm256_set_pd(_t898, _t899, _t900, _t901);
  dd_I _t903 = _ia_set_dd(-0.29028467725446233, 1.0530198523338187e-18,
                          0.29028467725446233, -1.0530198523338185e-18);
  dd_I _t904 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t905 = _ia_set_dd(-0.77301045336273699, 3.3768136434082411e-18,
                          0.77301045336273699, -3.3768136434082407e-18);
  dd_I _t906 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                          0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t907 = _ia_neg_dd(_t903);
  dd_I _t908 = _ia_neg_dd(_t904);
  dd_I _t909 = _ia_neg_dd(_t905);
  dd_I _t910 = _ia_neg_dd(_t906);
  ddi_4 _t911 = _igen_dd_mm256_set_pd(_t907, _t908, _t909, _t910);
  ddi_4 _t912 = _igen_dd_mm256_mul_pd(_t902, s2260);
  ddi_4 _t913 = _igen_dd_mm256_mul_pd(_t911, s2264);
  s2427 = _igen_dd_mm256_add_pd(_t912, _t913);
  t1780 = _igen_dd_mm256_add_pd(s2424, s2426);
  t1781 = _igen_dd_mm256_add_pd(s2425, s2427);
  t1782 = _igen_dd_mm256_sub_pd(s2424, s2426);
  t1783 = _igen_dd_mm256_sub_pd(s2425, s2427);
  dd_I _t914 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t915 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t916 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t917 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t918 = _ia_neg_dd(_t914);
  dd_I _t919 = _ia_neg_dd(_t915);
  dd_I _t920 = _ia_neg_dd(_t916);
  dd_I _t921 = _ia_neg_dd(_t917);
  ddi_4 _t922 = _igen_dd_mm256_set_pd(_t918, _t919, _t920, _t921);
  dd_I _t923 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t924 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t925 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t926 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t927 = _igen_dd_mm256_set_pd(_t923, _t924, _t925, _t926);
  ddi_4 _t928 = _igen_dd_mm256_mul_pd(_t922, s2053);
  ddi_4 _t929 = _igen_dd_mm256_mul_pd(_t927, s2057);
  s2428 = _igen_dd_mm256_sub_pd(_t928, _t929);
  dd_I _t930 = _ia_set_dd(-0.80320753148064494, 2.867286317778053e-18,
                          0.80320753148064494, -2.8672863177780526e-18);
  dd_I _t931 = _ia_set_dd(-0.88192126434835505, -4.4399473044904877e-19,
                          0.88192126434835505, 4.4399473044904887e-19);
  dd_I _t932 = _ia_set_dd(-0.94154406518302081, -3.6911110497021578e-18,
                          0.94154406518302081, 3.6911110497021586e-18);
  dd_I _t933 = _ia_set_dd(-0.98078528040323043, 5.7924223830923445e-19,
                          0.98078528040323043, -5.7924223830923435e-19);
  ddi_4 _t934 = _igen_dd_mm256_set_pd(_t930, _t931, _t932, _t933);
  dd_I _t935 = _ia_set_dd(-0.59569930449243336, -3.0943215345905628e-18,
                          0.59569930449243336, 3.0943215345905631e-18);
  dd_I _t936 = _ia_set_dd(-0.47139673682599764, 2.0397094898362414e-18,
                          0.47139673682599764, -2.039709489836241e-18);
  dd_I _t937 = _ia_set_dd(-0.33688985339222005, 1.1092626129538986e-18,
                          0.33688985339222005, -1.1092626129538984e-18);
  dd_I _t938 = _ia_set_dd(-0.19509032201612825, -1.9162116786901603e-18,
                          0.19509032201612825, 1.9162116786901607e-18);
  dd_I _t939 = _ia_neg_dd(_t935);
  dd_I _t940 = _ia_neg_dd(_t936);
  dd_I _t941 = _ia_neg_dd(_t937);
  dd_I _t942 = _ia_neg_dd(_t938);
  ddi_4 _t943 = _igen_dd_mm256_set_pd(_t939, _t940, _t941, _t942);
  ddi_4 _t944 = _igen_dd_mm256_mul_pd(_t934, s2053);
  ddi_4 _t945 = _igen_dd_mm256_mul_pd(_t943, s2057);
  s2429 = _igen_dd_mm256_add_pd(_t944, _t945);
  dd_I _t946 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t947 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t948 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t949 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t950 = _ia_neg_dd(_t946);
  dd_I _t951 = _ia_neg_dd(_t947);
  ddi_4 _t952 = _igen_dd_mm256_set_pd(_t948, _t949, _t950, _t951);
  dd_I _t953 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t954 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t955 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t956 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t957 = _ia_neg_dd(_t953);
  dd_I _t958 = _ia_neg_dd(_t954);
  dd_I _t959 = _ia_neg_dd(_t955);
  dd_I _t960 = _ia_neg_dd(_t956);
  ddi_4 _t961 = _igen_dd_mm256_set_pd(_t957, _t958, _t959, _t960);
  ddi_4 _t962 = _igen_dd_mm256_mul_pd(_t952, s2261);
  ddi_4 _t963 = _igen_dd_mm256_mul_pd(_t961, s2265);
  s2430 = _igen_dd_mm256_sub_pd(_t962, _t963);
  dd_I _t964 = _ia_set_dd(-0.90398929312344334, -1.8040452340210319e-18,
                          0.90398929312344334, 1.8040452340210323e-18);
  dd_I _t965 = _ia_set_dd(-0.99518472667219693, -1.2682493685861118e-18,
                          0.99518472667219693, 1.268249368586112e-18);
  dd_I _t966 = _ia_set_dd(-0.97003125319454397, 4.2386838588572577e-18,
                          0.97003125319454397, -4.238683858857257e-18);
  dd_I _t967 = _ia_set_dd(-0.83146961230254524, -4.328597320854896e-18,
                          0.83146961230254524, 4.3285973208548968e-18);
  dd_I _t968 = _ia_neg_dd(_t964);
  dd_I _t969 = _ia_neg_dd(_t965);
  dd_I _t970 = _ia_neg_dd(_t966);
  dd_I _t971 = _ia_neg_dd(_t967);
  ddi_4 _t972 = _igen_dd_mm256_set_pd(_t968, _t969, _t970, _t971);
  dd_I _t973 = _ia_set_dd(-0.24298017990326387, 9.441300761682215e-19,
                          0.24298017990326387, -9.441300761682213e-19);
  dd_I _t974 = _ia_set_dd(-0.55557023301960218, -2.351278591668233e-18,
                          0.55557023301960218, 2.3512785916682334e-18);
  dd_I _t975 = _ia_set_dd(-0.42755509343028208, 4.9097770405933265e-18,
                          0.42755509343028208, -4.9097770405933257e-18);
  dd_I _t976 = _ia_set_dd(-0.098017140329560604, -3.7122207386710211e-19,
                          0.098017140329560604, 3.7122207386710215e-19);
  dd_I _t977 = _ia_neg_dd(_t973);
  dd_I _t978 = _ia_neg_dd(_t974);
  ddi_4 _t979 = _igen_dd_mm256_set_pd(_t975, _t976, _t977, _t978);
  ddi_4 _t980 = _igen_dd_mm256_mul_pd(_t972, s2261);
  ddi_4 _t981 = _igen_dd_mm256_mul_pd(_t979, s2265);
  s2431 = _igen_dd_mm256_add_pd(_t980, _t981);
  t1784 = _igen_dd_mm256_add_pd(s2428, s2430);
  t1785 = _igen_dd_mm256_add_pd(s2429, s2431);
  dd_I _t982 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  dd_I _t983 = _ia_neg_dd(_t982);
  ddi_4 _t984 = _igen_dd_mm256_set1_pd(_t983);
  ddi_4 _t985 = _igen_dd_mm256_sub_pd(s2428, s2430);
  a534 = _igen_dd_mm256_mul_pd(_t984, _t985);
  dd_I _t986 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                          0.70710678118654757, -2.737310929369414e-18);
  ddi_4 _t987 = _igen_dd_mm256_set1_pd(_t986);
  ddi_4 _t988 = _igen_dd_mm256_sub_pd(s2429, s2431);
  a535 = _igen_dd_mm256_mul_pd(_t987, _t988);
  s2432 = _igen_dd_mm256_sub_pd(a534, a535);
  s2433 = _igen_dd_mm256_add_pd(a534, a535);
  t1786 = _igen_dd_mm256_add_pd(t1772, t1780);
  t1787 = _igen_dd_mm256_add_pd(t1773, t1781);
  t1788 = _igen_dd_mm256_sub_pd(t1772, t1780);
  t1789 = _igen_dd_mm256_sub_pd(t1773, t1781);
  t1790 = _igen_dd_mm256_add_pd(t1776, t1784);
  t1791 = _igen_dd_mm256_add_pd(t1777, t1785);
  t1792 = _igen_dd_mm256_sub_pd(t1776, t1784);
  t1793 = _igen_dd_mm256_sub_pd(t1777, t1785);
  t1794 = _igen_dd_mm256_add_pd(t1786, t1790);
  t1795 = _igen_dd_mm256_add_pd(t1787, t1791);
  t1796 = _igen_dd_mm256_sub_pd(t1786, t1790);
  t1797 = _igen_dd_mm256_sub_pd(t1787, t1791);
  s2434 = _igen_dd_mm256_unpacklo_pd(t1794, t1795);
  s2435 = _igen_dd_mm256_unpackhi_pd(t1794, t1795);
  s2436 = _igen_dd_mm256_permute2f128_pd(s2434, s2435, (0) | ((2) << 4));
  *((a529 + 6)) = s2436;
  s2437 = _igen_dd_mm256_permute2f128_pd(s2434, s2435, (1) | ((3) << 4));
  *((a529 + 7)) = s2437;
  s2438 = _igen_dd_mm256_unpacklo_pd(t1796, t1797);
  s2439 = _igen_dd_mm256_unpackhi_pd(t1796, t1797);
  s2440 = _igen_dd_mm256_permute2f128_pd(s2438, s2439, (0) | ((2) << 4));
  *((a529 + 38)) = s2440;
  s2441 = _igen_dd_mm256_permute2f128_pd(s2438, s2439, (1) | ((3) << 4));
  *((a529 + 39)) = s2441;
  t1798 = _igen_dd_mm256_sub_pd(t1788, t1793);
  t1799 = _igen_dd_mm256_add_pd(t1789, t1792);
  t1800 = _igen_dd_mm256_add_pd(t1788, t1793);
  t1801 = _igen_dd_mm256_sub_pd(t1789, t1792);
  s2442 = _igen_dd_mm256_unpacklo_pd(t1798, t1799);
  s2443 = _igen_dd_mm256_unpackhi_pd(t1798, t1799);
  s2444 = _igen_dd_mm256_permute2f128_pd(s2442, s2443, (0) | ((2) << 4));
  *((a529 + 22)) = s2444;
  s2445 = _igen_dd_mm256_permute2f128_pd(s2442, s2443, (1) | ((3) << 4));
  *((a529 + 23)) = s2445;
  s2446 = _igen_dd_mm256_unpacklo_pd(t1800, t1801);
  s2447 = _igen_dd_mm256_unpackhi_pd(t1800, t1801);
  s2448 = _igen_dd_mm256_permute2f128_pd(s2446, s2447, (0) | ((2) << 4));
  *((a529 + 54)) = s2448;
  s2449 = _igen_dd_mm256_permute2f128_pd(s2446, s2447, (1) | ((3) << 4));
  *((a529 + 55)) = s2449;
  t1802 = _igen_dd_mm256_sub_pd(t1774, t1783);
  t1803 = _igen_dd_mm256_add_pd(t1775, t1782);
  t1804 = _igen_dd_mm256_add_pd(t1774, t1783);
  t1805 = _igen_dd_mm256_sub_pd(t1775, t1782);
  t1806 = _igen_dd_mm256_add_pd(s2422, s2432);
  t1807 = _igen_dd_mm256_sub_pd(s2423, s2433);
  t1808 = _igen_dd_mm256_sub_pd(s2422, s2432);
  t1809 = _igen_dd_mm256_add_pd(s2423, s2433);
  t1810 = _igen_dd_mm256_add_pd(t1802, t1806);
  t1811 = _igen_dd_mm256_add_pd(t1803, t1807);
  t1812 = _igen_dd_mm256_sub_pd(t1802, t1806);
  t1813 = _igen_dd_mm256_sub_pd(t1803, t1807);
  s2450 = _igen_dd_mm256_unpacklo_pd(t1810, t1811);
  s2451 = _igen_dd_mm256_unpackhi_pd(t1810, t1811);
  s2452 = _igen_dd_mm256_permute2f128_pd(s2450, s2451, (0) | ((2) << 4));
  *((a529 + 14)) = s2452;
  s2453 = _igen_dd_mm256_permute2f128_pd(s2450, s2451, (1) | ((3) << 4));
  *((a529 + 15)) = s2453;
  s2454 = _igen_dd_mm256_unpacklo_pd(t1812, t1813);
  s2455 = _igen_dd_mm256_unpackhi_pd(t1812, t1813);
  s2456 = _igen_dd_mm256_permute2f128_pd(s2454, s2455, (0) | ((2) << 4));
  *((a529 + 46)) = s2456;
  s2457 = _igen_dd_mm256_permute2f128_pd(s2454, s2455, (1) | ((3) << 4));
  *((a529 + 47)) = s2457;
  t1814 = _igen_dd_mm256_sub_pd(t1804, t1809);
  t1815 = _igen_dd_mm256_add_pd(t1805, t1808);
  t1816 = _igen_dd_mm256_add_pd(t1804, t1809);
  t1817 = _igen_dd_mm256_sub_pd(t1805, t1808);
  s2458 = _igen_dd_mm256_unpacklo_pd(t1814, t1815);
  s2459 = _igen_dd_mm256_unpackhi_pd(t1814, t1815);
  s2460 = _igen_dd_mm256_permute2f128_pd(s2458, s2459, (0) | ((2) << 4));
  *((a529 + 30)) = s2460;
  s2461 = _igen_dd_mm256_permute2f128_pd(s2458, s2459, (1) | ((3) << 4));
  *((a529 + 31)) = s2461;
  s2462 = _igen_dd_mm256_unpacklo_pd(t1816, t1817);
  s2463 = _igen_dd_mm256_unpackhi_pd(t1816, t1817);
  s2464 = _igen_dd_mm256_permute2f128_pd(s2462, s2463, (0) | ((2) << 4));
  *((a529 + 62)) = s2464;
  s2465 = _igen_dd_mm256_permute2f128_pd(s2462, s2463, (1) | ((3) << 4));
  *((a529 + 63)) = s2465;
}
