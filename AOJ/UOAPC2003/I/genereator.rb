# random case

def randbet(a,b)
  return rand(b-a)+a
end

def randomcasebig()
  n = randbet(1,50)
  r = randbet(1,50)
  puts("#{n} #{r}")
  (r-1).times {
    print randbet(1,50), ' '
  }
  print randbet(1,50)
  puts('')
end

def randomcasesmall()
  n = randbet(1,50)
  r = randbet(1,50)
  puts("#{n} #{r}")
  (r-1).times {
    print randbet(1,10), ' '
  }
  print randbet(1,10)
  puts('')
end

# tricky cases

def allone()
  n = 50
  r = 50
  puts("#{n} #{r}")
  (r-1).times {
    print 1, ' '
  }
  print 1
  puts('')
end

def allhundred()
  n = 50
  r = 50
  puts("#{n} #{r}")
  (r-1).times {
    print 100, ' '
  }
  print 100
  puts('')
end

def sample1()
  print "9 1\n3\n"  
end

def sample2()
  print "9 4\n1 2 3 4\n"
end

sample1()
sample2()
allone()
allhundred()

47.times do
  randomcasebig()
  randomcasesmall()
end
