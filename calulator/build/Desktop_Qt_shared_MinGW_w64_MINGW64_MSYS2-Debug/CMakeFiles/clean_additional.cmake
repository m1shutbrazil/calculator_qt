# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\calulator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\calulator_autogen.dir\\ParseCache.txt"
  "calulator_autogen"
  )
endif()
