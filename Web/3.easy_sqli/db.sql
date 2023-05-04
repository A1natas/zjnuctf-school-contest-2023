use ctf;
CREATE TABLE users
        (
        id int(3) NOT NULL AUTO_INCREMENT,
        name varchar(20) NOT NULL,
        img varchar(20) NOT NULL,
        PRIMARY KEY (id)
        );
CREATE TABLE flagggg_1s_h3re
        (
        id int(3)NOT NULL AUTO_INCREMENT,
        flag varchar(100) NOT NULL,
        PRIMARY KEY (id)
        );
 
INSERT INTO ctf.users (id, name, img) VALUES 
    ('1', '伊蕾娜', './static/img1.jpg'), 
    ('2', '御坂美琴', './static/img2.jpg'), 
    ('3', '四宫辉夜', './static/img3.jpg'), 
    ('4', '椎名真白', './static/img4.jpg'), 
    ('5', '樱岛麻衣', './static/img5.jpg'), 
    ('6', '亚丝娜', './static/img6.jpg'), 
    ('7', '小鸟游六花', './static/img7.jpg'), 
    ('8', '爱蜜莉雅', './static/img8.jpg'),
    ('9', '藤原千花', './static/img9.jpg'),
    ('10', '时崎狂三', './static/img10.jpg');
 
INSERT INTO ctf.flagggg_1s_h3re (id, flag) VALUES 
    ('1', load_file('../../../../flag'));