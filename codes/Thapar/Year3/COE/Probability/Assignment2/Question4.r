# Q4.
data(iris)

#  4. (a)
head(iris)

#  4. (b)
str(iris)

#  4. (c)
range(iris$Sepal.Length)

#  4. (d)
mean(iris$Sepal.Length)

#  4. (e)
median(iris$Sepal.Length)

#  4. (f)
quartiles = quantile(iris$Sepal.Length, probs = c(0.25, 0.75))
IQR <- quantiles[2] - quantiles[1]

#  4. (g)
sd(iris$Sepal.Length)
var(iris$Sepal.Length)

#  4. (h)
mean(iris$Sepal.Width)
mean(iris$Petal.Length)
mean(iris$Petal.Width)

#  4. (i)
summary(iris)
