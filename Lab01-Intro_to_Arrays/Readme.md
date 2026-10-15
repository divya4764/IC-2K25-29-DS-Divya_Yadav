# Unit 1: Introduction to Data Structures and Arrays

## Program 1: One-Dimensional Array Operations

### Algorithm

1. Start the program.
2. Read the number of elements and the array elements.
3. Display a menu containing the available operations: display, insertion, deletion, searching, and left rotation.
4. Read the user's choice.
5. Perform the selected operation:

   * **Display:** Print all array elements.
   * **Insertion:** Read the position and value, shift elements to the right, and insert the value.
   * **Deletion:** Read the position, shift subsequent elements to the left, and decrease the array size.
   * **Searching:** Compare the target value with each element until a match is found or the array ends.
   * **Left Rotation:** Move the first element to the last position and shift the remaining elements one position to the left.
6. Display the result.
7. Repeat the menu until the user selects Exit.
8. Stop the program.

### Pseudocode

```text
START

READ n
READ array elements

REPEAT
    DISPLAY menu
    READ choice

    SWITCH choice

        CASE 1:
            DISPLAY all array elements

        CASE 2:
            READ position and value
            IF array has space AND position is valid
                SHIFT elements right
                INSERT value at position
                INCREMENT n
            ELSE
                DISPLAY error message
            END IF

        CASE 3:
            READ position
            IF position is valid
                SHIFT subsequent elements left
                DECREMENT n
            ELSE
                DISPLAY error message
            END IF

        CASE 4:
            READ search value
            SEARCH array using linear search
            DISPLAY result

        CASE 5:
            IF n > 1
                STORE first element
                SHIFT remaining elements left
                PLACE stored element at the end
            END IF

        CASE 6:
            EXIT

        DEFAULT:
            DISPLAY "Invalid choice"

    END SWITCH

UNTIL choice = 6

STOP
```

---

## Program 2: Two-Dimensional Array Operations

### Algorithm

1. Start the program.
2. Read the number of rows and columns.
3. Validate the matrix dimensions.
4. Read the matrix elements.
5. Display the original matrix.
6. Read the element to be searched.
7. Traverse the matrix and compare each element with the target value.
8. Display the position of each matching element or report that the element was not found.
9. Rotate the matrix 90 degrees clockwise by placing each element at its new position.
10. Display the rotated matrix.
11. Stop the program.

### Pseudocode

```text
START

READ rows, columns

IF dimensions are invalid
    DISPLAY error message
    STOP
END IF

READ matrix elements
DISPLAY original matrix

READ search value
found = FALSE

FOR i = 0 TO rows - 1
    FOR j = 0 TO columns - 1
        IF matrix[i][j] = search value
            DISPLAY row i and column j
            found = TRUE
        END IF
    END FOR
END FOR

IF found = FALSE
    DISPLAY "Element not found"
END IF

CREATE rotated matrix

FOR i = 0 TO rows - 1
    FOR j = 0 TO columns - 1
        rotated[j][rows - 1 - i] = matrix[i][j]
    END FOR
END FOR

DISPLAY rotated matrix
STOP
```

---

## Program 3: Insertion and Deletion of Rows in a Matrix

### Algorithm

1. Start the program.
2. Read the number of rows and columns.
3. Read and display the matrix.
4. Read the position at which a new row must be inserted.
5. Read the elements of the new row.
6. Validate the position and check whether sufficient capacity is available.
7. Shift the existing rows downward and insert the new row.
8. Display the updated matrix.
9. Read the position of the row to be deleted.
10. Validate the position.
11. Shift subsequent rows upward and decrease the row count.
12. Display the updated matrix.
13. Stop the program.

### Pseudocode

```text
START

READ rows, columns
READ matrix elements

READ insertion position
READ new row elements

IF matrix has capacity AND position is valid
    FOR i = rows DOWN TO position
        SHIFT row i - 1 TO row i
    END FOR

    INSERT new row at position - 1
    INCREMENT rows
    DISPLAY updated matrix
ELSE
    DISPLAY insertion error
END IF

READ deletion position

IF deletion position is valid
    FOR i = deletion position - 1 TO rows - 2
        COPY row i + 1 TO row i
    END FOR

    DECREMENT rows
    DISPLAY updated matrix
ELSE
    DISPLAY deletion error
END IF

STOP
```

**Note:** Positions are entered starting from 1, whereas array indices start from 0.

---

## Program 4: Sparse Matrix Representation Using Triple Format

### Algorithm

1. Start the program.
2. Read the number of rows and columns.
3. Validate the matrix dimensions.
4. Read all matrix elements.
5. Count the non-zero elements.
6. Store the number of rows, columns, and non-zero elements in the first row of the triple representation.
7. Traverse the original matrix.
8. For every non-zero element, store its row index, column index, and value in the triple representation.
9. Display the triple representation.
10. Stop the program.

### Pseudocode

```text
START

READ rows, columns
READ matrix elements

nonZero = 0

FOR i = 0 TO rows - 1
    FOR j = 0 TO columns - 1
        IF matrix[i][j] != 0
            nonZero = nonZero + 1
        END IF
    END FOR
END FOR

triplet[0][0] = rows
triplet[0][1] = columns
triplet[0][2] = nonZero

k = 1

FOR i = 0 TO rows - 1
    FOR j = 0 TO columns - 1
        IF matrix[i][j] != 0
            triplet[k][0] = i
            triplet[k][1] = j
            triplet[k][2] = matrix[i][j]
            k = k + 1
        END IF
    END FOR
END FOR

DISPLAY triplet
STOP
```

---

## Program 5: Addition of Two Sparse Matrices

### Algorithm

1. Start the program.
2. Read the dimensions of the matrices.
3. Read the elements of the first and second matrices.
4. Add the corresponding elements of both matrices.
5. Store the results in a sum matrix.
6. Count the non-zero elements in the sum matrix.
7. Display the sum matrix.
8. Construct the triple representation of the sum matrix.
9. Display the triple representation.
10. Stop the program.

### Pseudocode

```text
START

READ rows, columns
READ matrix A
READ matrix B

FOR i = 0 TO rows - 1
    FOR j = 0 TO columns - 1
        SUM[i][j] = A[i][j] + B[i][j]
    END FOR
END FOR

nonZero = 0

FOR i = 0 TO rows - 1
    FOR j = 0 TO columns - 1
        IF SUM[i][j] != 0
            nonZero = nonZero + 1
        END IF
    END FOR
END FOR

DISPLAY SUM matrix

DISPLAY header: rows, columns, nonZero

FOR i = 0 TO rows - 1
    FOR j = 0 TO columns - 1
        IF SUM[i][j] != 0
            DISPLAY i, j, SUM[i][j]
        END IF
    END FOR
END FOR

STOP
```

---

## Program 6: Menu-Driven Matrix Calculator

### Algorithm

1. Start the program.
2. Display a menu containing matrix addition, multiplication, transpose, determinant, and Exit.
3. Read the user's choice.
4. If addition is selected, read two matrices of equal dimensions and add their corresponding elements.
5. If multiplication is selected, read two matrices and verify that the number of columns in the first matrix equals the number of rows in the second matrix. Multiply the matrices if the condition is satisfied.
6. If transpose is selected, read a matrix and interchange its rows and columns.
7. If determinant is selected, read a square matrix of order 1, 2, or 3 and calculate its determinant.
8. Display the result of the selected operation.
9. Repeat the menu until Exit is selected.
10. Stop the program.

### Pseudocode

```text
START

REPEAT
    DISPLAY menu:
        1. Addition
        2. Multiplication
        3. Transpose
        4. Determinant
        5. Exit

    READ choice

    SWITCH choice

        CASE 1:
            READ rows and columns
            READ matrix A and matrix B

            FOR each element (i, j)
                RESULT[i][j] = A[i][j] + B[i][j]
            END FOR

            DISPLAY RESULT

        CASE 2:
            READ dimensions of A and B

            IF columns of A != rows of B
                DISPLAY "Multiplication not possible"
            ELSE
                READ matrices A and B

                FOR i = 0 TO rows of A - 1
                    FOR j = 0 TO columns of B - 1
                        RESULT[i][j] = 0

                        FOR k = 0 TO columns of A - 1
                            RESULT[i][j] =
                                RESULT[i][j] + A[i][k] * B[k][j]
                        END FOR
                    END FOR
                END FOR

                DISPLAY RESULT
            END IF

        CASE 3:
            READ matrix A

            FOR each element (i, j)
                RESULT[j][i] = A[i][j]
            END FOR

            DISPLAY RESULT

        CASE 4:
            READ order n

            IF n < 1 OR n > 3
                DISPLAY "Unsupported matrix order"
            ELSE
                READ square matrix A
                CALCULATE determinant of A
                DISPLAY determinant
            END IF

        CASE 5:
            EXIT

        DEFAULT:
            DISPLAY "Invalid choice"

    END SWITCH

UNTIL choice = 5

STOP
```

---

## Conclusion

In Unit 1, the programs demonstrate the fundamental operations performed on one-dimensional and two-dimensional arrays. Sparse matrix representation illustrates how memory can be optimized by storing only non-zero elements. The matrix calculator applies array concepts to common mathematical operations.

These programs develop an understanding of array manipulation, matrix processing, algorithm design, and basic space and time complexity analysis.
