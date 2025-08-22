# check 相关
## ticker check add
- API: /api/web/ticker/check/add
### 请求参数
```json
user_id: bigint, 必选参数
user_name: string, 可选参数
language: string, 可选参数, default=en
ticker_id: String
strategy: String
date: String, %Y-%m-%d 格式 如不输入则为当前时间
time: String, %H:%M 格式 如不输入则为当前时间
auto_trade: UInt, 默认0
distance: UInt, 默认0
chart_image_url: String, 默认空字符串
trade_direction: String, 默认buy, 可选[buy, sell]
```
### 返回结果
```json
{}
```
## ticker check list
- API: /api/web/ticker/check/list
### 请求参数
```json
user_id: bigint, 必选参数
user_name: string, 可选参数
language: string, 可选参数, default=en
```
### 返回结果
```json
{
  "ticker_ids": [
    {
      "auto_trade": 0,
      "chart_image_url": "",
      "datetime": "Sun, 01 Oct 2023 10:10:00 GMT",
      "distance": 0,
      "entry_datetime": null,
      "entry_price": null,
      "exit_datetime": null,
      "exit_price": null,
      "exit_status": null,
      "has_reached": 0,
      "id": 2,
      "limit_price": 0.0,
      "price": 0.0,
      "profit_rate": null,
      "stop_price": 0.0,
      "strategy": "",
      "ticker_id": "AMZN",
      "trade_direction": "buy",
      "trade_type": "check",
      "user_id": 123
    }
  ]
}
```
## ticker check edit
- API: /api/web/ticker/check/edit
### 请求参数
```json
user_id: bigint, 必选参数
user_name: string, 可选参数
language: string, 可选参数, default=en
edit_check_id: UInt, edit的唯一查询条件,会同时用user_id做校验
仅以下字段可以edit
price = {price},
stop_price = {stop_price},
limit_price = {limit_price},
auto_trade = {auto_trade},
chart_image_url = {chart_image_url}
datetime = {date} {time}
```
### 返回结果
```json
{}
```
edit 结束后再次调用list，确认edit结果
```json
{
  "ticker_ids": [
    {
      "auto_trade": 0,
      "chart_image_url": "",
      "datetime": "Sun, 01 Oct 2023 10:10:00 GMT",
      "distance": 0,
      "entry_datetime": null,
      "entry_price": null,
      "exit_datetime": null,
      "exit_price": null,
      "exit_status": null,
      "has_reached": 0,
      "id": 2,
      "limit_price": 0.0,
      "price": 0.0,
      "profit_rate": null,
      "stop_price": 0.0,
      "strategy": "",
      "ticker_id": "AMZN",
      "trade_direction": "buy",
      "trade_type": "check",
      "user_id": 123
    }
  ]
}
```
## ticker check delete
- API: /api/web/ticker/check/delete
### 请求参数
```json
user_id: bigint, 必选参数
user_name: string, 可选参数
language: string, 可选参数, default=en
edit_check_id: String
check_status: int
```
### 返回结果
```json
{}
```
delete 结束后再次调用list，确认edit结果
```json
{
  "ticker_ids": [
    {
      "auto_trade": 0,
      "chart_image_url": "",
      "datetime": "Sun, 01 Oct 2023 10:10:00 GMT",
      "distance": 0,
      "entry_datetime": null,
      "entry_price": null,
      "exit_datetime": null,
      "exit_price": null,
      "exit_status": null,
      "has_reached": 0,
      "id": 2,
      "limit_price": 0.0,
      "price": 0.0,
      "profit_rate": null,
      "stop_price": 0.0,
      "strategy": "",
      "ticker_id": "AMZN",
      "trade_direction": "buy",
      "trade_type": "check",
      "user_id": 123
    }
  ]
}
```
# trade 相关
## ticker trade list
- API: /api/web/ticker/trade/list
### 请求参数
```json
user_id: bigint, 必选参数
user_name: string, 可选参数
language: string, 可选参数, default=en
```
### 返回结果
```json
{
  "ticker_ids": []
}
```
## END
