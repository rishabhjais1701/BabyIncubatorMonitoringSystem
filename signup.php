<!DOCTYPE html>
<html>
<head>
    <title>Sign Up - Baby Incubation</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <header>
        <h1>Welcome to Baby Incubation</h1>
        <nav>
            <ul>
                <li><a href="#">Home</a></li>
                <li><a href="#">About</a></li>
                <li><a href="#">Contact</a></li>
                <li><a href="login.php">Log In</a></li>
                <li><a href="signup.php">Sign Up</a></li>
            </ul>
        </nav>
    </header>

    <section class="signup-section">
        <div class="signup-container">
            <h2>Sign Up</h2>
            <?php
            if (isset($_POST['signup'])) {
                // Perform signup process
                $username = $_POST['username'];
                $password = $_POST['password'];

                // Add your signup logic here
                // ...

                // Redirect to login page after successful signup
                header('Location: login.php');
                exit;
            }
            ?>
            <form method="POST" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
                <input type="text" name="username" placeholder="Username" required>
                <input type="password" name="password" placeholder="Password" required>
                <button type="submit" name="signup">Sign Up</button>
            </form>
        </div>
    </section>

    <footer>
        <p>&copy; 2023 Baby Incubation. All rights reserved.</p>
    </footer>
</body>
</html>
