# Qiime2Filter
# Language: C++
# Input: TXT
# Output: QZA
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: qiime2_2021.4

Filter Qiime2 (Bolyen et al, 2019) reads based on a feature.

The plugin takes as input a file of tab-delimited keyword-value pairs:

inputfile: Input data (QZA)
metadata: Sample data (QZA)
op1: First option for Qiime2 filter
op2: Second option for Qiime2 filter

Filtered output will be produced in the user-specified output QZA file.
