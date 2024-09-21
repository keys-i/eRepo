# Q2.
#  2. (a)
birth_sim = function(n, trials = 10000) {
  count = 0
  for (i in 1:trials) {
    birth = sample(1:365, size=n, replace=TRUE)
    if (length(unique(birth)) < n) {
      count = count + 1
    }
  }
  return (count / trials)
}

for (n in 1:50) {
  cat("For n =", n, "probability of matching birthdays is:", birth_sim(n), "\n")

#  2. (b)
small_n = function() {
  n = 1
  while (birth_sim(n) < 0.5) {
    n = n + 1
  }
  return(n)
}

small_n()
