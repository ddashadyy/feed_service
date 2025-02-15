cmake_minimum_required(VERSION 3.20)
project(feed_service)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

 
find_package(userver COMPONENTS postgresql REQUIRED)

add_executable(feed_service src/main.cpp src/feed_service.cpp) 
target_link_libraries(${PROJECT_NAME} userver::postgresql)

userver_add_sql_library(
    ${PROJECT_NAME}_sql
    NAMESPACE feed_service
    OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}
    SQL_FILES *.sql
)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_sql)

file(GLOB CONFIGS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.yaml ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.json)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT ${PROJECT_NAME})
install(FILES ${CONFIGS_FILES} DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/${PROJECT_NAME} COMPONENT ${PROJECT_NAME})