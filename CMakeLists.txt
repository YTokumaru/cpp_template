cmake_minimum_required(VERSION 3.14.0)
project(template_project VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

# ---- Options ----
option(ENABLE_CODE_ANALYSIS "Enable static code analysis" ON)
option(ENABLE_STRICT_COMPILE_WARNINGS "Enable strict compile warnings" ON)
option(ENABLE_TESTING "Enable testing" ON)

message(STATUS "ENABLE_CODE_ANALYSIS:           ${ENABLE_CODE_ANALYSIS}")
message(STATUS "ENABLE_STRICT_COMPILE_WARNINGS: ${ENABLE_STRICT_COMPILE_WARNINGS}")
message(STATUS "ENABLE_TESTING:                 ${ENABLE_TESTING}")

# ---- CppCheck ----
if(ENABLE_CODE_ANALYSIS)
    find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
    if (CMAKE_CXX_CPPCHECK)
        # Notes:
        # - unmatchedSuppression needed since not all source files are
        #   analyzed simultaneously
        # - unusedFunction needed since not all source files are
        #   analyzed simultaneously
        # - template needed to force "warning" into output string, and
        #   to make the 'id' available for suppression
        list(
            APPEND CMAKE_CXX_CPPCHECK 
            "--enable=warning"
            "--enable=all"
            "--inconclusive"
            "--inline-suppr"
            "--quiet"
            "--suppress=unmatchedSuppression"
            "--suppress=unusedFunction"
            "--template='{file}:{line}: warning: {id} ({severity}): {message}'"
            "--suppress=missingIncludeSystem")
    endif(CMAKE_CXX_CPPCHECK)
endif(ENABLE_CODE_ANALYSIS)

# ---- Strict Compile Warnings ----
if(ENABLE_STRICT_COMPILE_WARNINGS)
    if (MSVC)
        # Warning level 4 and all warnings as errors
        add_compile_options(/W4 /WX)
    else(MSVC)
        # Warning for gcc and clang
        add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wshadow)
    endif(MSVC)
endif(ENABLE_STRICT_COMPILE_WARNINGS)

# ---- GoogleTest ----
if(ENABLE_TESTING)
include(FetchContent)
FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    
    FetchContent_MakeAvailable(googletest)
    enable_testing()
endif(ENABLE_TESTING)

add_subdirectory(src)
add_subdirectory(test)