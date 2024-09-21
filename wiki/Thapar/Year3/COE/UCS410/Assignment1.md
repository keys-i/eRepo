# Assignment 1

## Q1. Create a vector c = [5, 10, 15, 20, 25, 30] and write a program which returns the maximum and minimum of this vector.
  ```R
  c = c(5, 10, 15, 20, 25, 30)

  max_c = max(c)
  min_c = min(c)

  cat("1.\n")
  cat("Maximum value of c is:", max_c, "\n")
  cat("Minimum value of c is:", min_c, "\n")
  ```

## Q2. Write a program in R to find factorial of a number by taking input from user. Please print error message if the input number is negative.
  ```R
  factorial_c = function(n) {
      if (n < 0) {
          return("Error: Factorial of a negative number is undefined.")
      } else if (n == 0) {
          return(1)
      } else {
          return(n * factorial_c(n - 1))
      }
  }

  n = as.integer(readline(prompt="Enter a number: "))

  res = factorial_c(n)
  cat("Factorial of", n, "is:", res, "\n")
  ```

## Q3. Write a program to write first n terms of a Fibonacci sequence. You may take n as an input from the user.
  ```R
  fib_sequence = function(n) {
    if (n <= 0) {
      return("Error: Please enter a positive integer.")
    } else {
      fib = numeric(n)
      fib[1] = 0
      if (n > 1) fib[2] = 1
      for (i in 3:n) {
        fib[i] = fib[i - 1] + fib[i - 2]
      }
      return (fib)
    }
  }

  n = as.integer(readline(prompt="Enter the number of Fibonacci terms: "))

  fib_seq = fib_sequence(n)
  cat("Fibonacci Sequence till", n, "is:", fib_seq, "\n")
  ```

## Q4. Write an R program to make a simple calculator which can add, subtract, multiply and divide.
  ```R
  calculator = function(x, y, operation) {
    switch(operation,
      "add" = c("+",x + y),
      "subtract" = c("-",x - y),
      "multiply" = c("*",x * y),
      "divide" = if (y != 0) c("/",x / y) else return("Error: Division by zero.")
      )
  }

  x = as.numeric(readline(prompt="Enter first number: "))
  y = as.numeric(readline(prompt="Enter second number: "))
  operation = readline(prompt="Enter operation (add, subtract, multiply, divide): ")

  res = calculator(x, y, operation)
  cat(x, res[1], y, "is:", res[2], "\n")
  ```

## Q5. Explore plot, pie, barplot etc. (the plotting options) which are built-in functions in R.
  ```R
  x = 1:10
  y = x^2
  plot(x, y, main="Basic Plot", xlab="x-axis", ylab="y-axis", col="blue", pch=19)

  # Box Plot
  data <- list(A = rnorm(100, mean = 5), B = rnorm(100, mean = 10), C = rnorm(100, mean = 15))
  boxplot(data, main = "Box Plot Example", xlab = "Categories", ylab = "Values")
  legend("topright", legend = c("A", "B", "C"), fill = c("white", "white", "white"))

  # Pie Chart
  slices = c(10, 20, 30, 40)
  labels = c("A", "B", "C", "D")
  pie(slices, labels=labels, main="Basic Pie Chart")

  # Bar Plot
  counts_matrix <- matrix(c(10, 15, 20, 25, 12, 18, 22, 28), nrow = 2, ncol = 4, byrow = TRUE)
  barplot(counts_matrix, beside = TRUE, main = "Bar Plot with Multiple Bars",
          xlab = "Categories", ylab = "Counts", col = c("green", "blue"),
          legend = c("Group 1", "Group 2"))

  # Histogram
  hist_data <- rnorm(100, mean = 50, sd = 10)
  hist(hist_data, main = "Histogram Example", xlab = "Value", col = "purple", border = "black", breaks = 10)

  # Scatter Plot
  x_sc = rnorm(100)
  y_sc = x_sc + rnorm(100, mean=0.5)
  plot(x_sc, y_sc, main="Scatter Plot", xlab="x-axis", ylab="y-axis", col="red", pch=19)
  legend("topright", legend = "Scatter Points", col = "red", pch = 19)
  ```
