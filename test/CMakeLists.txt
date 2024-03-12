include( FetchContent )

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ${PROJECT_NAME}.test
  tests.cpp
)

target_link_libraries(
    ${PROJECT_NAME}.test
    ${PROJECT_NAME}
    GTest::gtest_main
    pthread
)

target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test") # TODO: Ask if this is necessary

include(GoogleTest)
gtest_discover_tests(
    ${PROJECT_NAME}.test
    EXTRA_ARGS --gtest_output=xml:${CMAKE_BINARY_DIR}/testingReport/
)