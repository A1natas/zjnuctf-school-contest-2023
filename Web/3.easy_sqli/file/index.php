<?php
require_once("conn.php");
if(isset($_POST["id"])){
    $id = $_POST['id'];
    if(preg_match('/ |flag/i',$id)){
		die("nonono");
	}
    @$sql="SELECT name,img FROM users WHERE id='$id' LIMIT 0,1";
    $result=mysqli_query($conn,$sql);
	$row = mysqli_fetch_array($result);
}
;?>
<html>
<body>
    <div style="text-align:center;">
        <form action="/index.php" method="POST">
            <h1>选择你的英雄:</h1>
            <input type="text" name="id">
            <input type="submit" value="提交">
        </form>
        <?php
        if($row){
            echo "<h2>".$row['name']."</h2>";
            echo '<img src="'. $row['img'] .'" alt="Image" height="400" width="400">';
        }
        ;?>
    </div>
</body>
</html>