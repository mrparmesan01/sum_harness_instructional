#OpenMP settings:
export OMP_NUM_THREADS=1
export OMP_PLACES=threads
export OMP_PROC_BIND=spread

#run the application:
srun -n 1 -c 256 --cpu_bind=cores build/sum_direct sum_direct 1
srun -n 1 -c 256 --cpu_bind=cores build/sum_vector sum_vector 1
srun -n 1 -c 256 --cpu_bind=cores build/sum_indirect sum_indirect 1
srun -n 1 -c 256 --cpu_bind=cores build/sum_indirect sum_indirect 2
srun -n 1 -c 256 --cpu_bind=cores build/sum_indirect sum_indirect 3
srun -n 1 -c 256 --cpu_bind=cores build/sum_indirect_seed sum_indirect_seed 1
srun -n 1 -c 256 --cpu_bind=cores build/sum_indirect_seed sum_indirect_seed 2
srun -n 1 -c 256 --cpu_bind=cores build/sum_indirect_seed sum_indirect_seed 3