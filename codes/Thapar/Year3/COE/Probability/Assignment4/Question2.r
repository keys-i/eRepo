f = function(t) {
  return(0.1 * exp(-0.1 * t))
}

expected_value_t = integrate(function(t) t * f(t), lower = 0, upper = Inf)$value

cat("Expected value of T is: ", expected_value_t)
