# Assignment 2

## Q1.
(a) Suppose there is a chest of coins with 20 gold, 30 silver and 50 bronze coins.
You randomly draw 10 coins from this chest. Write an R code which will give us the
sample space for this experiment. (use of sample(): an in-built function in R)
(b) In a surgical procedure, the chances of success and failure are 90% and 10% respectively.
Generate a sample space for the next 10 surgical procedures performed.
(use of prob(): an in-built function in R)
### 1. (a)
  ```R
  chest = c(rep("gold", 20), rep("silver", 30), rep("bronze", 50))

  # Randomly draw 10 coins
  draw = sample(chest, size=10, replace=FALSE)

  cat("Sample Size: ", draw)
  ```

### 1. (b)
  ```R
  outcomes = c("'Success", "'Failure")
  probabilities = c(0.9, 0.1)

  surgery_out = sample(outcomes, size=10, replace=TRUE, prob=probabilities)

  cat("Sample Space for next 10 surgical procedures: ", surgery_out)
  ```

## Q2. A room has n people, and each has an equal chance of being born on any of the 365 days of the year. (For simplicity, we’ll ignore leap years). What is the probability that two people in the room have the same birthday?
(a) Use an R simulation to estimate this for various n.
(b) Find the smallest value of n for which the probability of a match is greater than 5.
### 2. (a)
  ```R
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
  }
  ```

### 2. (b)
  ```R
  small_n = function() {
    n = 1
    while (birth_sim(n) < 0.5) {
      n = n + 1
    }
    return(n)
  }

  small_n()
  ```

## Q3. Write an R function for computing conditional probability. Call this function to do the following problem:
suppose the probability of the weather being cloudy is 40%.
Also suppose the probability of rain on a given day is 20% and that the probability of clouds on a rainy day is 85%.
If it’s cloudy outside on a given day, what is the probability that it will rain that day?
  ```R
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
  ```

## Q4. The iris dataset is a built-in dataset in R that contains measurements on 4 different attributes (in centimeters) for 150 flowers from 3 different species. Load this dataset and do the following:
(a) Print first few rows of this dataset.
(b) Find the structure of this dataset.
(c) Find the range of the data regarding the sepal length of flowers.
(d) Find the mean of the sepal length.
(e) Find the median of the sepal length.
(f) Find the first and the third quartiles and hence the interquartile range.
(g) Find the standard deviation and variance.
(h) Try doing the above exercises for sepal.width, petal.length and petal.width.
(i) Use the built-in function summary on the dataset Iris.
  ```R
  data(iris)

  # a.
  head(iris)

  # b.
  str(iris)

  # c.
  range(iris$Sepal.Length)

  # d.
  mean(iris$Sepal.Length)

  # e.
  median(iris$Sepal.Length)

  # f.
  quartiles = quantile(iris$Sepal.Length, probs = c(0.25, 0.75))
  IQR <- quantiles[2] - quantiles[1]

  # g.
  sd(iris$Sepal.Length)
  var(iris$Sepal.Length)

  # h.
  mean(iris$Sepal.Width)
  mean(iris$Petal.Length)
  mean(iris$Petal.Width)

  # i.
  summary(iris)
  ```

## Q5. R does not have a standard in-built function to calculate mode. So we create a user function to calculate mode of a data set in R. This function takes the vector as input and gives the mode value as output.
  ```R
  gmode = function(v) {
    uniqv = unique(v)
    uniqv[which.max(tabulate(match(v, uniqv)))]
  }

  v = c(2, 3, 3, 5, 5, 5, 7)
  gmode(v)
  ```
