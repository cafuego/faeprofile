<?php
/**
 * @file
 *
 * Available template variables are:
 *
 * $qualifications - An array of all qualifications.
 */
?>

<?php if ($qualifications): ?>
  <h3>Qualifications</h3>
  <ul>
  <?php foreach ($qualifications as $qualification): ?>
    <li><?php print $qualification; ?></li>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>
