cond_prob = function(p_a_and_b, p_b) {
  return(p_a_and_b / p_b)
}

p_cloud = 0.4
p_rain = 0.2
p_cloud_and_rain = 0.85

p_cloudy_given_rain <- 0.85

# Calculate P(rain and cloudy)
p_rain_and_cloudy <- p_rain * p_cloudy_given_rain

# Calculate conditional probability
p_rain_given_cloudy <- conditional_prob(p_rain_and_cloudy, p_cloudy)

# Output the result
cat("Probability of Rain Given Cloudy is: ",p_rain_given_cloudy)
