<?php
/**
 * @file
 *
 * Available template variables are:
 *
 * $linkages - An array of all linkages.
 */
?>

<?php if ($linkages): ?>
  <h3>International linkage</h3>
  <ul>
  <?php foreach ($linkages as $linkage): ?>
    <li><?php print $linkage; ?></li>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>

