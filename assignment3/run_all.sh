#!/bin/bash

TRACE_DIR=$PWD/tracer/traces
TRACE0=matmul_basic-720M.champsim.xz
TRACE1=matmul_opt1-720M.champsim.xz
TRACE2=matmul_opt2-720M.champsim.xz


if [ -z $TRACE_DIR ] || [ ! -d "$TRACE_DIR" ] ; then
    echo "[ERROR] Cannot find a trace directory: $TRACE_DIR"
    exit 1
fi

if [ ! -f "bin/champsim" ] ; then
    echo "[ERROR] Cannot find a ChampSim binary: bin/champsim"
    exit 1
fi

if [ ! -f "$TRACE_DIR/$TRACE0" ] ; then
    echo "[ERROR] Cannot find a trace for matmul_basic: $TRACE_DIR/$TRACE0"
    exit 1
fi

if [ ! -f "$TRACE_DIR/$TRACE1" ] ; then
    echo "[ERROR] Cannot find a trace for matmul_opt1: $TRACE_DIR/$TRACE1"
    exit 1
fi

if [ ! -f "$TRACE_DIR/$TRACE2" ] ; then
    echo "[ERROR] Cannot find a trace for matmul_opt2: $TRACE_DIR/$TRACE2"
    exit 1
fi

bin/champsim --simulation_instructions 10000000 ${TRACE_DIR}/${TRACE0} > results/matmul_basic.result
bin/champsim --simulation_instructions 10000000 ${TRACE_DIR}/${TRACE1} > results/matmul_opt1.result
bin/champsim --simulation_instructions 10000000 ${TRACE_DIR}/${TRACE2} > results/matmul_opt2.result