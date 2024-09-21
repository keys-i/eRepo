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
