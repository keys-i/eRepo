calculator = function(x, y, operation) {
  switch(operation) {
    "add" = x + y
    "subtract" = x - y
    "multiply" = x * y
    "divide" = if (y != 0) x / y else return("Error: Division by zero.")
  }
}

x = as.numeric(readline(prompt="Enter first number: "))
y = as.numeric(readline(prompt="Enter second number: "))
operation = readline(prompt="Enter operation (add, subtract, multiply, divide): ")

res = calculator(x, y, operation)
cat(x, operator, y, "=", res, "\n")
