#!/bin/bash

usage() {
    echo "Usage: "
    echo "$0 [-h] [part]"
    echo
    echo "where:"
    echo "    -h prints this usage message"
    echo "    part optionally specifies tests of the following parts:"
    echo "          init_protocol"
    echo "          init_segment"
    echo "          read_data"
    echo "          send_data"
    echo "          send_file_normal"
    echo "          send_file_with_timeout"
    echo "          send_metadata"
    echo "          set_socket_timeout"
    echo "          set_udp_socket"
    echo "    If part is ommitted, tests for all parts run."
    exit
}

print_dot_sep() {
    echo "........................................................................"
}

print_dash_sep() {
    echo "------------------------------------------------------------------------"
}

makeproj() {
    print_dash_sep
    echo "Compiling project ..."
    echo

    export SILENCE_LOGGING=$1
    make
}

endproj() {
    print_dash_sep
    exit
}    

runtest() {
    print_dot_sep
    echo "Running test of $1 ..."
    ./test_rftcu_$1
}

runtests() {
    makeproj $1
    for part in init_protocol init_segment set_udp_socket set_socket_timeout \
                read_data send_metadata send_data send_file_normal \
                send_file_with_timeout
    do  
        runtest $part
    done 
    endproj
}

part=""
slog=1  # logging silenced by default

if [ $# -lt 1 ]; then
    runtests 1
elif [ $# -eq 1 ]; then
    if [ $1 == "-h" ]; then
        usage
    else 
        part=$1
    fi
elif [ $# -eq 2 ]; then 
    if [ $1 == "-h" ]; then
        usage
    else 
        usage
    fi
else
    usage
fi

case $part in
        init_segment|read_data|send_data|send_file_with_timeout|send_metadata\
        |send_file_normal|set_udp_socket|set_socket_timeout|init_protocol) \
            makeproj $slog; runtest $part; endproj ;;
        *) echo "$part is an invalid part"; usage ;;
    esac
fi
