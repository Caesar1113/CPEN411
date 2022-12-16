1. To compile Champsim use the following command
    $ bash compile_champsim.sh
2. To run a single trace use the following command
    $ bash run_single.sh <0-3>
        0: Run the base matrix multiplication code (matmul_basic.c)
        1: Run the opt1 matrix multiplication code (matmul_opt1.c)
        2: Run the opt2 matrix multiplication code (matmul_opt2.c)
        3: Run the opt3 matrix multiplication code (matmul_opt3.c) 
3. To run all traces use the following command
    $ bash run_all.sh
4. To create the the gzip file for the submission use the following command
    $ bash create_submission.sh