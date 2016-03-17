/*
Project: Ocean
Author:  DEISS Olivier
License: This software is offered under the GPL license. See COPYING for more information.
*/

/*
This class treats the command line arguments and sets their default value.
*/

#ifndef Arguments_hpp
#define Arguments_hpp

#include <iostream>
#include <set>
#include <vector>

class Arguments {

    public:
    
        double      lx;               /* width of the scene */
        double      ly;               /* height of the scene */
        int         fps;              /* target FPS of the simulation */
        int         nx;               /* waves detail level */
        int         ny;               /* waves detail level */
        double      wind_speed;       /* wind speed */
        int         wind_alignment;   /* to specify how the waves should align to the wind */
        double      min_wave_size;    /* minimum wave size, to smooth the simulation */
        double      A;                /* amplification factor */
        double      motion_factor;    /* motion factor to slow down or speed up the simulation */
        std::string keyboard;         /* keyboard mode: azerty or qwerty */
    
        Arguments(int, char**);
        ~Arguments() {}

        bool is_set(std::string arg) { return arg_set.count(arg); }
        void print_help();
        int  parse_arguments();

    private:

        bool parse_string_arg(std::string, int*, std::string*, std::string);
        bool check_long_args(std::string);
    
        std::set<std::string> arg_set;   /* if an argument is correct and specified it is added to this set */
        int                   argc;      /* number of arguments */
        char**                argv;      /* value of arguments */

};

#endif