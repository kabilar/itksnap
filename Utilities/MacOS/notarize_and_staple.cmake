cmake_minimum_required(VERSION 3.16)

MESSAGE(STATUS "Executing notarytool on ${CPACK_TEMPORARY_PACKAGE_FILE_NAME}")
IF(KEYCHAIN)
  SET(KEYCHAIN_OPTION "--keychain ${KEYCHAIN}")
ENDIF()
EXECUTE_PROCESS(COMMAND xcrun notarytool submit ${CPACK_TEMPORARY_PACKAGE_FILE_NAME} --keychain-profile "@SNAP_MACOS_NOTARYTOOL_PROFILE@" ${KEYCHAIN_OPTION} --wait RESULT_VARIABLE RC_N COMMAND_ECHO STDOUT)
MESSAGE(STATUS "notarytool return code: ${RC_N}")

MESSAGE(STATUS "Executing staple on ${CPACK_TEMPORARY_PACKAGE_FILE_NAME}")
EXECUTE_PROCESS(COMMAND xcrun stapler staple ${CPACK_TEMPORARY_PACKAGE_FILE_NAME} RESULT_VARIABLE RC_S COMMAND_ECHO STDOUT)
MESSAGE(STATUS "staple return code: ${RC_S}")
