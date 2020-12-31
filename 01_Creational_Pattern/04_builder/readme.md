## 感觉有几种设计

1. 两种房屋不同的构建方案

https://blog.csdn.net/sinat_21107433/article/details/102635881

2. 两种建造的过程也不相同

https://refactoringguru.cn/design-patterns/builder/cpp/example#example-0

3. 有关联产品的

https://refactoringguru.cn/design-patterns/builder

https://refactoringguru.cn/design-patterns/builder/java/example#example-0--cars-Manual-java

都是在builder里set好，然后return出来

一种是同一个产品的不同设计

一种是不是同一个产品，但是相关联，比如汽车和汽车说明书

## 在 director设计组装函数

一种是不同的接口产生不同的物品

一种是相同的接口，因为builder不同而结果不同

