cmake_minimum_required(VERSION 3.10)

project(ces41lex VERSION 0.1 LANGUAGES C)

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_VERSION)

# https://cmake.org/cmake/help/latest/module/FindFLEX.html
find_package(BISON)
find_package(FLEX)

SET(CES41_SRC "src" CACHE FILEPATH "Directory with student sources")

include_directories( ${CES41_SRC} include lib )

FILE(GLOB labSrc ${CES41_SRC}/*.c  )

file(GLOB_RECURSE C_FILES ${CES41_SRC}/*.c)
#set_source_files_properties(${C_FILES} {CMAKE_CURRENT_BINARY_DIR}/lexer.c )

FLEX_TARGET(scanner ${CES41_SRC}/cminus.l  ${CMAKE_CURRENT_BINARY_DIR}/lexer.c )

message("   * FOUT = ${FLEX_scanner_OUTPUTS}")
message("   * SRC FILES = ${labSrc}")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
 add_executable(mylex
    ${labSrc}
    ${FLEX_scanner_OUTPUTS}
 )
 target_link_libraries(mylex ${FLEX_LIBRARIES})
 

add_custom_target(runmylex ALL
  COMMENT "running mylex"
  COMMAND ../scripts/runlex
  DEPENDS mylex
  VERBATIM
  USES_TERMINAL
)

add_custom_target(rundiff ALL
  COMMENT "running diff"
  COMMAND ../scripts/rundiff
  DEPENDS runmylex
  VERBATIM
  USES_TERMINAL
)


# works, but file is hardcoded
# add_custom_target(mdcout ALL
#   COMMAND mylex ../example/mdc.cm > mdc.out
#   COMMENT "running diff for mdc.cm"
#   COMMAND diff -ZbB ../output/mdc.out  mdc.out
#   DEPENDS mylex
# )


# explaning about diff options
# diff -Z (trail space) -b (change space) -B (blank lines)

# problem: does not run when lex is up to date
#add_custom_command( TARGET lex POST_BUILD
#  COMMAND lex ../example/mdc.cm > mdc.out
#  COMMENT "running diff for mdc.cm"
#  COMMAND diff -ZbB ../output/mdc.out  mdc.out
#  MAIN_DEPENDENCY lex
#)



