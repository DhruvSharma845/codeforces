cmake_minimum_required(VERSION 3.15)
project(codeforces)

set(CMAKE_CXX_STANDAmainRD 17)

set(SOURCE_FILES
        equality_1038_A.cpp
        birthday_cake_629_A.cpp
        pallindromic_supersequence_932_A.cpp
        anton_and_polyhedrons_785_A.cpp
        burgers_1207_A.cpp
        even_odd_game_959_A.cpp
        hit_the_lottery_996_A.cpp
        love_A_1146_A.cpp
        love_triangle_939_A.cpp
        new_year_and_hurry_750_A.cpp
        qaq_894_A.cpp
        kefa_and_first_steps_580_A.cpp
        hotelier_1200_A.cpp
        oath_of_night_watch_786_A.cpp
        king_escape_1033_A.cpp
        single_push_1253_A.cpp
        bad_prices_1213_B.cpp
        transformation_727_A.cpp
        kuriyama_stones_433_B.cpp
        social_network_1234_B2.cpp)
add_executable(cpp ${SOURCE_FILES})