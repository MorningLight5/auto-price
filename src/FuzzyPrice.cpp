//
// File: FuzzyPrice.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 09-Apr-2024 15:11:39
//

// Include Files
#include "FuzzyPrice.h"
#include "evalfis.h"
#include <cmath>

// Function Definitions
//
// 初始化参数
//
// Arguments    : double priceRate
//                double price
//                double isCompetitorPrice
//                double achiRate
//                double SV
//                double TSV
//                double COR
//                double DISadd
// Return Type  : double
//
double FuzzyPrice(double priceRate, double price, double isCompetitorPrice,
                  double achiRate, double SV, double TSV, double COR,
                  double DISadd)
{
  double AR;
  double MPR;
  double PR;
  double priceLast;
  double priceNewDelta;
  double priceNewRate;
  int isCompetitor;
  // codegen
  // priceRate
  priceNewRate = 0.0;
  priceNewDelta = 0.0;
  isCompetitor = 0;
  AR = achiRate * 100.0;
  if ((SV < 5.0) && (TSV < 5.0)) {
    AR = 70.0;
  }
  if (priceRate < 0.0) {
    priceRate = 0.0;
  } else if (priceRate > 1000.0) {
    priceRate = 1000.0;
  }
  PR = priceRate * 100.0;
  if (isCompetitorPrice > 0.0) {
    isCompetitor = 1;
  }
  if ((price > 100.0) && (price <= 5000.0)) {
    if (PR > 499.0) {
      PR = 499.0;
    }
    if (PR < 30.0) {
      PR = 30.0;
    }
    MPR = coder::evalfis(PR);
  } else if ((price > 5000.0) && (price <= 10000.0)) {
    if (PR > 299.0) {
      PR = 299.0;
    }
    if (PR < 30.0) {
      PR = 30.0;
    }
    MPR = coder::b_evalfis(PR);
  } else if ((price > 10000.0) && (price <= 15000.0)) {
    if (PR > 229.0) {
      PR = 229.0;
    }
    if (PR < 30.0) {
      PR = 30.0;
    }
    MPR = coder::c_evalfis(PR);
  } else if ((price > 15000.0) && (price <= 30000.0)) {
    if (PR > 199.0) {
      PR = 199.0;
    }
    if (PR < 30.0) {
      PR = 30.0;
    }
    MPR = coder::d_evalfis(PR);
  } else if ((price > 30000.0) && (price <= 60000.0)) {
    if (PR > 199.0) {
      PR = 199.0;
    }
    if (PR < 30.0) {
      PR = 30.0;
    }
    MPR = coder::e_evalfis(PR);
  } else if ((price > 60000.0) && (price <= 150000.0)) {
    if (PR > 139.0) {
      PR = 139.0;
    }
    if (PR < 30.0) {
      PR = 30.0;
    }
    MPR = coder::f_evalfis(PR);
  } else if (price > 150000.0) {
    if (PR > 139.0) {
      PR = 139.0;
    }
    if (PR < 30.0) {
      PR = 30.0;
    }
    MPR = coder::f_evalfis(PR);
  } else {
    MPR = 0.0;
  }
  if ((MPR < 0.75) && (AR > 80.0) && (COR >= -0.1) && (DISadd < 90.0)) {
    // 环比下降10%以上不涨价
    priceNewRate = 0.03;
    // 利润回归策略1：利润偏低，销量比较好涨价3%
    if (price < 15000.0) {
      // 小货值多涨
      priceNewDelta = 800.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR < 0.7) && (AR > 80.0) && (DISadd < 40.0)) {
    priceNewRate = 0.05;
    // 利润回归策略2：利润偏低，销量比较好但是库存很少，涨价5%
    if (price < 15000.0) {
      // 小货值多涨
      priceNewDelta = 1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR < 0.7) && (AR > 70.0) && (DISadd < 120.0)) {
    priceNewRate = 0.03;
    // 利润回归策略3：利润低，销量勉强，涨价3%
    if (price < 15000.0) {
      // 小货值多涨
      priceNewDelta = 1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR < 0.7) && (AR > 70.0) && (DISadd < 40.0)) {
    priceNewRate = 0.08;
    // 利润回归策略4：利润差，库存少，销量还行，涨价8%
    if (price < 15000.0) {
      // 小货值多涨
      priceNewDelta = 1800.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR < 0.7) && (AR > 120.0) && (COR >= -0.2) && (DISadd < 90.0)) {
    priceNewRate = 0.05;
    // 利润回归策略5：利润稍低，销量好，涨价5%，去库存小于90天，环比下降小于20%
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = 1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR < 0.7) && (AR > 120.0) && (DISadd < 40.0)) {
    priceNewRate = 0.1;
    // 利润回归策略6：利润稍低，销量好，涨价10%  ，库存小于40天
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = 2000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR < 0.65) && (AR > 150.0) && (COR >= -0.1) && (DISadd < 90.0)) {
    priceNewRate = 0.1;
    // 利润回归策略7：利润低，销量很好，涨价1%，，库存小90天
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = 1500.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR < 0.65) && (AR > 50.0) && (COR >= -0.1) && (DISadd < 80.0)) {
    priceNewRate = 0.05;
    // 利润回归策略7：利润低，销量很好，涨价1%，，库存小90天
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = 1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 0.8) && (AR < 50.0)) {
    priceNewRate = -0.03;
    // 降价促销策略8：利润还行，销量不太好，降价6%
    if (price < 12000.0) {
      // 小货值多降
      priceNewDelta = -1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 0.8) && (AR < 20.0)) {
    priceNewRate = -0.05;
    // 降价促销策略8：利润还行，销量不太好，降价6%
    if (price < 12000.0) {
      // 小货值多降
      priceNewDelta = -1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 0.95) && (AR < 70.0)) {
    priceNewRate = -0.06;
    // 降价促销策略8：利润还行，销量不太好，降价6%
    if (price < 12000.0) {
      // 小货值多降
      priceNewDelta = -1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 0.95) && (AR < 70.0) && (DISadd < 40.0)) {
    priceNewRate = 0.0;
    // 降价促销策略9：利润还行，销量不太好，库存少保持
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.15) && (AR < 60.0)) {
    priceNewRate = -0.08;
    // 降价促销策略10：利润比较好，销量不好，降价8%
    if (price < 12000.0) {
      // 小货值多
      priceNewDelta = -1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.15) && (AR < 60.0) && (DISadd < 40.0)) {
    priceNewRate = 0.0;
    // 降价促销策略11：利润比较好，销量不好， 库存少保持
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.2) && (AR < 50.0)) {
    priceNewRate = -0.1;
    // 降价促销策略12：利润好，销量不好，降价10%
    if (price < 12000.0) {
      // 小货值多
      priceNewDelta = -1200.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.2) && (AR < 50.0) && (DISadd < 40.0)) {
    priceNewRate = 0.0;
    // 降价促销策略13：利润好，销量不好，降价15%
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.3) && (AR > 100.0)) {
    priceNewRate = -0.05;
    // 利润率高14，销量也高尝试降价策略
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = -1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.2) && (AR > 100.0) && (DISadd < 40.0)) {
    priceNewRate = 0.03;
    // 利润率高15，销量也高尝试降价策略
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = 1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.3) && (AR > 90.0)) {
    priceNewRate = -0.05;
    // 利润率太高16，销量也高，尝试降价策略
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = -1000.0;
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  if ((MPR > 1.3) && (AR > 90.0) && (DISadd < 40.0)) {
    priceNewRate = 0.05;
    // 利润率太高，销量还行，尝试降价策略
    if (price < 15000.0) {
      // 小货值多
      priceNewDelta = 1000.0;
    }
  }
  if ((DISadd < 30.0) && (priceNewRate < 0.0)) {
    priceNewRate = 0.0;
    priceNewDelta = 0.0;
  } else if ((DISadd < 30.0) && (priceNewRate <= 0.05)) {
    priceNewRate = 0.05;
  } else if (DISadd < 30.0) {
    priceNewRate = 0.1;
  }
  if (isCompetitor == 1) {
    // 存在竞对
    MPR = (isCompetitorPrice - price) / price;
    // 和竞对的差值
    if ((MPR < 0.2) && (MPR > 0.0) && (DISadd > 60.0) && (priceNewRate > 0.0)) {
      // 比竞对低
      priceNewRate = 0.0;
      // 有竟对不涨价
    }
    if ((MPR >= 0.2) && (MPR < 1.0) && (DISadd > 60.0) && (AR < 40.0)) {
      priceNewRate = -0.05;
      // 比竟对低太对涨5%
    }
    if ((MPR < 0.0) && (DISadd > 60.0) && (AR > 100.0)) {
      // 比竞对高
      priceNewRate = -0.05;
    }
    if ((MPR < 0.0) && (DISadd > 60.0) && (AR < 70.0)) {
      // 比竞对高
      priceNewRate = -0.08;
    }
    if ((MPR < 0.0) && (DISadd > 60.0) && (AR < 10.0)) {
      // 比竞对高
      priceNewDelta = -(price - isCompetitorPrice) * 1.1;
    }
  }
  if (priceNewDelta == 0.0) {
    priceNewRate = (priceNewRate + 1.0) * price;
  } else {
    priceNewRate = priceNewDelta + price;
  }
  priceLast = std::floor(priceNewRate / 100.0) * 100.0 + 90.0;
  // 转换为90结尾
  MPR = price / (PR / 100.0 + 1.0);
  if ((priceLast - price) + MPR < 0.0) {
    priceLast = std::floor(MPR * 1.4 / 100.0) * 100.0 + 90.0;
  }
  MPR = priceLast - price;
  if (MPR > 10000.0) {
    priceLast = price + 10000.0;
  } else if (MPR < -10000.0) {
    priceLast = price - 10000.0;
  }
  return priceLast;
}

//
// File trailer for FuzzyPrice.cpp
//
// [EOF]
//
