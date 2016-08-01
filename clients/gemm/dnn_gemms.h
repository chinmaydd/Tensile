
const unsigned int num_gemm_params = 2;

unsigned int gemm_params[][11] = {
/*{     M,     N,     K,    tA,    tB,   lda,   ldb,   ldc, alpha,  beta, cnt },  network   */
  {  1024,    32,     1,     0,     0,  2304,   169,   169,      1,    0,   1 },
  {  1024,    32,     1,     0,     0,  2304,   169,   169,      1,    1,   1 }
};


#if 0
/*{     M,     N,     K,    tA,    tB,   lda,   ldb,   ldc, alpha,  beta, cnt },  network   */
  {  3456,   256,   169,     1,     0,   169,   169,  3456,     1,     1, 128 }, /* Alexnet */
  {  3025,    64,   363,     0,     0,  3025,   363,  3025,     1,     1, 128 }, /* Alexnet */
  {  3025,    64,     1,     1,     0,     1,     1,  3025,     1,     0, 128 }, /* Alexnet */
  {  2304,   256,   169,     1,     0,   169,   169,  2304,     1,     1, 128 }, /* Alexnet */
  {  1728,   384,   169,     1,     0,   169,   169,  1728,     1,     1, 128 }, /* Alexnet */
  {  1600,   192,   729,     1,     0,   729,   729,  1600,     1,     1, 128 }, /* Alexnet */
  {   729,  1600,   192,     0,     1,   729,  1600,   729,     1,     0, 128 }, /* Alexnet */
  {   729,   192,  1600,     0,     0,   729,  1600,   729,     1,     1, 128 }, /* Alexnet */
  {   729,   192,     1,     1,     0,     1,     1,   729,     1,     0, 128 }, /* Alexnet */
  {   363,    64,  3025,     1,     0,  3025,  3025,   363,     1,     1, 128 }, /* Alexnet */
  {   169,  3456,   256,     0,     1,   169,  3456,   169,     1,     0, 128 }, /* Alexnet */
  {   169,  2304,   256,     0,     1,   169,  2304,   169,     1,     0, 128 }, /* Alexnet */
  {   169,  1728,   384,     0,     1,   169,  1728,   169,     1,     0, 128 }, /* Alexnet */
  {   169,   384,  1728,     0,     0,   169,  1728,   169,     1,     1, 128 }, /* Alexnet */
  {   169,   384,     1,     1,     0,     1,     1,   169,     1,     0, 128 }, /* Alexnet */
  {   169,   256,  3456,     0,     0,   169,  3456,   169,     1,     1, 128 }, /* Alexnet */
  {   169,   256,  2304,     0,     0,   169,  2304,   169,     1,     1, 128 }, /* Alexnet */
  {   169,   256,     1,     1,     0,     1,     1,   169,     1,     0, 128 }, /* Alexnet */
  { 11881,    64,   147,     0,     0, 11881,   147, 11881,     1,     1, 126 }, /* Google */
  { 11881,    64,     1,     1,     0,     1,     1, 11881,     1,     0, 126 }, /* Google */
  {  2916,    64,    64,     0,     0,  2916,    64,  2916,     1,     1, 127 }, /* Google */
  {  2916,    64,     1,     1,     0,     1,     1,  2916,     1,     0, 126 }, /* Google */
  {  2704,   192,   576,     0,     0,  2704,   576,  2704,     1,     1, 126 }, /* Google */
  {  2704,   192,     1,     1,     0,     1,     1,  2704,     1,     0, 126 }, /* Google */
  {   625,   128,   256,     0,     0,   625,   256,   625,     1,     1, 128 }, /* Google */
  {   625,   128,     1,     1,     0,     1,     1,   625,     1,     0, 128 }, /* Google */
  {   625,    96,   192,     0,     0,   625,   192,   625,     1,     1, 126 }, /* Google */
  {   625,    96,     1,     1,     0,     1,     1,   625,     1,     0, 126 }, /* Google */
  {   625,    64,   192,     0,     0,   625,   192,   625,     1,     1, 127 }, /* Google */
  {   625,    64,     1,     1,     0,     1,     1,   625,     1,     0, 126 }, /* Google */
  {   625,    32,   256,     0,     0,   625,   256,   625,     1,     1, 126 }, /* Google */
  {   625,    32,     1,     1,     0,     1,     1,   625,     1,     0, 127 }, /* Google */
  {   625,    16,   192,     0,     0,   625,   192,   625,     1,     1, 126 }, /* Google */
  {   625,    16,     1,     1,     0,     1,     1,   625,     1,     0, 127 }, /* Google */
  {   529,   192,  1152,     0,     0,   529,  1152,   529,     1,     1, 126 }, /* Google */
  {   529,   192,     1,     1,     0,     1,     1,   529,     1,     0, 126 }, /* Google */
  {   529,   128,   864,     0,     0,   529,   864,   529,     1,     1, 126 }, /* Google */
  {   529,   128,     1,     1,     0,     1,     1,   529,     1,     0, 127 }, /* Google */
  {   529,    64,   256,     0,     0,   529,   256,   529,     1,     1, 126 }, /* Google */
  {   529,    64,     1,     1,     0,     1,     1,   529,     1,     0, 127 }, /* Google */
  {   529,    32,   192,     0,     0,   529,   192,   529,     1,     1, 126 }, /* Google */
  {   529,    32,     1,     1,     0,     1,     1,   529,     1,     0, 127 }, /* Google */
  {   441,    96,   800,     0,     0,   441,   800,   441,     1,     1, 126 }, /* Google */
  {   441,    96,     1,     1,     0,     1,     1,   441,     1,     0, 127 }, /* Google */
  {   441,    32,   400,     0,     0,   441,   400,   441,     1,     1, 126 }, /* Google */
  {   441,    32,     1,     1,     0,     1,     1,   441,     1,     0, 126 }, /* Google */
  {   144,   256,   528,     0,     0,   144,   528,   144,     1,     1, 126 }, /* Google */
  {   144,   256,     1,     1,     0,     1,     1,   144,     1,     0, 127 }, /* Google */
  {   144,   192,   480,     0,     0,   144,   480,   144,     1,     1, 126 }, /* Google */
  {   144,   192,     1,     1,     0,     1,     1,   144,     1,     0, 126 }, /* Google */
  {   144,   160,   528,     0,     0,   144,   528,   144,     1,     1, 126 }, /* Google */
  {   144,   160,   512,     0,     0,   144,   512,   144,     1,     1, 127 }, /* Google */
  {   144,   160,     1,     1,     0,     1,     1,   144,     1,     0, 128 }, /* Google */
  {   144,   144,   512,     0,     0,   144,   512,   144,     1,     1, 126 }, /* Google */
  {   144,   144,     1,     1,     0,     1,     1,   144,     1,     0, 127 }, /* Google */
  {   144,   128,   512,     0,     0,   144,   512,   144,     1,     1, 128 }, /* Google */
  {   144,   128,     1,     1,     0,     1,     1,   144,     1,     0, 128 }, /* Google */
  {   144,   112,   512,     0,     0,   144,   512,   144,     1,     1, 128 }, /* Google */
  {   144,   112,     1,     1,     0,     1,     1,   144,     1,     0, 128 }, /* Google */
  {   144,    96,   480,     0,     0,   144,   480,   144,     1,     1, 127 }, /* Google */
  {   144,    96,     1,     1,     0,     1,     1,   144,     1,     0, 126 }, /* Google */
  {   144,    32,   528,     0,     0,   144,   528,   144,     1,     1, 126 }, /* Google */
  {   144,    32,   512,     0,     0,   144,   512,   144,     1,     1, 127 }, /* Google */
  {   144,    32,     1,     1,     0,     1,     1,   144,     1,     0, 128 }, /* Google */
  {   144,    24,   512,     0,     0,   144,   512,   144,     1,     1, 128 }, /* Google */
  {   144,    24,     1,     1,     0,     1,     1,   144,     1,     0, 128 }, /* Google */
  {   144,    16,   480,     0,     0,   144,   480,   144,     1,     1, 126 }, /* Google */
  {   144,    16,     1,     1,     0,     1,     1,   144,     1,     0, 127 }, /* Google */
  {   100,   320,  1440,     0,     0,   100,  1440,   100,     1,     1, 126 }, /* Google */
  {   100,   320,     1,     1,     0,     1,     1,   100,     1,     0, 127 }, /* Google */
  {   100,   288,  1296,     0,     0,   100,  1296,   100,     1,     1, 126 }, /* Google */
  {   100,   288,     1,     1,     0,     1,     1,   100,     1,     0, 126 }, /* Google */
  {   100,   256,  1152,     0,     0,   100,  1152,   100,     1,     1, 127 }, /* Google */
  {   100,   256,     1,     1,     0,     1,     1,   100,     1,     0, 126 }, /* Google */
  {   100,   224,  1008,     0,     0,   100,  1008,   100,     1,     1, 126 }, /* Google */
  {   100,   224,     1,     1,     0,     1,     1,   100,     1,     0, 127 }, /* Google */
  {   100,   208,   864,     0,     0,   100,   864,   100,     1,     1, 126 }, /* Google */
  {   100,   208,     1,     1,     0,     1,     1,   100,     1,     0, 126 }, /* Google */
  {   100,   128,   528,     0,     0,   100,   528,   100,     1,     1, 127 }, /* Google */
  {   100,   128,     1,     1,     0,     1,     1,   100,     1,     0, 126 }, /* Google */
  {   100,    64,   512,     0,     0,   100,   512,   100,     1,     1, 128 }, /* Google */
  {   100,    64,   480,     0,     0,   100,   480,   100,     1,     1, 127 }, /* Google */
  {   100,    64,     1,     1,     0,     1,     1,   100,     1,     0, 128 }, /* Google */
  {    64,   128,   800,     0,     0,    64,   800,    64,     1,     1, 126 }, /* Google */
  {    64,   128,     1,     1,     0,     1,     1,    64,     1,     0, 127 }, /* Google */
  {    64,    64,   800,     0,     0,    64,   800,    64,     1,     1, 127 }, /* Google */
  {    64,    64,   600,     0,     0,    64,   600,    64,     1,     1, 128 }, /* Google */
  {    64,    64,     1,     1,     0,     1,     1,    64,     1,     0, 128 }, /* Google */
  {    64,    48,   400,     0,     0,    64,   400,    64,     1,     1, 126 }, /* Google */
  {    64,    48,     1,     1,     0,     1,     1,    64,     1,     0, 127 }, /* Google */
  {    25,   832,   384,     0,     1,    25,   832,    25,     1,     0, 126 }, /* Google */
  {    25,   832,   256,     0,     1,    25,   832,    25,     1,     0, 126 }, /* Google */
  {    25,   832,   192,     0,     1,    25,   832,    25,     1,     0, 127 }, /* Google */
  {    25,   832,    48,     0,     1,    25,   832,    25,     1,     0, 127 }, /* Google */
  {    25,   384,   832,     0,     0,    25,   832,    25,     1,     1, 126 }, /* Google */
  {    25,   384,     1,     1,     0,     1,     1,    25,     1,     0, 127 }, /* Google */
  {    25,   256,   832,     0,     0,    25,   832,    25,     1,     1, 126 }, /* Google */
  {    25,   256,     1,     1,     0,     1,     1,    25,     1,     0, 127 }, /* Google */
  {    25,   192,   832,     0,     0,    25,   832,    25,     1,     1, 126 }, /* Google */
  {    25,   192,     1,     1,     0,     1,     1,    25,     1,     0, 126 }, /* Google */
  {    25,   160,   832,     0,     0,    25,   832,    25,     1,     1, 127 }, /* Google */
  {    25,   160,     1,     1,     0,     1,     1,    25,     1,     0, 126 }, /* Google */
  {    25,    48,   832,     0,     0,    25,   832,    25,     1,     1, 126 }, /* Google */
  {    25,    48,     1,     1,     0,     1,     1,    25,     1,     0, 127 }, /* Google */
  {    25,    32,   832,     0,     0,    25,   832,    25,     1,     1, 126 }, /* Google */
  {    25,    32,     1,     1,     0,     1,     1,    25,     1,     0, 127 }, /* Google */
  {     9,  1728,   384,     0,     1,     9,  1728,     9,     1,     0, 126 }, /* Google */
  {     9,   832,   128,     0,     1,     9,   832,     9,     1,     0, 127 }, /* Google */
  {     9,   384,  1728,     0,     0,     9,  1728,     9,     1,     1, 126 }, /* Google */
  {     9,   384,     1,     1,     0,     1,     1,     9,     1,     0, 127 }, /* Google */
  {     9,   320,  1440,     0,     0,     9,  1440,     9,     1,     1, 126 }, /* Google */
  {     9,   320,     1,     1,     0,     1,     1,     9,     1,     0, 127 }, /* Google */
  {     9,   128,   832,     0,     0,     9,   832,     9,     1,     1, 128 }, /* Google */
  {     9,   128,     1,     1,     0,     1,     1,     9,     1,     0, 128 }, /* Google */
#if INCLUDE_GEMV
  {     1,  1200,   128,     0,     1,     1,  1200,     1,     1,     0, 126 }, /* Google */
  {     1,   128,  1200,     0,     0,     1,  1200,     1,     1,     1, 126 }, /* Google */
  {     1,   128,   800,     0,     0,     1,   800,     1,     1,     1, 127 }, /* Google */
  {     1,   128,     1,     1,     0,     1,     1,     1,     1,     0, 128 }, /* Google */
#endif
  {  9216,  1024,   144,     1,     0,   144,   144,  9216,     1,     1, 128 }, /* Overfeat */
  {  4608,  1024,   144,     1,     0,   144,   144,  4608,     1,     1, 128 }, /* Overfeat */
  {  3136,    96,   363,     0,     0,  3136,   363,  3136,     1,     1, 128 }, /* Overfeat */
  {  3136,    96,     1,     1,     0,     1,     1,  3136,     1,     0, 128 }, /* Overfeat */
  {  2400,   256,   576,     1,     0,   576,   576,  2400,     1,     1, 128 }, /* Overfeat */
  {  2304,   512,   144,     1,     0,   144,   144,  2304,     1,     1, 128 }, /* Overfeat */
  {   576,  2400,   256,     0,     1,   576,  2400,   576,     1,     0, 128 }, /* Overfeat */
  {   576,   256,  2400,     0,     0,   576,  2400,   576,     1,     1, 128 }, /* Overfeat */
  {   576,   256,     1,     1,     0,     1,     1,   576,     1,     0, 128 }, /* Overfeat */
  {   363,    96,  3136,     1,     0,  3136,  3136,   363,     1,     1, 128 }, /* Overfeat */
  {   144,  9216,  1024,     0,     1,   144,  9216,   144,     1,     0, 128 }, /* Overfeat */
  {   144,  4608,  1024,     0,     1,   144,  4608,   144,     1,     0, 128 }, /* Overfeat */
  {   144,  2304,   512,     0,     1,   144,  2304,   144,     1,     0, 128 }, /* Overfeat */
  {   144,  1024,  9216,     0,     0,   144,  9216,   144,     1,     1, 128 }, /* Overfeat */
  {   144,  1024,  4608,     0,     0,   144,  4608,   144,     1,     1, 128 }, /* Overfeat */
  {   144,  1024,     1,     1,     0,     1,     1,   144,     1,     0, 128 }, /* Overfeat */
  {   144,   512,  2304,     0,     0,   144,  2304,   144,     1,     1, 128 }, /* Overfeat */
  {   144,   512,     1,     1,     0,     1,     1,   144,     1,     0, 128 }, /* Overfeat */
  { 50176,    64,    27,     0,     0, 50176,    27, 50176,     1,     1,  64 }, /* Oxford */
  { 50176,    64,     1,     1,     0,     1,     1, 50176,     1,     0,  63 }};/* Oxford */

#endif