<?php
/**
 * @file
 * marketplace_features.features.inc
 */

/**
 * Implements hook_node_info().
 */
function marketplace_features_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Product Display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
      'node_submitted' => '0',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
