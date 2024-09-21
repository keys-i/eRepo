x = c(0, 1, 2, 3)
p_x = c(0.1, 0.2, 0.2, 0.5)

# Net Revenue = (Revenue from sold books) - (Cost of purchased books) + (Refund from unsold books)
Y = function(x) {
  return((12 * x - 6 * 3) + (3 - x) * 2)
}

expected_value_y = sum(p_x * Y(x))

cat("Expected value of Y is: ", expected_value_y, "\n")
