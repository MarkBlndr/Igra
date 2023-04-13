add_executable(Igra main.cpp) #[[Make exe from the following files]]

include_directories(../Blndr/include)

target_link_libraries(Igra Blndr)