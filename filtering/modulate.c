/**
 * Modulate audio file
 */

/*==================================
 * Includes
 *==================================*/

#include "modulate.h"

 /*==================================
 * Constants
 *==================================*/

const static double filterCoef[MODULATE_FLT_LEN] = {1, 0.998026728428272, 0.992114701314478,
  0.982287250728689, 0.968583161128631, 0.951056516295154, 0.929776485888252,
  0.904827052466020, 0.876306680043864, 0.844327925502015, 0.809016994374948,
  0.770513242775789, 0.728968627421412, 0.684547105928689, 0.637423989748690,
  0.587785252292473, 0.535826794978997, 0.481753674101715, 0.425779291565073,
  0.368124552684678, 0.309016994374947, 0.248689887164855, 0.187381314585725,
  0.125333233564304, 0.0627905195293135, 6.12323399573677e-17,
  -0.0627905195293134, -0.125333233564304, -0.187381314585725,
  -0.248689887164855, -0.309016994374947, -0.368124552684678,
  -0.425779291565073, -0.481753674101715, -0.535826794978997,
  -0.587785252292473, -0.637423989748690, -0.684547105928689,
  -0.728968627421411, -0.770513242775789, -0.809016994374947,
  -0.844327925502015, -0.876306680043864, -0.904827052466019,
  -0.929776485888251, -0.951056516295154, -0.968583161128631,
  -0.982287250728689, -0.992114701314478, -0.998026728428272, -1,
  -0.998026728428272, -0.992114701314478, -0.982287250728689,
  -0.968583161128631, -0.951056516295154, -0.929776485888252,
  -0.904827052466020, -0.876306680043864, -0.844327925502015,
  -0.809016994374948, -0.770513242775789, -0.728968627421412,
  -0.684547105928689, -0.637423989748690, -0.587785252292473,
  -0.535826794978996, -0.481753674101715, -0.425779291565072,
  -0.368124552684678, -0.309016994374948, -0.248689887164854,
  -0.187381314585725, -0.125333233564305, -0.0627905195293132,
  -1.83697019872103e-16, 0.0627905195293128, 0.125333233564304,
  0.187381314585724, 0.248689887164855, 0.309016994374947, 0.368124552684677,
  0.425779291565072, 0.481753674101716, 0.535826794978997, 0.587785252292473,
  0.637423989748689, 0.684547105928688, 0.728968627421411, 0.770513242775789,
  0.809016994374947, 0.844327925502015, 0.876306680043863, 0.904827052466019,
  0.929776485888252, 0.951056516295154, 0.968583161128631, 0.982287250728689,
  0.992114701314478, 0.998026728428272};

/*==================================
 * Public
 *==================================*/

void modulate(double data[], uint32_t dataLen) {
	
  // Iterate through all terms
  uint32_t i, fltIndx;
  for (i = 0; i < dataLen; i++) {

    // Get scaling coef from filter
    fltIndx = ((i * MODULATE_FLT_LEN) / MODULATE_FREQ_MOD) % MODULATE_FLT_LEN;

    // Update data
    data[i] = filterCoef[fltIndx] * data[i];
  }
}
