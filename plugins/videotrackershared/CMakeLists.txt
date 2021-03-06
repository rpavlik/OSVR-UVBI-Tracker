
if(WIN32)
    add_subdirectory(DirectShowCameraLib)
endif()

# ls *.cpp *.h | sort | sed  -e 's/^/"${CMAKE_CURRENT_SOURCE_DIR}\//' -e 's/$/"/'
set(OSVR_VIDEOTRACKERSHARED_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}"
    CACHE INTERNAL "" FORCE)

set(OSVR_VIDEOTRACKERSHARED_SOURCES_CORE
    "${CMAKE_CURRENT_SOURCE_DIR}/BasicTypes.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/BlobParams.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/BlobExtractor.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/BlobExtractor.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/CameraDistortionModel.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/CameraParameters.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/cvToEigen.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/cvUtils.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/EdgeHoleBasedLedExtractor.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EdgeHoleBasedLedExtractor.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/EdgeHoleBlobExtractor.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EdgeHoleBlobExtractor.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/GenericBlobExtractor.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GenericBlobExtractor.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/IdentifierHelpers.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/LedMeasurement.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/ProjectPoint.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/RealtimeLaplacian.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/SBDBlobExtractor.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SBDBlobExtractor.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/UndistortMeasurements.h"
    CACHE INTERNAL "" FORCE)

set(OSVR_VIDEOTRACKERSHARED_SOURCES_IO
    "${CMAKE_CURRENT_SOURCE_DIR}/OptionalStream.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/GetOptionalParameter.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/ParseBlobParams.h"
    CACHE INTERNAL "" FORCE)

set(OSVR_VIDEOTRACKERSHARED_SOURCES_HDKDATA
    "${CMAKE_CURRENT_SOURCE_DIR}/HDKData.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/HDKData.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/LoadCalibration.h"
    CACHE INTERNAL "" FORCE)

if(BUILD_ADVANCED_DEV_TOOLS)
    add_executable(blob_extraction_demo
        BlobExtractionDemo.cpp
        ${OSVR_VIDEOTRACKERSHARED_SOURCES_CORE}
        ${OSVR_VIDEOTRACKERSHARED_SOURCES_IO})
    target_include_directories(blob_extraction_demo
        PRIVATE
        ${OSVR_VIDEOTRACKERSHARED_INCLUDE_DIR}
        ${OpenCV_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS})
    target_compile_features(blob_extraction_demo PUBLIC cxx_std_11)
    target_link_libraries(blob_extraction_demo
        PUBLIC
        ${VIDEOTRACKER_EXTRA_LIBS}
        opencv_core
        opencv_imgproc
        opencv_image2d
        osvrUtil
        JsonCpp::JsonCpp)
    target_compile_definitions(blob_extraction_demo
        PRIVATE
        OSVR_USING_EDGE_HOLE_EXTRACTOR)
    set_target_properties(blob_extraction_demo PROPERTIES
        FOLDER "OSVR Plugins")
endif()
