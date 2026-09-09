#run the application:
srun -n 1 -c 256 --cpu_bind=cores build/sum_direct sum_direct 1
srun -n 1 -c 256 --cpu_bind=cores build/sum_indirect sum_indirect 1
srun -n 1 -c 256 --cpu_bind=cores build/sum_vector sum_vector 1