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
cat("Factorial of ", n, " is: ", res, "\n")
