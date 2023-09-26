<!DOCTYPE html>
<html>
<head>
    <title>Login - Baby Incubation</title>
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

    <section class="login-section">
        <div class="login-container">
            <h2>Login</h2>
            <?php
            if (isset($_POST['login'])) {
                // Perform authentication and redirect if successful
                $username = $_POST['username'];
                $password = $_POST['password'];

                // Add your authentication logic here
                if ($username === 'admin' && $password === 'password') {
                    session_start();
                    $_SESSION['username'] = $username;
                    header('Location: dashboard.php');
                    exit;
                } else {
                    echo '<p class="error-message">Invalid username or password.</p>';
                }
            }
            ?>
            <form method="POST" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
                <input type="text" name="username" placeholder="Username" required>
                <input type="password" name="password" placeholder="Password" required>
                <button type="submit" name="login">Log In</button>
            </form>
        </div>
    </section>

    <footer>
        <p>&copy; 2023 Baby Incubation. All rights reserved.</p>
    </footer>
</body>
</html>
