# Actions
## Build
- initialize matrix
- get neighbors
- calculate value for current cell (based on neighbors)

## Retrace
- get neighbors
- calculate operation (insert, keep, etc.) based on neighbors

# Data structures
- multidimensional array with integer values for matrix

# Other
- deallocate memory

# Goal
- compute min number of edits (increment count for all non-keep values)
- compute editing operations needed with calculate operation action, then append to string with each operation