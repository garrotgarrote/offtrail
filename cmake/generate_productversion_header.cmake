
include(${BINARY_DIR}/version_variables.cmake)
#message(STATUS "[generate_productversion_header.cmake] BINARY_DIR in generate_productversion_header.cmake: ${BINARY_DIR}/version_variables.cmake")
message(STATUS "[generate_productversion_header.cmake] Running ${CMAKE_SOURCE_DIR}/cmake/generate_productversion_header.cmake")

function(generate_productversion_header)
#	message(STATUS "[generate_productversion_header.cmake] generate_productversion_header() in generate_productversion_header.cmake")
	set(PRODUCT_VERSION_H_PATH ${BINARY_DIR}/src/lib_gui/productVersion.h)
	configure_file(
		${CMAKE_SOURCE_DIR}/cmake/productVersion.h.in
		${PRODUCT_VERSION_H_PATH}
	)
endfunction(generate_productversion_header)

if (NOT EXISTS ${BINARY_DIR}/version_variables.cmake)
	message(WARNING "[generate_productversion_header.cmake] ${BINARY_DIR}/version_variables.cmake does NOT EXIST")
endif ()

generate_productversion_header()
