gmode = function(v) {
  uniqv = unique(v)
  uniqv[which.max(tabulate(match(v, uniqv)))]
}

v = c(2, 3, 3, 5, 5, 5, 7)
gmode(v)