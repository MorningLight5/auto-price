add_executable (auto-price "evalfis.cpp" "evalfis.h" "FuzzyPrice.cpp" "FuzzyPrice.h"  "FuzzyPrice_data.h" "FuzzyPrice_types.h" "main.cpp" "main.h" "rtwtypes.h" "trimf.cpp" "trimf.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET auto-price PROPERTY CXX_STANDARD 20)
endif()
