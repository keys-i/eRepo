fib_sequence = function(n) {
  if (n <= 0) {
    return("Error: Please enter a positive integer.")
  } else {
    fib = numeric(n)
    fib[1] = 0
    if (n > 1) fib[2] = 1
    for (i in 3:n) {}
      fib[i] = fib[i - 1] + fib[i - 2]
    }
    return (fib)
  }
}

n = as.integer(readline(prompt="Enter the number of Fibonacci terms: "))

fib_seq = fib_sequence(n)
cat("Fibonacci Sequence till", n, "is:", fib_seq, "\n")
