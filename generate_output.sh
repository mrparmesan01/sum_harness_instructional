if [ ! -d "output" ]; then
    echo "Creating output directory"
    mkdir output
else
    echo "Output directory already exists"
fi

echo "Generating sum_direct output..."
./build/sum_direct > output/sum_direct_output.txt

echo "Generating sum_indirect output..."
./build/sum_indirect > output/sum_indirect_output.txt

echo "Generating sum_vector output..."
./build/sum_vector > output/sum_vector_output.txt