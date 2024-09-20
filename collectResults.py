from subprocess import call
from testing import *
from radixSort import *
from calculate_stat import *

for i in range(0, 100):
    # Generate data
    generate_scrambled_numbers('scramble.txt')
    # Execute the compiled C
    call(["./bucketsort"])
    # Execute the Java
    call(["java", "radixSort.java"])
    # Execute the python
    sortFile()

generateStats()
