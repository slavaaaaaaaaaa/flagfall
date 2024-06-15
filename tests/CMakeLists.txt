################################################################################
## Test Build Options (Turn ON or OFF as needed)
option(BUILD_TEST_KINGTESTS "Option to build kingtest.cpp"      ON)
option(BUILD_TEST_PAWNTESTS "Option to build pawntests.cpp"     ON)
option(BUILD_TEST_QUEENTESTS "Option to build queentests.cpp"   ON) 
################################################################################

################################################################################
# test_patterns
if(BUILD_TEST_KINGTESTS)
    
    add_executable(kingtests ${CMAKE_CURRENT_SOURCE_DIR}/kingtests.cpp)
    target_compile_features(kingtests PUBLIC cxx_std_17)

    target_link_libraries(
        kingtests 
            PUBLIC 
                slavalib::flagfall
    ) 

endif(BUILD_TEST_KINGTESTS)
################################################################################

################################################################################
# test_patterns
if(BUILD_TEST_PAWNTESTS)
    
    add_executable(pawntests ${CMAKE_CURRENT_SOURCE_DIR}/pawntests.cpp)
    target_compile_features(pawntests PUBLIC cxx_std_17)

    target_link_libraries(
        pawntests 
            PUBLIC 
                slavalib::flagfall
    ) 

endif(BUILD_TEST_PAWNTESTS)
################################################################################

################################################################################
# test_patterns
if(BUILD_TEST_QUEENTESTS)
    
    add_executable(queentests ${CMAKE_CURRENT_SOURCE_DIR}/queentests.cpp)
    target_compile_features(queentests PUBLIC cxx_std_17)

    target_link_libraries(
        queentests 
            PUBLIC 
                slavalib::flagfall
    ) 

endif(BUILD_TEST_QUEENTESTS)
################################################################################

