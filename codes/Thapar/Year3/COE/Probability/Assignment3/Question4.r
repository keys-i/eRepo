# Parameters for the hypergeometric distribution
m = 17   # number of defective processors
n = 250 - 17  # number of non-defective processors
k = 5    # sample size

# P(X = 3) for X ~ Hypergeometric(m = 17, n = 233, k = 5)
p_exactly_3_defectives = dhyper(3, m, n, k)

cat("Probability of exactly 3 defectives in the sample is: ", p_exactly_3_defectives, "\n")
